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
* Archivo main.cc: Main File
* Comprueba el funcionamiento del QuickHull y la clase PointSet
* 15/12/2024 - Creación (primera versión) del código
*/

#include "functions.h"

int main(int argc, char* argv[]) {
    using namespace CyA;
    // Leer puntos desde la entrada estándar
    point_vector points;
    ReadPoints(argv[1], points);
    // Crear un conjunto de puntos
    PointSet point_set(points);
    // Calcular la envolvente convexa
    point_set.QuickHull();
    // Escribir los puntos de la envolvente convexa
    point_set.WriteHull(std::cout);
    // Graphviz: neato output.dot -Tpdf -o salida.pdf
    if (argv[2] != nullptr)
        IsDot(argv[2], point_set);
    return 0;
}
