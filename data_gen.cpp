#include <iostream>
#include <string> 
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include "problem.cpp"


int gas_stations(int cities) {
	int min_gas_stations = 2;
	int max_gas_stations = cities - 2;
	if (max_gas_stations < min_gas_stations) {
		max_gas_stations = min_gas_stations;
	}
	return rand() % (max_gas_stations +1 - min_gas_stations) + min_gas_stations;
}

int cities(int min_cities, int max_cities) {
	return rand() % (max_cities +1 - min_cities) + min_cities;
}

//Write file with the problem
//ID_problemPNUM.p
void write_file(Problem p, int id, int pnum) {
	std::ofstream output (std::to_string(id)+"_problem"+std::to_string(pnum)+".p");
	output << p.toString() << std::endl;
	output.close();
}

int main (int argc, char *argv[]) {

	srand(time(NULL));
	
	//Cities
	int min_cities = 3
	int max_cities = atoi(argv[1]);
	if (max_cities < 5) {
		max_cities = 4;
	}
	//Distances
	int min_distance = 1
	int max_distance = atoi(argv[2]);
	//Problems
	int problems = atoi(argv[3]);
	
	int id = rand(); //for the file
		

	std::cout << "Max cities: " << max_cities << std::endl;
	std::cout << "Max distance: " << max_distance << std::endl;
	std::cout << "Problems: " << problems << std::endl;

	Problem problem;
	for(int p=0; p<problems; p++) {
		int c = cities(min_cities, max_cities);
		int g = gas_stations(c);
		problem = new Problem(c, g, min_distance, max_distance);
		write_file(problem, id, p);
		delete problem;
	}
	
	return 0;
}


