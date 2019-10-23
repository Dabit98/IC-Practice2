#include "nodo.h"
#include "solution.h"
#include "problem.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <sstream>
#include <string.h>

void write_file(std::string name, std::string content) {
	std::ofstream output (name);
	output << content << std::endl;
	output.close();
}

Solution solve(Problem problem) {
	Solution mejorSolucion;
	float mejorCoste = -1;

	/*
	 *	1: Inicializamos los datos
	 */
	Nodo<Solution>* arbol = new Nodo<Solution>(problem.getBaseSolution());
	std::vector<Nodo<Solution>*> listaSinExplorar;
	listaSinExplorar.push_back(arbol);

		while(!listaSinExplorar.empty()) {
		/*
		 *	2: Exploramos el arbol
		 */
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

		//Si la solucion del Nodo explorado esta completa, deja de explorar el arbol
		if(next->getDato().isComplete()) {
			/*
			 *	3: Calcula el coste
			 */
			float coste = problem.cost(next->getDato());

			/*
			 *	4: Se queda con el mejor coste
			 */
			if (mejorCoste == -1 || coste < mejorCoste) {
				mejorCoste = coste;
				mejorSolucion = next->getDato();
			}
		}
	}

	/*
	 *	5: Una vez acaba el pipeline, devuelve el mejor
	 */
	return mejorSolucion;
}

int main (int argc, char* argv[]) {
  if(argc < 3) {
		std::cout << "WRONG NUMBER OF ARGUMENTS!!!" << std::endl;
		std::cout << "./opt.exe output_filename input_files_list_filename [-t]" << std::endl;
		return -1;
  }
  std::string name_output(argv[1]);

	std::string name_input(argv[2]);

	bool test = false;
	if(3 < argc && 0==strcmp(argv[3], "-t")) {
		test = true;
	}

	std::string problemFile;
	std::ifstream input(name_input);

	std::string solutionString = "";
	float acc = 0;
	int total = 0;
	while (std::getline(input, problemFile)) {
			if (!problemFile.empty()) {
				Problem problema(problemFile);
				auto start = std::chrono::steady_clock::now();
				Solution solucion = solve(problema);
				auto end = std::chrono::steady_clock::now();
				std::string time = std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
				if (!test) {
			    std::cout << problemFile << std::endl << "\t" << solucion.toString() << "\t"
						<< time << " µs"
						<< std::endl;
				}
		    solutionString = solutionString +problemFile+"\t:"+ solucion.toString() + "\n";
				acc += atoi(time.c_str());
				total++;
			}
	}

	if(!test) {
		std::cout << "MEDIA: ";
	}
	std::cout << acc/total << std::endl;

	input.close();

  write_file(name_output, solutionString);

  return 0;
}
