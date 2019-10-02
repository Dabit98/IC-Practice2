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

	 std::vector<std::string> split(std::string str, char pattern) {

		 int posInit = 0;
		 int posFound = 0;
		 std::string splitted;
		 std::vector<std::string> resultados;

		 while(posFound >= 0){
		 posFound = str.find(pattern, posInit);
		 splitted = str.substr(posInit, posFound - posInit);
		 posInit = posFound + 1;
		 resultados.push_back(splitted);
			 }

			 return resultados;
	 }

	public:

		void print(std::vector<std::vector<int> > v)  {
			for (int i=0; i<v.size(); i++) {
				std::cout << "SIZE: " << v[i].size() << std::endl;
			}
		}

		Problem(int ciudades, int gasolineras, int min_dist, int max_dist) {
			srand(time(NULL));
			this->ciudades = ciudades;
			this->gasolineras = gasolineras;
			std::vector<int> distancias_ciudad;
			//genera los valores de diagonal e inferiores
			for (int i=0; i<ciudades; i++) {
				for (int j=0; j<i; j++) {
					distancias_ciudad.push_back(
						rand() % (max_dist + 1 - min_dist) + min_dist
					);
				}
				distancias_ciudad.push_back(0);
				distancias.push_back(distancias_ciudad);
			}
			//copia los valores superiores a la diagonal
			for(int i=0; i<ciudades; i++) {
				for(int j=i; j<ciudades; j++) {
					distancias[i].push_back(distancias[j][i]);
				}
			}
		}

		Problem(std::string s) {
			std::vector<std::string> aux = split(s, '\n');
			std::vector<std::string> ciudadesEstaciones = split(aux[0], '	');
			ciudades = std::stoi(ciudadesEstaciones[0]);
			gasolineras = std::stoi(ciudadesEstaciones[1]);

			for(int i = 1; i < aux.size(); i++){
				std::vector<std::string> distan = split(aux[i], '	');
				for(int j = 0; j < distan.size(); j++){
					distancias[i-1].push_back(std::stoi(distan[j]));
				}
			}
		}

		std::string toString() {
			std::string result = "";
			result += ciudades;
			result += "	" + gasolineras + '\n';
			for(int i = 0; i < distancias.size(); i++){


				for(int j = 0; j < distancias[i].size(); j++){
					result += distancias[i][j];

					if(i < distancias[i].size() - 1){
						result += "	";
					}
				}

				result += '\n';


			}
			return result;
		}

		int getCities() {return ciudades;}
		int getGasStations() {return gasolineras;}
		int getDistancia(int city1, int city2) {return distancias[city1][city2];}

};
