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

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

class Estado {
  public:
    Estado() : id(-1), final(false) {}  // Constructor por defecto que inicializa los valores
    Estado(int id) : id(id), final(false) {}  // Inicializa solo el id
    Estado(int id, bool es_final) : id(id), final(es_final) {}  // Inicializa id y final

    int getId() const;
    bool esFinal() const;
    void setFinal(bool es_final);

    bool operator<(const Estado& estado) const;
    bool operator==(const Estado& estado) const;

  private:
    int id;
    bool final;
};

#endif