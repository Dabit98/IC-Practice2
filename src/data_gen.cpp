#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include "problem.h"

//Write file with the problem
//problems/ID_problemPNUM.p
std::string write_file(Problem* p, int id, int pnum) {
	std::string name = "problems/"+std::to_string(id)+"_problem"+std::to_string(pnum)+".p";
	std::ofstream output (name);
	output << p->toString() << std::endl;
	output.close();
	return name;
}

void append_file(std::string name, std::string content) {
	std::ofstream output (name, std::fstream::out | std::fstream::app);
	output << content << std::endl;
	output.close();
}

int main (int argc, char *argv[]) {

	srand(time(NULL));

	if (argc < 5) {
		std::cout << "WRONG NUMBER OF ARGUMENTS!!!" << std::endl;
		std::cout << "./data_gen.exe output_filename max_cities max_distance max_weight problems [-t]" << std::endl;
		return -1;
	}

	//Output file
	std::string output_filename(argv[1]);
	//Cities
	int c = atoi(argv[2]);
	if (c < 4) {
		c = 4;
	}
	//Gas stations
	int g = atoi(argv[3]);
	if (g < 3) {
		g = 3;
	}
	if (c < g) {
		g = c-1;
	}
	//Distances
	int min_distance = 1;
	int max_distance = atoi(argv[4]);
	//Weight
	int max_weight = atoi(argv[5]);
	//Problems
	int problems = atoi(argv[6]);

	bool test = false;
	if(7 < argc && 0==strcmp(argv[7], "-t")) {
		test = true;
	}

	int id = rand(); //for the file

	if (test) {
		std::cout << c << "\t"
						<< g << "\t"
						<< max_distance << "\t"
						<< max_weight << "\t";
	} else {
		std::cout << "Cities: " << c << std::endl;
		std::cout << "Gas stations: " << g << std::endl;
		std::cout << "Max distance: " << max_distance << std::endl;
		std::cout << "Max weight: " << max_weight << std::endl;
		std::cout << "Problems: " << problems << std::endl;
	}

std::string problem_index = "";
	Problem* problem;
	for(int p=0; p<problems; p++) {
		problem = new Problem(c, g, min_distance, max_distance, max_weight);
		std::string name = write_file(problem, id, p);
		problem_index = problem_index + name + "\n";
		delete problem;
	}

	append_file(output_filename, problem_index);

	return 0;
}
