.PHONY: verify
verify: .competitive-verifier/local
	competitive-verifier verify --verify-json .competitive-verifier/local/verify_files.json --prev-result .competitive-verifier/local/result.json --output .competitive-verifier/local/result.json

.PHONY: resolve
resolve: .competitive-verifier/local
	CPLUS_INCLUDE_PATH= competitive-verifier oj-resolve --exclude archive atcoder lib template oj-resolve --config .verify-helper/config.toml >.competitive-verifier/local/verify_files.json

.PHONY: docs
docs: .competitive-verifier/local
	competitive-verifier docs --verify-json .competitive-verifier/local/verify_files.json .competitive-verifier/local/result.json
	(cd .competitive-verifier/_jekyll && bundle config set --local path .vendor/bundle && bundle install && bundle exec jekyll serve --incremental --livereload)

.competitive-verifier/local:
	mkdir -p $@
