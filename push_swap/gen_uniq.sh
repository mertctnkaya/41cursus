#!/usr/bin/env bash

print_help() {
  cat <<EOF
Usage: $0 -m <MIN> -M <MAX> [OPTION]...
Generate random numbers and pass them as arguments to ./a.out.
Mandatory arguments:
  -m, --min=<MIN>        Minimum value for random numbers
  -M, --max=<MAX>        Maximum value for random numbers
Optional arguments:
  -c, --count=<N>        Number of random arguments to generate (default: 5)
  -h, --help             Display this help and exit
EOF
  exit 1
}

parse_args() {
  local COUNT
  COUNT=5
  if ! ARGS=$(getopt -o "m:M:c:h" -l min:,max:,count:,help -- "$@"); then
    print_help
  fi
  eval set -- "${ARGS}"
  while true; do
    case "$1" in
      -m|--min) MIN=$2; shift 2 ;;
      -M|--max) MAX=$2; shift 2 ;;
      -c|--count) COUNT=$2; shift 2 ;;
      -h|--help) print_help ;;
      --) shift; break ;;
      *) print_help ;;
    esac
  done
  if [ -z "${MIN}" ] || [ -z "${MAX}" ]; then
    echo "$0: error: --min and --max are required." >&2
    echo "Try '$0 --help' for more information." >&2
    exit 1
  fi
  NUMS=$(shuf -i "${MIN}-${MAX}" -n "${COUNT}")
#   echo $NUMS
#   echo -ne "\n"
  ./push_swap $NUMS
}

main() {
  parse_args "$@"
}

main "$@"