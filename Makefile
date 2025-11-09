.PHONY: verify-multi-process
verify-multi-process: .competitive-verifier/local
	seq 0 $(shell expr $(shell nproc) - 1) | xargs -I {} -P $(shell nproc) competitive-verifier verify --verify-json .competitive-verifier/local/verify_files.json --prev-result .competitive-verifier/local/result.json --split $(shell nproc) --split-index {} --output .competitive-verifier/local/result-{}.json
	competitive-verifier merge-result .competitive-verifier/local/result-*.json >.competitive-verifier/local/result.json
	rm .competitive-verifier/local/result-*.json
	competitive-verifier check .competitive-verifier/local/result.json

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
