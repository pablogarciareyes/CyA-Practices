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

#ifndef FA_H
#define FA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

#include "Alfabeto.h"
#include "Estado.h"

class Automata {
  public:
    Automata(const std::string& nombre_fichero);
    // Getters
    Alfabeto getAlfabeto() const {return alfabeto_;}
    std::set<Estado> getEstados() const {return estados_;}
    Estado getEstadoInicial() const {return estado_inicial_;}
    std::set<Estado> getEstadosFinales() const {return estados_finales_;}
    std::multimap<std::pair<Estado, char>, Estado> getTransiciones() const {return transiciones_;}
    // Setters
    void setAlfabeto(Alfabeto alfabeto) {alfabeto_ = alfabeto;}
    void setEstados(std::set<Estado> estados) {estados_ = estados;}
    void setEstadoInicial(Estado estado_inicial) {estado_inicial_ = estado_inicial;}
    void setEstadosFinales(std::set<Estado> estados_finales) {estados_finales_ = estados_finales;}
    void setTransiciones(std::multimap<std::pair<Estado, char>, Estado> transiciones) {transiciones_ = transiciones;}
    // Métodos
    void agregarTransicion(Estado origen, char simbolo, Estado destino);
    bool simularAutomata(const Cadena& cadena);
    void writeAutomata(const std::string& nombre_fichero);
    void procesarEpsilonTransiciones(std::set<Estado>& estados_actuales);
    // Modificación
    void imprimirEstadosNoAlcanzablesDesdeArranque();
  private:
    Alfabeto alfabeto_;
    std::set<Estado> estados_;
    Estado estado_inicial_;
    std::set<Estado> estados_finales_;
    std::multimap<std::pair<Estado, char>, Estado> transiciones_;
    int num_estados_;
};

#endif