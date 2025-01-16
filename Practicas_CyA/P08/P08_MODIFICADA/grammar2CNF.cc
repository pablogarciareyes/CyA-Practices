// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo grammar2CNF.cc: Main del programa
// Contiene la implementación del main del programa
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código
// 05/11/2024 - Implementación del algoritmo para su utilización en la práctica 8
// Funcionamiento: ./p08_grammar2CNF input.gra output.gra 

#include <iostream>
#include "funciones.h"

int main(int argc, char* argv[]) {
    Usage(argc, argv);
    Gramatica gramatica(argv[1]);
    AplicarAlgoritmo(gramatica, argv[2]);
    return 0;
}