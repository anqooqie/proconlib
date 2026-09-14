.PHONY: test
test:
	python3 scripts/test.py $(foreach compiler,$(COMPILER),--compiler $(compiler)) $(FILES)

.PHONY: docs
docs:
	python3 scripts/test.py --docs
	(cd .competitive-verifier/_jekyll && bundle config set --local path .vendor/bundle && bundle install && bundle exec jekyll serve --incremental --livereload)
