g++ -c -o obj/data_gen.o src/data_gen.cpp -Iinclude -std=c++11 -O0
g++ -o data_gen.exe obj/data_gen.o obj/problem.o obj/nodo.o obj/solution.o -Iinclude -std=c++11 -O0
./test.sh
Cities	Gas	Dist	Weight	Time (µs)
4	3	4	4	384.8
4	4	4	4	2643.8
5	3	4	4	1394
5	4	4	4	4986.6
5	5	4	4	6993.8
6	3	4	4	3396.8
6	4	4	4	9573.6
6	5	4	4	15418
6	6	4	4	21302.3
7	3	4	4	2984.9
7	4	4	4	12364.6
7	5	4	4	45991.1
7	6	4	4	102289
7	7	4	4	145821
8	3	4	4	6617.8
8	4	4	4	31655.4
8	5	4	4	116261
8	6	4	4	377720
8	7	4	4	838083
8	8	4	4	1.20927e+06
9	3	4	4	7830
9	4	4	4	50713.8
9	5	4	4	261505
9	6	4	4	1.08271e+06
9	7	4	4	3.49771e+06
9	8	4	4	8.29608e+06
9	9	4	4	1.18829e+07
10	3	4	4	13035.7
10	4	4	4	96176.3
10	5	4	4	586189
10	6	4	4	3.08181e+06
10	7	4	4	1.19881e+07
10	8	4	4	10	9	4	4	Makefile:47: fallo en las instrucciones para el objetivo 'test'
