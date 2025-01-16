// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Cadena.h: Archivo que contiene la definición de la clase Cadena
// Contiene la definición de la clase Cadena con sus atributos y métodos
// Referencias:
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>

class Cadena {
  public:
    // Constructor por parámetros
    Cadena(std::vector<char> cadena_vector) : cadena_vector_(cadena_vector) {}
    // Constructor por defecto
    Cadena() = default;
    // Constructor con el nombre de un fichero
    Cadena(const std::string& nombre_fichero);
    // Método para obtener la longitud
    int getLongitud() const {return cadena_vector_.size();} 
    // Lee la cadena desde un archiv
    void readCadena(const std::string& nombre_fichero);
    // Método para obtener el vector de la cadena
    std::vector<char> getCadenaVector() const {return cadena_vector_;}
    // Método para escribir la longitud en un fichero
    void writeLongitud (const std::string& nombre_fichero);
    // Insertar símbolo
    void insertSymbol(const char simbolo_insertar);
    // Método para obtener la cadena inversa
    Cadena getInversa();
    // Método para imprimir la cadena en un archivo
    void writeCadena(const std::string& nombre_fichero);
    // Método para comprobar si una cadena es vacía
    bool esVacia();
    // Método para obtener los prefijos de una cadena e introducirlo a un set
    std::set<Cadena> obtenerPrefijos();
    // Método para obtener los sufijos de una cadena e introducirlo a un set
    std::set<Cadena> obtenerSufijos();
    // MODIFICACIÓN: Obtener la potencia de una cadena
    Cadena obtenerPotencia(const Cadena& cadena, int potencia) const;
    // Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
    // Sobrecarga del operador < para comparar cadenas
    bool operator<(const Cadena& cadena) const;
    // Sobrecarga del operador de comparación con un simbolo
    bool operator==(const char* simbolo) const;
  private:
    std::vector<char> cadena_vector_;    
};

#endif