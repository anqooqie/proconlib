.PHONY: docs
docs:
	oj-verify docs
	(cd .verify-helper/markdown && bundle exec jekyll serve --incremental)
