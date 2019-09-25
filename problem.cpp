#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

class Problem {
	private:
		int cities;
		int gas_stations;
		std::vector<std::vector<int>> distancias;
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

		Problem(std::string s) {}
		
		std::string toString() {return "";} 


};
