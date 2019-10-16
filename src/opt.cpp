#include <iostream>
#include <fstream>

void write_file(std::string name, std::string content) {
	std::ofstream output (name);
	output << content << std::endl;
	output.close();
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
		std::cout << "WRONG NUMBER OF ARGUMENTS!!!" << std::endl;
		std::cout << "./opt.exe output_filename input_files_list_filename" << std::endl;
		return -1;
  }
  std::string name_output(argv[1]);

	std::string name_input(argv[2]);

	std::string problem;
	std::ifstream input(name_input);

	std::string solutions = "";
	while (std::getline(input, problem)) {
			if (!problem.empty()) {
		    std::cout << problem << std::endl;
		    solutions = solutions+problem+"\t:"+" unsolved"+"\n";
			}
	}

	input.close();

  write_file(name_output, solutions);

  return 0;
}
