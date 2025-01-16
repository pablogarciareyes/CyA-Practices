// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Cadenas.cc: Archivo que contiene la implementación de los métodos de la clase Cadena 
// Contiene la implementación de los métodos de la clase Cadena
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#include "Funciones.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  Automata automata(argv[1]);
  std::vector<Cadena> cadenas;
  leer_cadenas(argv[2], cadenas);
  automata.imprimirEstadosNoAlcanzablesDesdeArranque();
  comprobar_aceptacion(automata, cadenas);
  return 0;
}