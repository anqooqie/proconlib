#!/usr/bin/bash -eu

while :; do
  STATE="$(curl -L -H 'Accept: application/vnd.github+json' -H 'Authorization: Bearer '"$GH_PAT" -H 'X-GitHub-Api-Version: 2022-11-28' 'https://api.github.com/repos/anqooqie/proconlib/actions/runs?branch=main&per_page=1' 2>/dev/null | ruby -r json -r time -e 'w = JSON.parse(STDIN.read)["workflow_runs"][0]; puts w["status"] != "completed" ? "waiting" : Time.iso8601(w["updated_at"]) - Time.iso8601(w["run_started_at"]) <= 600 ? "completed" : "running"')"
  echo '['"$(date '+%Y/%m/%d %H:%M:%S')"'] '"$STATE" >&2
  if [ "$STATE" = 'waiting' ]; then
    sleep 10
  elif [ "$STATE" = 'running' ]; then
    git fetch auto
    git merge auto/main
    git commit --allow-empty -m 'Rerun verification'
    git push auto main
    sleep 30
  elif [ "$STATE" = 'completed' ]; then
    git fetch auto
    git merge auto/main
    break
  fi
done
