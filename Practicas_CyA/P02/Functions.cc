// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo functions.cc: Archivo que contiene la implementación de las funciones
// Contiene la definición de funciones necesarias para la lectura de ficheros y comprobación de argumentos
// Referencias:
// Enlaces de interés
//
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#include "Functions.h"



/// @brief Lee el fichero de entrada y almacena cada cadena y alfabeto
/// @param nombre_fichero 
/// @param cadena_entrada 
/// @param alfabeto_entrada 
void read_fichero(const std::string& nombre_fichero, std::vector<Cadena>& cadenas_introducidas, std::vector<Alfabeto>& alfabetos_introducidos) {
  std::ifstream archivo_entrada(nombre_fichero);
  std::string linea_lectura;
  
  while(std::getline(archivo_entrada, linea_lectura)) {
    Cadena cadena_entrada;
    Alfabeto alfabeto_entrada;
    std::istringstream entrada_palabras(linea_lectura);
    std::string cadena_linea, alfabeto_linea;
    entrada_palabras >> cadena_linea >> alfabeto_linea;
    // Insertar símbolos en la cadena
    for(int i = 0; i < cadena_linea.length(); i++) {
      cadena_entrada.insertSymbol(cadena_linea[i]);
    }
    // Insertar símbolos en el alfabeto
    for(int i = 0; i < alfabeto_linea.length(); i++) {
      alfabeto_entrada.insertSymbol(alfabeto_linea[i]);
    }

    if (!alfabeto_entrada.perteneceAlfabeto(cadena_entrada)) {
      std::cerr << "La cadena: " << cadena_linea << " no pertenece al alfabeto: " << alfabeto_linea << std::endl;
      exit(EXIT_SUCCESS);
    }

    cadenas_introducidas.push_back(cadena_entrada);
    alfabetos_introducidos.push_back(alfabeto_entrada);
  }
}

/// @brief Comprueba si los argumentos de entrada son correctos
/// @param argc 
/// @param argv 
void Usage(int argc, char* argv[]) {
    if (argc != 4) {
        std::string help_message;
        std::cerr << "Usage: " << "<filein.txt> " << "<fileout.txt> " << "<opcode>" << std::endl;
        std::cerr << "Use --help para conocer la utilización del programa" << std::endl;
        std::cin >> help_message;
        if (help_message == "--help") {
          std::cout << "El programa lee cadenas y alfabetos desde un fichero de entrada y realiza operaciones siguiendo su respectivo código las cuales escriben el resultado en el fichero de salida." << std::endl;
        }
        exit(EXIT_SUCCESS);
    }
}

/// @brief Comprueba si los argumentos de entrada son correctos
/// @param argc 
/// @param argv 
void UsageOption6(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << "<filein.txt> " << "<fileout.txt> " << "<opcode>" << "<n>" << std::endl;
        exit(EXIT_SUCCESS);
    }
}