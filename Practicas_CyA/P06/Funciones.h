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

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>

#include "Automata.h"

void Usage(int argc, char* argv[]);
void leer_cadenas(const std::string& nombre_fichero, std::vector<Cadena>& cadenas);
void comprobar_aceptacion(Automata& automata, const std::vector<Cadena>& cadenas);

#endif