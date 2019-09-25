#include <iostream>
#include <string> 
#include <ctime>
#include <cstdlib>
#include "problem.cpp"

int main (int argc, char *argv[]) {
	
	int min_cities = 3
	int max_cities = atoi(argv[1]);
	if (max_cities < 5) {
		max_cities = 4;
	}
	int min_distance = 1
	int max_distance = atoi(argv[2]);
	int problems = atoi(argv[3]);
	srand(time(NULL));
	int id = rand();

	std::cout << "Max cities: " << max_cities << std::endl;
	std::cout << "Max distance: " << max_distance << std::endl;
	std::cout << "Problems: " << problems << std::endl;
	
	
	return 0;
}

int gas_stations(int cities) {
	int min_gas_stations = 2;
}

void write_problem_file(int id, 
