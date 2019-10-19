#ifndef PROBLEM_H
#define PROBLEM_H
  #include "solution.h"

  #include <vector>
  #include <string>

  class Problem {
  	private:
      static bool semilla_inicializada;
  		int ciudades;
  		int gasolineras;
  		std::vector<std::vector<int> > distancias;
		  std::vector<int> pesos;

  	 std::vector<std::string> split(std::string str, char pattern);

  	public:

      /* HERRAMIENTAS DE DIAGNOSTICO
  		void print(std::vector<std::vector<int> > v);
  		void print(std::vector<std::string> v);
      */

  		Problem(int ciudades, int gasolineras, int min_dist, int max_dist, int max_weight);

  		Problem(std::string s);

  		std::string toString();

      float cost(Solution s);
      Solution getBaseSolution() {return Solution(ciudades, gasolineras);}

  		int getCities() {return ciudades;}
  		int getGasStations() {return gasolineras;}
  		int getDistancia(int city1, int city2) {return distancias[city1][city2];}
      int getPeso(int city) {return pesos[city];}

  };


#endif
