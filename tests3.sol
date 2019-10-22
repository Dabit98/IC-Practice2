g++ -c -o obj/data_gen.o src/data_gen.cpp -Iinclude -std=c++11
g++ -o data_gen.exe obj/data_gen.o obj/problem.o obj/nodo.o obj/solution.o -Iinclude -std=c++11
./test.sh
Cities	Gas	Dist	Weight	Time (ms)
11	7	4	4	11	7	8	4	11	7	4	8	11	7	8	8	11	7	20	4	11	7	4	20	11	7	20	20	11	8	4	4	11	8	8	4	11	8	4	8	