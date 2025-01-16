// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingniiería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 23/09/2024
// Archivo main.cc: Archivo que contiene la función principal del programa
// Enlaces de interés 
// Historial de revisiones
// 17/09/2024 - Creacion (primera versión) del código

#include "Functions.h"

int main(int argc, char* argv[]) {
  std::vector<Cadena> cadenas;
  std::vector<Alfabeto> alfabetos;
  Cadena cadena_potencia;
  read_fichero(argv[1], cadenas, alfabetos);

  switch(std::stoi(argv[3])) {
    case 1: // Imprime el alfabeto
      Usage(argc, argv);
      for (int i = 0; i < alfabetos.size(); i++) {
        alfabetos[i].writeAlfabeto(argv[2]);
      }
      break;
    case 2: // Imprime la longitud de la cadena
      Usage(argc, argv);
      for (int i = 0; i < cadenas.size(); i++) {
        cadenas[i].writeLongitud(argv[2]);
      }
      break;
    case 3: // Imprime la inversa de la cadena
      Usage(argc, argv);
      for(int i = 0; i < cadenas.size(); i++) {
        Cadena inversa;
        inversa = cadenas[i].getInversa();
        inversa.writeCadena(argv[2]);
      }
      break;
    case 4: // Imprime los prefijos de la cadena
      Usage(argc, argv);
      for(int i = 0; i < cadenas.size(); i++) {
        Lenguaje lenguaje;
        lenguaje = cadenas[i].obtenerPrefijos();
        lenguaje.writeLenguaje(argv[2]);
      }
      break;
    case 5: // Imprime los sufijos de la cadena
      Usage(argc, argv);
      for(int i = 0; i < cadenas.size(); i++) {
        Lenguaje lenguaje;
        lenguaje = cadenas[i].obtenerSufijos();
        lenguaje.writeLenguaje(argv[2]);
      }
      break;
    case 6: // Imprime la potencia de una cadena
      UsageOption6(argc, argv);
      for (int i = 0; i < cadenas.size(); i++) {
        cadena_potencia = cadenas[i];
        cadena_potencia.obtenerPotencia(cadena_potencia, std::stoi(argv[4])).writeCadena(argv[2]); 
    }
    break;
    default:
      std::cout << "Operación no válida" << std::endl;
      break;
  }

  return 0;
}