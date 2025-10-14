#!/usr/bin/env bash

print_help() {
  cat <<EOF
Usage: $0 -m <MIN> -M <MAX> [OPTION]...
Generate random numbers and pass them as arguments to ./push_swap.

Mandatory arguments:
  -m, --min=<MIN>        Minimum value for random numbers
  -M, --max=<MAX>        Maximum value for random numbers

Optional arguments:
  -n, --number=<N>		Number of random arguments to generate (default: 5)
  -c, --check=<0|1>		Run checker if 1 (default: 0)
  -s, --show=<0|1>		Show integers before running (default: 0) 
  -h, --help			Display this help and exit
EOF
  exit 1
}

parse_args() {
  local COUNT=5
  local CHECK=0
  local SHOW=0

  local RED="\033[1;31m"
  local GREEN="\033[1;32m"
  local GRAY="\033[0;37m"
  local RESET="\033[0m"


  if ! ARGS=$(getopt -o "m:M:n:csh" -l min:,max:,number:,check:,show:,help -- "$@"); then
    print_help
  fi

  eval set -- "${ARGS}"

  while true; do
    case "$1" in
      -m|--min) MIN=$2; shift 2 ;;
      -M|--max) MAX=$2; shift 2 ;;
      -n|--number) COUNT=$2; shift 2 ;;
      -c|--check) CHECK=1; shift ;;
	  -s|--show) SHOW=1; shift ;;
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

  if [ "$SHOW" -eq 1 ]; then
    OUT=$(echo $NUMS | tr '\n' ' ')
  	echo -e "${GRAY}$OUT${RESET}\n"
  fi

  if [ "$CHECK" -eq 1 ]; then
    RESULT=$(./push_swap $NUMS | ./checker $NUMS)
	MOVES=$(./push_swap $NUMS | wc -l)
    if [ "$RESULT" = "OK" ]; then
	  	echo -e "${RED}Moves: ${MOVES}${RESET}"
      echo -e "${GREEN}Checker Result: OK${RESET}"
    else
	  	echo -e "${RED}Moves: ${MOVES}${RESET}"
      echo -e "${RED}Checker Result: $RESULT${RESET}"
    fi
  else
    MOVES=$(./push_swap $NUMS | wc -l)
    echo -e "${RED}Moves: ${MOVES}${RESET}"
  fi
}

main() {
  parse_args "$@"
}

main "$@"
