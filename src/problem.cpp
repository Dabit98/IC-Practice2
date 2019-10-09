#include "problem.h"
#include "fstream"


	 std::vector<std::string> Problem::split(std::string str, char pattern) {

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

		void Problem::print(std::vector<std::vector<int> > v)  {
			for (int i=0; i<v.size(); i++) {
				std::cout << "SIZE: " << v[i].size() << "\t";
				for(int j=0; j<v[i].size(); j++) {
					std::cout << v[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		void Problem::print(std::vector<std::string> v) {
			for (int i=0; i<v.size(); i++) {
				std::cout << v[i] << std::endl;
			}
		}

		Problem::Problem(int ciudades, int gasolineras, int min_dist, int max_dist) {
			srand(time(NULL));
			this->ciudades = ciudades;
			this->gasolineras = gasolineras;
			//genera los valores de diagonal e inferiores
			for (int i=0; i<ciudades; i++) {
				std::vector<int> distancias_ciudad;
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
				for(int j=i+1; j<ciudades; j++) {
					distancias[i].push_back(distancias[j][i]);
				}
			}
		}

		Problem::Problem(std::string s) {
			std::ifstream fe(s);
			std::string str="";
			std::string num="";

			while(!fe.eof()){
				fe >> num;
				str += num;
				str += '\t';
			}

			fe.close();
			
			std::vector<std::string> aux = split(str, '\t');
			ciudades = std::stoi(aux[0]);
			gasolineras = std::stoi(aux[1]);

			int it = 2;
			for(int i = 0; i < ciudades; i++){
				std::vector<int> distancias_ciudad;
				for(int j = 0; j < ciudades; j++){
					distancias_ciudad.push_back(std::stoi(aux[it]));
					it++;
				}
				distancias.push_back(distancias_ciudad);
			}

		}

		std::string Problem::toString() {
			std::string result = "";
			result += std::to_string(ciudades);
			result += "	" + std::to_string(gasolineras) + '\n';
			for(int i = 0; i < distancias.size(); i++){


				for(int j = 0; j < distancias[i].size(); j++){
					result += std::to_string(distancias[i][j]);

					if(j < distancias[i].size() - 1){
						result += "	";
					}
				}

				result += '\n';


			}
			return result;
		}
