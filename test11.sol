g++ -c -o obj/data_gen.o src/data_gen.cpp -Iinclude -std=c++11 -Ofast
g++ -o data_gen.exe obj/data_gen.o obj/problem.o obj/nodo.o obj/solution.o -Iinclude -std=c++11 -Ofast
./test.sh
Cities	Gas	Dist	Weight	Time (ms)
11	3	4	4	1.2
11	3	8	4	1
11	3	4	8	1
11	3	8	8	1.1
11	3	20	4	3.9
11	3	4	20	2.9
11	3	20	20	4.9
11	4	4	4	16.9
11	4	8	4	15.8
11	4	4	8	15.4
11	4	8	8	15.9
11	4	20	4	21.3
11	4	4	20	13.5
11	4	20	20	15.4
11	5	4	4	113.6
11	5	8	4	109.2
11	5	4	8	111
11	5	8	8	109
11	5	20	4	109.9
11	5	4	20	105.2
11	5	20	20	110.8
11	6	4	4	639.5
11	6	8	4	622
11	6	4	8	623.2
11	6	8	8	626.5
11	6	20	4	618.7
11	6	4	20	612.7
11	6	20	20	617.5
