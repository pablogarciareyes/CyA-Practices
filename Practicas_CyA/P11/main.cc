// Modificación: Introducir un umbral que evita que los arcos que estén a una distancia menor que ese umbral pertenezcan al arbol generador minimo

#include "functions.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  CyA::point_vector pv;
  ReadPoints(pv, argv[1]);
  EMST::point_set ps(pv);
  ps.EMST();
  // ps.Write(std::cout);
  ps.WriteTree(std::cout);
  IsDot(argv[2], ps);
  return 0;
}