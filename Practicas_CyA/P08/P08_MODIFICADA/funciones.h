// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Funciones.h: Archivo que contiene la implementación de las funciones necesarias para la ejecución del programa
// Contiene la declaración de las funciones necesarias para la ejecución del programa
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "gramatica.h"

void Usage(int argc, char* argv[]);
void ComprobarGramatica(Gramatica gramatica_usuario);
void AplicarAlgoritmo(Gramatica gramatica_usuario, std::string fichero_salida);

#endif