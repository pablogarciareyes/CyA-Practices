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

#include "Estado.h"

/// @brief Getter del atributo id
/// @return id
int Estado::getId() const {
  return id;
}

/// @brief Getter del atributo final
/// @return final
bool Estado::esFinal() const {
  return final;
}

/// @brief Setter del atributo final 
/// @param es_final 
void Estado::setFinal(bool es_final) {
  final = es_final;
}

/// @brief Sobrecarga del operador de comparación 
/// @param estado 
/// @return id < estado.getId()
bool Estado::operator<(const Estado& estado) const {
  return id < estado.getId();
}

/// @brief Sobrecarga del operador de comparación 
/// @param estado 
/// @return id == estado.getId()
bool Estado::operator==(const Estado& estado) const {
  return id == estado.getId();
}