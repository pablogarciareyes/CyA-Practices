// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo Functions.h: Archivo que contiene la definición de las funciones
// Contiene la definición de las funciones necesarias para la lectura de ficheros y comprobación de argumentos
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Lenguaje.h"

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


void read_fichero(const std::string& nombre_fichero, std::vector<Cadena>& cadenas_introducidas, std::vector<Alfabeto>& alfabetos_introducidos);
void Usage(int argc, char *argv[]);
void UsageOption6(int argc, char *argv[]);




#endif