// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Lenguaje.h: Archivo que contiene la definición de la clase Lenguaje
// Contiene la definición de la clase Lenguaje con sus atributos y métodos
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include "Alfabeto.h"

class Lenguaje {
  public:
    // Constructor por defecto
    Lenguaje() = default;
    //Constructor por parámetros
    Lenguaje(std::set<Cadena> lenguaje_set) : lenguaje_set_(lenguaje_set) {}
    // Método para obtener el set del Alfabeto
    std::set<Cadena> getSet() {return lenguaje_set_;}
    // Método para obtener el cardinal del Alfabeto
    int getCardinal() {return lenguaje_set_.size();}
    // Write lenguaje
    void writeLenguaje (const std::string& nombre_fichero);
    // Sobrecarga de operador de asignación
    Lenguaje& operator=(const Lenguaje& lenguaje);
  private:
    std::set<Cadena> lenguaje_set_;
};

#endif