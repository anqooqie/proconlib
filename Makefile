.PHONY: test
test:
	oj-verify run -j 2

.PHONY: docs
docs:
	oj-verify docs
	(cd .verify-helper/markdown && bundle exec jekyll serve --incremental)

.PHONY: watch
watch:
	./watch.sh
