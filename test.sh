#!/bin/bash
printf "Cities\tGas\tDist\tWeight\tTime (ms)\n"
input="sizes.test"
while IFS= read -r line
do
  ./data_gen.exe problems/index.p $line -t
  ./opt.exe "results.sol" problems/index.p -t
  make cleanProblems >> results.sol
done < "$input"