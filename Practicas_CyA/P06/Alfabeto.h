// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Alfabeto.h: Archivo que contiene la definición de la clase Alfabeto
// Contiene la definición de la clase Alfabeto con sus atributos y métodos
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código
// 20/10/2024 - Implementación de nuevos métodos para su utilización en la práctica 6

#define ALFABETO_H
#ifndef ALFABETO_h

#include "Cadena.h"

#include <iostream>
#include <set>
#include <fstream>

class Alfabeto {
  public:
    // Constructor por defecto
    Alfabeto() = default;
    // Método para obtener el cardinal del Alfabeto
    int getCardinal() {return alfabeto_set_.size();}
    std::set<char> getAlfabeto() {return alfabeto_set_;}
    // Método para escribir el alfabeto en un fichero
    void writeAlfabeto (const std::string& nombre_fichero);
    // Método para insertar símbolo al alfabeto
    void insertSymbol(const char simbolo_insertar);
    // Método para comprobar que una cadena pertenece al alfabeto
    bool perteneceAlfabeto(Cadena cadena_comprobar) const;
    // Método para comprobar que un simbolo pertenece al alfabeto
    bool isSymbol(const char simbolo_comprobar);
    // Método para comprobar si un simbolo pertenece al alfabeto
    bool containsSymbol(const char simbolo_comprobar);
    // Tiene &?
    bool hasEpsilon();
  private:
    std::set<char> alfabeto_set_;    
};

#endif