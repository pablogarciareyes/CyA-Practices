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

/// @brief Comprueba el Uso de paramétros en el programa
/// @param argc 
/// @param argv 
void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    std::string help_message;
    std::cerr << "Usage: " << "<input.fa> " << "<input.txt> " << std::endl;
    std::cerr << "Use --help para conocer la utilización del programa" << std::endl;
    std::cin >> help_message;
    if (help_message == "--help") {
      std::cout << "El programa lee un automata finito desde un ficher con extensión .fa y comprueba la aceptación de las cadenas escritas en otro fichero con extensión .txt" << std::endl;
    }
    exit(EXIT_SUCCESS);
  }
}

/// @brief Lee las cadenas de un fichero de texto y las almacena en un vector para su posterior procesamiento
/// @param nombre_fichero 
/// @param cadenas 
void leer_cadenas(const std::string& nombre_fichero, std::vector<Cadena>& cadenas) {
  std::ifstream file(nombre_fichero);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string line;
  while (std::getline(file, line)) {
    std::vector<char> cadena_vector;
    for (char c : line) {
      cadena_vector.push_back(c);
    }
    Cadena cadena(cadena_vector);
    cadenas.push_back(cadena);
  }
  file.close();
}

/// @brief Comprueba si las cadenas son aceptadas o rechazadas por el autómata, además de si contienen símbolos no reconocidos por el alfabeto
/// @param automata 
/// @param cadenas 
void comprobar_aceptacion(Automata& automata, const std::vector<Cadena>& cadenas) {
  for (const Cadena& cadena : cadenas) {
    if (automata.simularAutomata(cadena)) {
      std::cout << cadena;
      std::cout << " --- Accepted" << std::endl;
    } else {
      std::cout << cadena;
      std::cout << " --- Rejected" << std::endl;
    }
  }
}