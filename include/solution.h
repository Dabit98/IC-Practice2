#ifndef SOLUTION_H
#define SOLUTION_H
  #include <vector>
  #include <string>

  class Solution {
    private:
      int ciudades;
      //gasolineras que necesita el problema a ser solucionado
      int gasolineras;
      int gasolinerasPuestas;
      //para cada solucion, true si hay gasolinera
      std::vector<bool> solucion;

    public:

      Solution() : Solution(0,0) {};
      Solution(int cities, int gas);
      Solution(int cities, int gas, std::vector<int> ciudadesConGas);

      void addGas(int city);
      std::string toString();

      std::vector<Solution> explore();

      int getCities() {return ciudades;}
      int getGasStations() {return gasolineras;}
      bool gasAtCity(int city) {return solucion[city];}
      bool isComplete() {return gasolineras == gasolinerasPuestas;}

  };
#endif
