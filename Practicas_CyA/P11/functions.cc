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

/// @brief Lee los puntos de un archivo de texto
/// @param pv
/// @param file_name
void ReadPoints(CyA::point_vector &pv, std::string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de entrada" << std::endl;
        exit(1);
    }
    int num_points;
    file >> num_points; // Leer el número de puntos
    for (int i = 0; i < num_points; ++i) {
        CyA::point p;
        file >> p;
        pv.push_back(p);
    }
    file.close();
}

/// @brief Comprueba si se ha pasado la opción -d
/// @param argv 
/// @param ps 
void IsDot(char* option, EMST::point_set &ps) {
  std::string dot_option = "-d";
  if (option == dot_option) {
    std::cout << "El programa generará un archivo .dot" << std::endl;
    ps.WriteDot("output.dot");
  }
}