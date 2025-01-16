// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Produccion.cc: Contiene la implementación de los métodos de la clase Produccion
// Entre ellos se encuentra el constructor, los métodos getNoTerminal, getProd y replaceSymbol
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código

#include "produccion.h"

/// @brief Constructor de la clase Produccion
/// @param no_terminal 
/// @param produccion 
Produccion::Produccion(const std::string &no_terminal, const std::vector<char> &produccion)
{
  no_terminal_ = no_terminal;
  for (const auto &simbolo : produccion)
  {
    produccion_.push_back(simbolo);
  }
}

/// @brief Devuelve el no terminal de la producción
/// @return no_terminal_
std::string Produccion::getNoTerminal() const
{
  return no_terminal_;
}

/// @brief Devuelve la producción
/// @return produccion_
std::vector<char> Produccion::getProd() const
{
  return produccion_;
}

/// @brief Reemplaza un símbolo de la producción
/// @param simbolo
void Produccion::replaceSymbol(char simbolo, char produccion)
{
  for (int i = 0; i < produccion_.size(); i++)
  {
    if (produccion_[i] == simbolo)
    {
      produccion_[i] = produccion;
    }
  }
}
