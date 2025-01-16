// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Lenguaje.cc: Archivo que contiene la implementación de los métodos de la clase Lenguaje
// Realiza la implementación de los métodos writeLenguaje y la sobrecarga del operador de asignación de la clase Lenguaje
// Referencias:
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#include "Lenguaje.h"

/// @brief Escribe el lenguaje en un fichero teniendo en cuenta la funcion contiene_cadena_vacia para imprimir o no la cadena vacía
/// @param nombre_fichero 
void Lenguaje::writeLenguaje(const std::string& nombre_fichero) {
  std::ofstream file(nombre_fichero, std::ios::app);
  if (file.is_open()) {
    file << "{&";
    for (auto it = lenguaje_set_.begin(); it != lenguaje_set_.end(); ++it) { // Bucle iterador sobre el set (por definición)
      if (!it->getCadenaVector().empty() && it->getCadenaVector()[0] != '&') { // Si la cadena no es vacía y no es la cadena vacía seguirá imprimiendo el resto de cadenas
        file << " , " << *it; 
      }
    }
    file << "}" << std::endl;
    file.close();
  }
}

/// @brief Sobrecarga del operador de asignación
/// @param lenguaje
Lenguaje& Lenguaje::operator=(const Lenguaje& lenguaje) {
  lenguaje_set_ = lenguaje.lenguaje_set_;
  return *this;
}