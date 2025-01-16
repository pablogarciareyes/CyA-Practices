// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Alfabeto.cc: Archivo que contiene la implementación de los métodos de la clase Alfabeto
// Contiene la implementación de los métodos de la clase Alfabeto insertSymbol, writeAlfabeto y perteneceAlfabeto
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código
// 20/10/2024 - Implementación de nuevos métodos para su utilización en la práctica 6

#include "Alfabeto.h"

/// @brief Inserta un símbolo en el alfabeto
/// @param simbolo_insertar 
void Alfabeto::insertSymbol(const char simbolo_insertar) {
  alfabeto_set_.insert(simbolo_insertar);
}

/// @brief Escritura del alfabeto en un fichero
/// @param nombre_fichero 
void Alfabeto::writeAlfabeto(const std::string& nombre_fichero) {
  std::ofstream file(nombre_fichero, std::ios::app);
  if (file.is_open()) {
    file << "{";
    for(std::set<char>::iterator it = alfabeto_set_.begin(); it != alfabeto_set_.end(); it++) {
      if (std::next(it) == alfabeto_set_.end()) {
        file << *it;
      } else {
        file << *it << ", ";
      }
    }
    file << "}" << std::endl;
    file.close();
  }
}

/// @brief Comprueba si una cadena pertenece al alfabeto
/// @param cadena_comprobar
bool Alfabeto::perteneceAlfabeto(Cadena cadena_comprobar) const {
  for (int i = 0; i < cadena_comprobar.getLongitud(); i++) { // Itera sobre la cadena
    char simbolo = cadena_comprobar.getCadenaVector()[i]; // Obtiene el símbolo en la posición i de la cadena
    if (simbolo == '&') {
      continue; // El símbolo & es inmune a la comprobación
    }
    if (alfabeto_set_.find(simbolo) == alfabeto_set_.end()) { // Si el símbolo no está en el alfabeto
      return false;
    }
  }
  return true;
}

/// @brief Comprueba si un símbolo pertenece al alfabeto
/// @param simbolo_comprobar
bool Alfabeto::isSymbol(const char simbolo_comprobar) {
  if (alfabeto_set_.find(simbolo_comprobar) == alfabeto_set_.end()) { // Si el símbolo no está en el alfabeto
    return false;
  }
  return true;
}

/// @brief Comprueba si un símbolo pertenece al alfabeto
/// @param simbolo_comprobar
bool Alfabeto::containsSymbol(const char simbolo_comprobar) {
  if (simbolo_comprobar == '&') {
    return true; // El símbolo & pertenece al alfabeto
  }
  if (alfabeto_set_.find(simbolo_comprobar) == alfabeto_set_.end()) { // Si el símbolo no está en el alfabeto
    return false;
  }
  return true;
}

/// @brief Comprueba si el alfabeto contiene el símbolo epsilon
bool Alfabeto::hasEpsilon() {
  if (alfabeto_set_.find('&') == alfabeto_set_.end()) { // Si el símbolo & no está en el alfabeto
    return false;
  }
  return true;
}