/* *
* Universidad de La Laguna
* Escuela Superior de Ingenieria y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 12: Algoritmos Divide y venceras
* Autor: Pablo García de los Reyes
* Correo: alu0101630045@ull.edu.es
* Fecha: 17/12/2024
* Archivo Functions.h: Header File
* Funciones para el testeo
* 15/12/2024 - Creación (primera versión) del código
*/

#pragma once
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

#include "PointSet.h"

void Usage(int argc, char *argv[]);
void ReadPoints(std::string filename, CyA::point_vector& points);
void IsDot(char* option, CyA::PointSet &ps);