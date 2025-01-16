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

#include "Lenguaje.h"

/// @brief Escribe la longitud de la cadena en un fichero
/// @param nombre_fichero 
void Cadena::writeLongitud(const std::string& nombre_fichero) {
  std::ofstream file(nombre_fichero, std::ios::app);
  if (file.is_open()) {
    if (cadena_vector_[0] == '&') { // Si la cadena es vacía imprimirá la longitud 0
      file << 0 << std::endl;
    } 
    else {
    file << cadena_vector_.size() << std::endl;
    file.close();
    }
  }
}

/// @brief Insertar un simbolo en la cadena
/// @param simbolo_insertar 
void Cadena::insertSymbol(const char simbolo_insertar) {
  cadena_vector_.push_back(simbolo_insertar);
}

/// @brief Escribir la cadena inversa en un fichero
/// @param nombre_fichero 
Cadena Cadena::getInversa() {
  Cadena cadena_inversa;
  for(int i = cadena_vector_.size() - 1; i >= 0; i--) {
    cadena_inversa.insertSymbol(cadena_vector_[i]);
  }
  return cadena_inversa;
}

/// @brief Escribir la cadena en un fichero
/// @param nombre_fichero
void Cadena::writeCadena(const std::string& nombre_fichero) {
  std::ofstream file(nombre_fichero, std::ios::app);
  if (file.is_open()) {
    file << *this << std::endl;
    file.close();
  }
}

/// @brief Comprobar si una cadena es vacía
/// @return true si la cadena es vacía, false en caso contrario
bool Cadena::esVacia() {
  return cadena_vector_[0] == '&';
}

/// @brief Obtiene los prefijos de una cadena
/// @return prefijos
std::set<Cadena> Cadena::obtenerPrefijos() {
  std::set<Cadena> prefijos;
  Cadena prefijo;
  for(int i = 0; i < cadena_vector_.size(); i++) {
    prefijo.insertSymbol(cadena_vector_[i]);
    prefijos.insert(prefijo);
  }
  return prefijos;
}

/// @brief Obtiene los sufijos de una cadena
/// @return Conjunto de sufijos de la cadena
std::set<Cadena> Cadena::obtenerSufijos() {
  std::set<Cadena> sufijos;
  for (int i = 0; i <= cadena_vector_.size(); ++i) {
    // Crear un sufijo desde la posición i hasta el final
    std::vector<char> subcadena(cadena_vector_.begin() + i, cadena_vector_.end());
    Cadena sufijo(subcadena);  // Crear un objeto Cadena a partir de la subcadena
    sufijos.insert(sufijo);    // Insertar el sufijo en el conjunto de sufijos
  }
  return sufijos;
}

/// MODIFICACIÓN
/// @brief Obtiene la potencia de una cadena
/// @param cadena
/// @param potencia
/// @return cadena_potencia
Cadena Cadena::obtenerPotencia(const Cadena& cadena, int potencia) const {
  Cadena resultado;
  if (potencia == 0) {
    return resultado; // La potencia de 0 es la cadena vacía
  }
  for (int i = 0; i < potencia; ++i) {
    resultado.cadena_vector_.insert(resultado.cadena_vector_.end(), cadena.cadena_vector_.begin(), cadena.cadena_vector_.end());
  }
  return resultado;
}

/// @brief Sobrecarga del operador de salida
/// @param os
/// @param cadena
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  for(int i = 0; i < cadena.cadena_vector_.size(); i++) {
    os << cadena.cadena_vector_[i];
  }
  return os;
}

/// @brief Sobrecarga del operador < para comparar cadenas
/// @param cadena
bool Cadena::operator<(const Cadena& cadena) const {
  return cadena_vector_.size() < cadena.cadena_vector_.size();
}

/// @brief Sobrecarga del operador == para comparar cadenas con un simbolo
/// @param simbolo
bool Cadena::operator==(const char* simbolo) const {
  return cadena_vector_[0] == simbolo[0];
}