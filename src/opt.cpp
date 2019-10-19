#include "nodo.h"
#include "solution.h"
#include "problem.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <sstream>

void write_file(std::string name, std::string content) {
	std::ofstream output (name);
	output << content << std::endl;
	output.close();
}

Solution solve(Problem problem) {
	Solution mejorSolucion;
	float mejorCoste = -1;

	Nodo<Solution>* arbol = new Nodo<Solution>(problem.getBaseSolution());
	std::vector<Nodo<Solution>*> listaSinExplorar;
	listaSinExplorar.push_back(arbol);

	while(!listaSinExplorar.empty()) {
		//exploramos, creamos hijos, metemos hijos a listaSinExplorar
		//si no tiene hijo, miramos lo buena que es su solucion
		//sacamos el ultimo nodo
		Nodo<Solution>* next = listaSinExplorar.back();
		listaSinExplorar.pop_back();
		//exploramos
		std::vector<Solution> hijos = next->getDato().explore();
		//creamos hijos, los metemos a lista sin explorar
		for(int i=0; i<hijos.size(); i++) {
			Nodo<Solution>* hijo = next->crearHijo(hijos[i]);
			listaSinExplorar.push_back(hijo);
		}
		//Si la solucion del Nodo explorado esta completa, compara coste y la guarda

		if(next->getDato().isComplete()) {
			float coste = problem.cost(next->getDato());
			if (mejorCoste == -1 || coste < mejorCoste) {
				mejorCoste = coste;
				mejorSolucion = next->getDato();
			}
		}
	}

	return mejorSolucion;
}

int main (int argc, char* argv[]) {
  if(argc < 3) {
		std::cout << "WRONG NUMBER OF ARGUMENTS!!!" << std::endl;
		std::cout << "./opt.exe output_filename input_files_list_filename" << std::endl;
		return -1;
  }
  std::string name_output(argv[1]);

	std::string name_input(argv[2]);

	std::string problemFile;
	std::ifstream input(name_input);

	std::string solutionString = "";
	while (std::getline(input, problemFile)) {
			if (!problemFile.empty()) {
				Problem problema(problemFile);
				auto start = std::chrono::steady_clock::now();
				Solution solucion = solve(problema);
				auto end = std::chrono::steady_clock::now();
				std::string time = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()) + " ms";
		    std::cout << problemFile << std::endl << "\t" << solucion.toString() << "\t"
					<< time
					<< std::endl;
		    solutionString = solutionString +problemFile+"\t:"+ solucion.toString() + "\t" + time + " ms\n";
			}
	}

	input.close();

  write_file(name_output, solutionString);

  return 0;
}
