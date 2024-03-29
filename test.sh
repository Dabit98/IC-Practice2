#!/bin/bash
printf "Cities\tGas\tDist\tWeight\tTime (µs)\n"
input="sizes.test"
while IFS= read -r line
do
  if [ -n "$line" ]; then
    ./data_gen.exe problems/index.p $line -t
    ./opt.exe "results.sol" problems/index.p -t
    make cleanProblems >> results.sol
  fi
done < "$input"
