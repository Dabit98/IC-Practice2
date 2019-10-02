#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

class Problem {
	private:
		int ciudades;
		int gas_stations;
		std::vector<std::vector<int>> distancias;

	 vector<string> split(string str, char pattern) {

			 int posInit = 0;
			 int posFound = 0;
			 std::string splitted;
			 std::vector<string> resultados;

			 while(posFound >= 0){
		 posFound = str.find(pattern, posInit);
		 splitted = str.substr(posInit, posFound - posInit);
		 posInit = posFound + 1;
		 resultados.push_back(splitted);
			 }

			 return resultados;
	 }

	public:
		Problem(int ciudades, int gasolineras, int min_dist, int max_dist) {
			srand(time(NULL));
			this->ciudades = ciudades;
			this->gasolineras = gasolineras;
			distancias = new std::vector<std::vector<int>>();
			std::vector<int> distancias_ciudad;
			//genera los valores de diagonal e inferiores
			for (int i=0; i<ciudades; i++) {
				distancias_ciudad = new std::vector<int>();
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
				for(int i=j; j<ciudades; j++) {
					distancias[i].pushback(distancias[j][i]);
				}
			}
		}

		Problem(std::string s) {
			std::vector<string> aux = split(s, '\n');
			std::vector<string> ciudadesEstaciones = split(aux[0], '	');
			ciudades = std::stoi(ciudadesEstaciones[0]);
			gas_stations = std::stoi(ciudadesEstaciones[1]);

			for(Int i = 1; i < aux.size(); i++){
				std::vector<string>distan = split(aux[i], '	');
				for(int j = 0; j < distan; j++){
					distancias[i-1].pushback(distan[j]);
				}
			}
		}

		std::string toString() {
			std::string result = "";
			result += ciudades;
			result += "	" + gas_stations + '\n';
			for(int i = 0; i < distancias.size(); i++){


				for(int j = 0; j < distacias[i].size(); j++){
					result += distancias[i][j];

					if(i < distancias[i].size() - 1){
						result += "	";
					}
				}

				result += '\n'


			}


			return result;
		}

		int getCities() {return ciudades;}
		int getGasStations() {return gas_stations;}
		int getDistancia(int city1, int city2) {return distancias[city1][city2];}

};
