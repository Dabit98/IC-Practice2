#include "solution.h"


std::vector<Solution> Solution::explore() {
  std::vector<Solution> hijos;
  if(gasolinerasPuestas < gasolineras) {
    for(int c=0; c<ciudades; c++) {
      if(!solucion[c]) {
        Solution s = (*this);
        s.addGas(c);
        hijos.push_back(s);
      }
    }
  }
  return hijos;
}

Solution::Solution(int cities, int gas) {
  ciudades = cities;
  gasolineras = gas;
  for(int i = 0; i<cities; i++) {
    solucion.push_back(false);
  }
  gasolinerasPuestas = 0;
}

Solution::Solution(int cities, int gas, std::vector<int> ciudadesConGas) : Solution(cities, gas) {
  for(; gasolinerasPuestas<ciudadesConGas.size() && gasolinerasPuestas<gasolineras; gasolinerasPuestas++) {
    solucion[ciudadesConGas[gasolinerasPuestas]] = true;
  }
}


void Solution::addGas(int city) {
    if(gasolinerasPuestas < gasolineras && !solucion[city]) {
      solucion[city] = true;
      gasolinerasPuestas++;
    }
}

std::string Solution::toString() {
  std::string output = "";
  for(int i=0; i<solucion.size(); i++) {
    if(0 < i) {
      output = output + "\t\t";
    }
    if(solucion[i]) {
      output = output+"  GAS  ";
    } else {
      output = output+"SIN GAS";
    }
  }
  return output;
}
