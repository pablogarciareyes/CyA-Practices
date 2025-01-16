// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Funciones.cc: Archivo que contiene la implementación de las funciones necesarias para la ejecución del programa
// Contiene la definición de las funciones necesarias para la ejecución del programa
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código

#include "funciones.h"

/// @brief Comprueba el Uso de paramétros en el programa
/// @param argc 
/// @param argv 
void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    std::string help_message;
    std::cerr << "Usage: " << "<input.gra> " << "<output.gra> " << std::endl;
    std::cerr << "Use --help para conocer la utilización del programa" << std::endl;
    std::cin >> help_message;
    if (help_message == "--help") {
      std::cout << "El programa lee una gramática de un fichero de texto y la transforma a la forma normal de Chomsky" << std::endl;
    }
    exit(EXIT_SUCCESS);
  }
}

/// @brief Comprueba que la gramática esté simplificada para poder aplicar el algoritmo pertinente.
/// @param gramatica_usuario 
void ComprobarGramatica(Gramatica gramatica_usuario) {
  if (gramatica_usuario.comprobarProduccionesUnitarias() || gramatica_usuario.comprobarProduccionesVacias()) {
    std::cerr << "La gramática contiene producciones unitarias o vacías" << std::endl;    
    exit(EXIT_SUCCESS);
  }
}

/// @brief Aplica el algoritmo de Chomsky a la gramática
/// @param gramatica_usuario
/// @param fichero_salida
void AplicarAlgoritmo(Gramatica gramatica_usuario, std::string fichero_salida) {
  ComprobarGramatica(gramatica_usuario);
  Gramatica gramatica_en_forma_chomsky = gramatica_usuario.algoritmoFormaNormalChomsky();
  gramatica_en_forma_chomsky.writeGramatica(fichero_salida);
}