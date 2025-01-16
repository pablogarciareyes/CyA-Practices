// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Produccion.h: Archivo que contiene la implementación de las funciones necesarias para la ejecución del programa
// Contiene la declaración de las funciones necesarias para la ejecución del programa
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <iostream>
#include <string>
#include <vector>

class Produccion {
  public:
    // Constructor por defecto
    Produccion() = default;
    // Constructor con parámetros
    Produccion(const std::string& no_terminal, const std::vector<char>& produccion);
    // Getters
    std::string getNoTerminal() const;
    std::vector<char> getProd() const;
    // Reemplaza un símbolo de la producción
    void replaceSymbol(char simbolo, char produccion);
  private:
    std::string no_terminal_; // No terminal de la producción
    std::vector<char> produccion_; // Producción del no terminal
};

#endif