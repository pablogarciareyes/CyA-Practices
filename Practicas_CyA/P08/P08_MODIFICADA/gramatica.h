// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Gramatica.h: Archivo que contiene la definición de la clase Gramatica
// Contiene la definición de la clase Gramática con sus atributos y métodos
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código
// 05/11/2024 - Implementación de nuevos métodos para su utilización en la práctica 8

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "produccion.h"
#include "alfabeto.h"

#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <iostream>
#include <map>

class Gramatica { 
public:
    Gramatica(const std::string& archivoEntrada);
    Gramatica() = default;
    // Tratar la gramatica con ficheros
    void leerGramatica(const std::string& nombre_fichero_entrada);
    void writeGramatica(const std::string& nombre_fichero);
    // Agregar una producción a la gramática
    void agregarProduccion(const std::string& izq, const std::vector<char>& der);
    void agregarProduccion(const Produccion& produccion);
    // Algoritmo para pasar la gramática a la forma normal de Chomsky
    Gramatica algoritmoFormaNormalChomsky();
    // Comprobar producciones y operar sobre ellas
    bool existeProduccion(std::vector<char> produccion);
    void eliminarProduccion(Produccion produccion);
    // Setters
    void setSimboloArranque(std::string simbolo_arranque) {simbolo_arranque_ = simbolo_arranque;}
    void setDerivacion(std::string no_terminal);
    // Getters
    Produccion getProduccion(std::vector<char> produccion);
    std::vector<Produccion> getProducciones() {return producciones_;}
    // Funciones para comprobar si la gramática está simplificada antes de aplicar el algoritmo
    bool comprobarProduccionesUnitarias();
    bool comprobarProduccionesVacias();
    bool esLinealPorLaDerecha() const;
private:
    // G ≡ (V,Σ,S,P)
    Alfabeto terminales_; // Alfabeto de terminales (Σ)
    std::set<std::string> no_terminales_; // Conjunto de no terminales (V)
    std::string simbolo_arranque_; // Símbolo de arranque (S)
    std::vector<Produccion> producciones_; // Conjunto de reglas de producciones (P)
};

#endif