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
		std::cout << "./opt.exe output_name list of input files" << std::endl;
		return -1;
  }
  std::string name(argv[1]);
  std::string solutions = "";
  for(int i=2; i<argc; i++) {
    std::cout << argv[i] << std::endl;
    solutions = solutions+argv[i]+"\t:"+" unsolved"+"\n";
  }
  write_file(name, solutions);

  return 0;
}
