#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include "problem.h"


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
//problems/ID_problemPNUM.p
std::string write_file(Problem* p, int id, int pnum) {
	std::string name = "problems/"+std::to_string(id)+"_problem"+std::to_string(pnum)+".p";
	std::ofstream output (name);
	output << p->toString() << std::endl;
	output.close();
	return name;
}

void write_file(std::string name, std::string content) {
	std::ofstream output (name);
	output << content << std::endl;
	output.close();
}

int main (int argc, char *argv[]) {

	srand(time(NULL));

	if (argc < 5) {
		std::cout << "WRONG NUMBER OF ARGUMENTS!!!" << std::endl;
		std::cout << "./data_gen.exe output_filename max_cities max_distance problems" << std::endl;
		return -1;
	}

	//Output file
	std::string output_filename(argv[1]);
	//Cities
	int min_cities = 3;
	int max_cities = atoi(argv[2]);
	if (max_cities < 5) {
		max_cities = 4;
	}
	//Distances
	int min_distance = 1;
	int max_distance = atoi(argv[3]);
	//Problems
	int problems = atoi(argv[4]);

	int id = rand(); //for the file


	std::cout << "Max cities: " << max_cities << std::endl;
	std::cout << "Max distance: " << max_distance << std::endl;
	std::cout << "Problems: " << problems << std::endl;

std::string problem_index = "";
	Problem* problem;
	for(int p=0; p<problems; p++) {
		int c = cities(min_cities, max_cities);
		int g = gas_stations(c);
		problem = new Problem(c, g, min_distance, max_distance);
		std::string name = write_file(problem, id, p);
		problem_index = problem_index + name + "\n";
		Problem* p2 = new Problem(name);
		write_file(p2, id+1, p);
		delete problem;
	}

	write_file(output_filename, problem_index);

	return 0;
}
