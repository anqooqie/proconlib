// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc272/tasks/abc272_f

#include <iostream>
#include <string>
#include "tools/assert_that.hpp"
#include "tools/chmin.hpp"
#include "tools/suffix_array.hpp"

using ll = long long;

ll solve(const int N, const std::string S, const std::string T) {
  tools::suffix_array SSTT{S + S, T + T};
  SSTT.erase_if([&](auto, const auto j) {
    return N <= j;
  });
  for (auto& lcpa_i : SSTT.lcpa) {
    tools::chmin(lcpa_i, N);
  }

  ll answer = 0;
  ll partial_answer = 0;
  for (int l = 0, r = 0; l < 2 * N; l = r) {
    for (++r; r < 2 * N && SSTT.lcpa[r - 1] == N; ++r);
    for (int i = l; i < r; ++i) {
      if (SSTT.sa[i].first == 0) ++partial_answer;
    }
    for (int i = l; i < r; ++i) {
      if (SSTT.sa[i].first == 1) answer += partial_answer;
    }
  }

  return answer;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(3, "adb", "cab") == 4LL);
  assert_that(solve(10, "wsiuhwijsl", "pwqoketvun") == 56LL);
  assert_that(solve(970, "mlrdpgdpzmrnmtwfxfcmuspgazhdvflgntgeunnpmqcdwcwjurixfrmqadfsvpalvtyqesobncnpmlxtztlnvwwbdlilikrywvteujblkivkohbfijkvjohdimjjddpjmviuidlyyeozbkyqieavrfwjdsjcfgfiluwfwrmxaucqapqiwmyyqjvlubqaopnhjteiibfhnemuangsshcsfmndugvwonnxjoxoldmmperxzstntfvyqbkfrksjgebkrfcwtqvccrenhvkronqryktwjwpavwhzbiwkcruskldunbpscgeofwlqilivyhnytjekbzrutxdxiiabbpgrchbnnseedylwlukrkreledpofqtvbuttcvnmgydvqmkmylpmlalnfrinwcwggvyiwylhokxvpcmjkkmcocioulzdwuiuebfugqqrbworwgapjjpejtubopujsdbnukhiyokhfudjuwglgteuskklpaoyclmxatnkjjupnaodvwgqkukstzcpiragziizwjwynbcwhrzverpegxjnuredpwciozqqivqfoxvtjogaorxkibawbaguyqeihoaxbmhrultzmyfwjrdasvbxnabcvoebngmcwhbxfjxpgzesadctcxgxdqfhwodzxjeypoarjkfiyekhgqesxmbsejavytasgqkymndrrdmjqrfyssxtjweupciryzokxzldyrcrxsfdjpxjahrtskimyfkoedbxvvydgkfaixdsiotqhhzaxkedelfygbvckkapduueanbpvnfyfpgbfjnsaivedpeyrzgwmcfqgaqzjswfwneaebgdhbcuguwvjjxcrahxurrdgipsibtsdqlvqfajistngbjojtlfgrlbqlcyaewjhbybzeadjfexmprwragfvipgfkdwiuhpgoxqrjmrfgopwhphbuvkvlzkqcunxuypsjzsligwje", "idnbrgjmedujdcycmuhhoqbfvkkxwugvjuszcstuvegjndslhbxyxtihciqqkzbmnpavmubiojomiuzgfsufpszvxtdxbvstvxcbxnbfgoxdfgeczbtximspguvtwteosxypyzcckzqodmulbnyfdxjrjebsihjqnuzwwsyycjgmcmkvmizwkocbkmxblmtthlsuqzmyaslhggkvafkdaaysyzawpmudufnscswwqnnmsyjzqaddngqfkhdwolfaetadiwumgknctewtzcxeqqsdwmskcjoqadtbjcdzddvbrlmdqnakmcwetsukrpkadnibhielnesdtfazuoeslgzdqychuhtxdkeutjruelhgidgzyghsmkdsswlxwommniqfwfkzjxyxsopmagfepnhxwuqjcravblwgnwmptinwwapbqcnrwhvwpgbkewyqxkvysjabzdeghyptzebqvufazjwviczpwqfiyeauglzqjlvwyjvgvefnirualcnpdvxkmrekbbuwxffkplngjzofjvupmfxapjjcnykxrxsrzmirvnnbmucqyzrdyqkirqcplezzzqdxotcfpcucelnzlgusiolmrxjhgqnevvfsegikxcigcrosmkjbhrcfeqwyxjqdsergzhotivawcdipkmmxflclhynsdgwhimnnipynsfbfvlvbtgkvkgfstwrxyfljjzuzisszftatmmeuzdcbeqgzrshlaujptjankhebygriubjfwvtgnslweesfrbprrdtnaquvjrkcwnvfmsqqggvsnmeoghxnvlazyhrwhayzomyhitstlghgudwypwhgmwdiifdryrjrwizquqxryryjwrrzsofpagokxeffpgkiyvnnovyhgcxmjnyxqfvwamlhhgzvqxygcsrmaeqwrnnihfmlbbihuwjxwgkdcovlryvgtqngshpdcohaugoyfb") == 490088LL);
  assert_that(solve(220, "llqsknwejlkfxjznwwohkwgjbxhkcsudmgxhtsxkyidaxbbqlskkyzbxbiihyqaggmgnkrtbvwvjamkfyhjkgohajtqzjfkytxmtshqpcenezflbvtbntejesivdczitxynumayifoipcupmpfkgiovmtylrugoipisujhrcyksqqorgbirhltzbogkgfrrlmsmlwxfjcennlsxlapykxdakjcfc", "jzlmimvwlsmjyrbndnrqalwvkborbolfupldsifxqqrirpexavjkzrlqkbrmjikekdzyfxmwjxgsiymoyfjehprrcjebqpekvrdatfndypystlkgpqdbgrbbbheyirfluntdgnjfbzczmguhgqzuvexgkjlrqflkxnbqogaaaiomjlbzblvjeshhbcvsctyaeaixodlurnopyzhranihmjzeqmwq") == 23607LL);
  assert_that(solve(1, "i", "y") == 1LL);

  return 0;
}
