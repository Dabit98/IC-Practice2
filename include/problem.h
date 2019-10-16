#ifndef PROBLEM_H
#define PROBLEM_H
  #include <iostream>
  #include <ctime>
  #include <cstdlib>
  #include <vector>
  #include <string>

  class Problem {
  	private:
  		int ciudades;
  		int gasolineras;
  		std::vector<std::vector<int> > distancias;
		std::vector<int> pesos;

  	 std::vector<std::string> split(std::string str, char pattern);

  	public:

  		void print(std::vector<std::vector<int> > v);

  		void print(std::vector<std::string> v);

  		Problem(int ciudades, int gasolineras, int min_dist, int max_dist);

  		Problem(std::string s);

  		std::string toString();

  		int getCities() {return ciudades;}
  		int getGasStations() {return gasolineras;}
  		int getDistancia(int city1, int city2) {return distancias[city1][city2];}
		

  };


#endif
