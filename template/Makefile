CXXFLAGS = -Wall -Wextra -pedantic -g -fsanitize=address,undefined -std=c++17 -O2 -DLOCAL
LDFLAGS = -lm
LIB_PATH = ~/.local/lib64

a.out: combined.cpp
	LD_RUN_PATH=$(LIB_PATH) $(CXX) $(CXXFLAGS) -o $@ $<

combined.cpp: main.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

output_checker: output_checker_combined.cpp
	LD_RUN_PATH=$(LIB_PATH) $(CXX) $(CXXFLAGS) -o $@ $<

output_checker_combined.cpp: output_checker.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

input_generator: input_generator_combined.cpp
	LD_RUN_PATH=$(LIB_PATH) $(CXX) $(CXXFLAGS) -o $@ $<

input_generator_combined.cpp: input_generator.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

output_generator: output_generator_combined.cpp
	LD_RUN_PATH=$(LIB_PATH) $(CXX) $(CXXFLAGS) -o $@ $<

output_generator_combined.cpp: output_generator.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

include:
	mkdir -p $@
	ln -f -s ~/.proconlib/atcoder $@/atcoder
	ln -f -s ~/.proconlib/tools $@/tools

.PHONY: g/i
g/i: input_generator
	rm -f test/random-*
	LD_LIBRARY_PATH=$(LIB_PATH) oj g/i ./input_generator 10

.PHONY: g/o
g/o: output_generator
	LD_LIBRARY_PATH=$(LIB_PATH) oj g/o -c ./output_generator

.PHONY: hack
hack: a.out input_generator output_generator
	rm -f test/hack-*
	LD_LIBRARY_PATH=$(LIB_PATH) oj g/i --hack-expected ./output_generator --hack-actual ./a.out ./input_generator

.PHONY: test
test: a.out # output_checker
	LD_LIBRARY_PATH=$(LIB_PATH) oj test
#	LD_LIBRARY_PATH=$(LIB_PATH) oj test -e 1e-6
#	LD_LIBRARY_PATH=$(LIB_PATH) oj test --judge-command ./output_checker
#	LD_LIBRARY_PATH=$(LIB_PATH) oj test-reactive ./output_checker

.PHONY: submit
submit: combined.cpp
	acc submit --skip-filename -- --wait 0 --no-open --yes

.PHONY: clean
clean:
	rm -f *~ a.out combined.cpp {output_checker,input_generator,output_generator}{,_combined.cpp}

.PHONY: force
force:
	$(MAKE) clean
	$(MAKE)
