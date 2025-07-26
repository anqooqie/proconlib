CXXFLAGS = -Wall -Wextra -pedantic -std=c++20 -O2 -g -fsanitize=address,undefined -DLOCAL
LDFLAGS = -lm

a.out: combined.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

combined.cpp: main.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

output_checker: output_checker_combined.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

output_checker_combined.cpp: output_checker.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

input_generator: input_generator_combined.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

input_generator_combined.cpp: input_generator.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

output_generator: output_generator_combined.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

output_generator_combined.cpp: output_generator.cpp include
	oj-bundle -I include $< | tee $@ >/dev/null

include:
	mkdir -p $@
	ln -f -s /workspaces/proconenv/lib/atcoder $@/atcoder
	ln -f -s /workspaces/proconenv/lib/tools $@/tools

.PHONY: g/i
g/i: input_generator
	rm -f test/random-*
	oj g/i ./input_generator 10

.PHONY: g/o
g/o: output_generator
	oj g/o -c ./output_generator

.PHONY: hack
hack: a.out input_generator output_generator
	rm -f test/hack-*
	oj g/i --hack-expected ./output_generator --hack-actual ./a.out ./input_generator

.PHONY: test
test: a.out # output_checker
	oj test
#	oj test -e 1e-6
#	oj test --judge-command ./output_checker
#	oj test-reactive ./output_checker

.PHONY: submit
submit: combined.cpp
	acc submit --skip-filename -- --wait 0 --no-open --yes

.PHONY: clean
clean:
	rm -f *~ a.out combined.cpp output_checker output_checker_combined.cpp input_generator input_generator_combined.cpp output_generator output_generator_combined.cpp

.PHONY: force
force:
	$(MAKE) clean
	$(MAKE)
