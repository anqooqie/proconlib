#ifndef VARIANT_HPP
#define VARIANT_HPP

#include <cstddef>
#include <type_traits>
#include <utility>

// Source: https://qiita.com/ktokhrtk/items/9774208863f249007462
// Author: ktokhrtk ( https://qiita.com/ktokhrtk )
namespace tools {
  namespace detail {
    namespace variant {
      template <class...>
      struct variant_storage;

      template <class A, class... B>
      struct variant_storage<A, B...> : variant_storage<B...> {
        using base_t = variant_storage<B...>;
        static constexpr std::size_t size = sizeof(A) > base_t::size ? sizeof(A) : base_t::size;
        static constexpr std::size_t align = alignof(A) > base_t::align ? alignof(A) : base_t::align;
      };

      template <class Z>
      struct variant_storage<Z> {
        static constexpr std::size_t size = sizeof(Z);
        static constexpr std::size_t align = alignof(Z);
      };

      template <class... Types>
      using storage_t = typename std::aligned_storage<variant_storage<Types...>::size, variant_storage<Types...>::align>::type;

      template <class...>
      struct variant_typeid;

      template <class A, class... B>
      struct variant_typeid<A, B...> : variant_typeid<B...> {
        using base_t = variant_typeid<B...>;
        static constexpr std::size_t id = base_t::id + 1;

        template <class T, typename std::enable_if<std::is_same<A, typename std::decay<T>::type>::value, std::nullptr_t>::type = nullptr>
        static std::size_t assign(void* p, T&& t) {
          ::new(p) A(std::forward<T>(t));
          return id;
        }

        using base_t::assign;
      };

      template <class Z>
      struct variant_typeid<Z> {
        static constexpr std::size_t id = 1;

        template <class T, typename std::enable_if<std::is_same<Z, typename std::decay<T>::type>::value, std::nullptr_t>::type = nullptr>
        static std::size_t assign(void* p, T&& t) {
          ::new(p) Z(std::forward<T>(t));
          return id;
        }
      };

      template <class F, class T, class R>
      auto declfunc() -> R (*)(void*, F&&) {
        return [](void* p, F&& f) {
          return std::forward<F>(f)(*static_cast<T*>(p));
        };
      }

      template <class F, class T, class R>
      auto const_declfunc() -> R (*)(const void*, F&&) {
        return [](const void* p, F&& f) {
          return std::forward<F>(f)(*static_cast<const T*>(p));
        };
      }

      template <class...>
      struct contains;

      template <class T, class FirstType, class... Types>
      struct contains<T, FirstType, Types...> {
        static constexpr bool value = std::is_same<typename std::decay<T>::type, FirstType>::value || contains<T, Types...>::value;
      };

      template <class T>
      struct contains<T> {
        static constexpr bool value = false;
      };

      template <class FirstType, class... Types>
      struct first {
        using type = FirstType;
      };
    }
  }

  template <class... Types>
  struct variant {
  private:
    detail::variant::storage_t<Types...> m_storage;
    std::size_t m_id;

    struct deleter {
      template <class T>
      void operator()(T& p) {
        p.~T();
      }
    };

  public:
    ~variant() {
      this->visit<void>(deleter());
    }

    variant()
      : variant(detail::variant::first<Types...>::type()) {
    }

    template <
      class T,
      typename std::enable_if<detail::variant::contains<T, Types...>::value, std::nullptr_t>::type = nullptr
    >
    variant(T&& t)
      : m_id(detail::variant::variant_typeid<Types...>::assign(&this->m_storage, std::forward<T>(t))) {
    }

    template <class R, class F>
    R visit(F&& f) {
      static R (*ftbl[])(void*, F&&) = { detail::variant::declfunc<F, Types, R>()... };
      return ftbl[sizeof...(Types) - this->m_id](&this->m_storage, std::forward<F>(f));
    }

    template <class R, class F>
    R visit(F&& f) const {
      static R (*ftbl[])(const void*, F&&) = { detail::variant::const_declfunc<F, Types, R>()... };
      return ftbl[sizeof...(Types) - this->m_id](&this->m_storage, std::forward<F>(f));
    }
  };
}

#endif
