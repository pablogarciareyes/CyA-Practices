/* *
* Universidad de La Laguna
* Escuela Superior de Ingenieria y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 12: Algoritmos Divide y venceras
* Autor: Pablo García de los Reyes
* Correo: alu0101630045@ull.edu.es
* Fecha: 17/12/2024
* Archivo Functions.cc: Source File
* Definición de funciones
* 15/12/2024 - Creación (primera versión) del código
*/

#include "functions.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

/// @brief Comprueba que el paso de parámetros del programa sea correcto
/// @param argc 
/// @param argv 
void Usage(int argc, char* argv[]) {
  if (argc > 3) {
    std::string help_message;
    std::cerr << "Usage: " << argv[0] << "<input.txt> " << std::endl;
    std::cerr << "Use --help para conocer la utilización del programa" << std::endl;
    std::cin >> help_message;
    if (help_message == "--help") {
      std::cout << "El programa lee un fichero con puntos de un plano para realizar operaciones sobre estos." << std::endl;
    }
    exit(EXIT_SUCCESS);
  }
}

/// @brief Lee los puntos de un fichero y los almacena en un vector
/// @param ifs
/// @param points
void ReadPoints(std::string filename, CyA::point_vector& points) {
  std::ifstream ifs(filename);
  if (!ifs) {
    std::cerr << "Error al abrir el fichero " << filename << std::endl;
    exit(EXIT_FAILURE);
  }
  double x, y, points_number;
  ifs >> points_number;
  while (ifs >> x >> y) {
    points.push_back(std::make_pair(x, y));
  }
  ifs.close();
}

/// @brief Comprueba si se ha pasado la opción -d
/// @param argv 
/// @param ps 
void IsDot(char* option, CyA::PointSet &ps) {
  std::string dot_option = "-d";
  if (option == dot_option) {
    std::cout << "El programa generará un archivo .dot" << std::endl;
    std::ofstream archivo_salida("output.dot");
    ps.WriteDot(archivo_salida);
  }
}