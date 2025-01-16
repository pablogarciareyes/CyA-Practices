// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas
// Autor: Pablo García de los Reyes
// Correo: alu0101630045@ull.edu.es
// Fecha: 05/11/2024
// Archivo Gramatica.cc: Archivo que contiene la implementación de los métodos de la clase Gramatica
// Contiene la implementación de los métodos de la clase Gramática, entre ellos el algoritmo para pasar una gramática a la forma normal de Chomsky
// Enlaces de interés 
// Historial de revisiones
// 03/11/2024 - Creación (primera versión) del código
// 05/11/2024 - Implementación del algoritmo para su utilización en la práctica 8

#include "gramatica.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

// Constructor que llama a leerGramatica
Gramatica::Gramatica(const std::string &archivoEntrada)
{
    leerGramatica(archivoEntrada);
}

/// @brief Lee la gramática de un archivo de texto
/// @param archivoEntrada
void Gramatica::leerGramatica(const std::string &nombre_fichero_entrada)
{
  std::ifstream archivo_entrada(nombre_fichero_entrada);
  if (!archivo_entrada.is_open())
  {
    std::cerr << "No se pudo abrir el archivo " << nombre_fichero_entrada << std::endl;
    return;
  }
  int num_terminales, num_noterminales, num_producciones;
  char simbolo_terminal;
  std::string simbolo_noterminal, produccion;
  archivo_entrada >> num_terminales;
  for (int i = 0; i < num_terminales; i++)
  {
    archivo_entrada >> simbolo_terminal;
    terminales_.insertSymbol(simbolo_terminal);
  }
  archivo_entrada >> num_noterminales;
  for (int i = 0; i < num_noterminales; i++)
  {
    archivo_entrada >> simbolo_noterminal;
    if (simbolo_arranque_ == "") {
      simbolo_arranque_ = simbolo_noterminal;
    }
    no_terminales_.insert(simbolo_noterminal);
    if (i == 0)
      simbolo_arranque_ = simbolo_noterminal;
  }
  archivo_entrada >> num_producciones;
  for (int i = 0; i < num_producciones; i++)
  {
    archivo_entrada >> simbolo_noterminal >> produccion;
    std::vector<char> producciones;
    for (const auto &simbolo : produccion)
    {
      // Comprobar si el símbolo es un terminal o no terminal
      if ((terminales_.isSymbol(simbolo) || no_terminales_.count(std::string(1, simbolo))) || simbolo == '&')
        producciones.push_back(simbolo);
      else {
        std::cerr << "El símbolo " << simbolo << " no es un terminal ni un no terminal" << std::endl;
      }
    }
    agregarProduccion(simbolo_noterminal, producciones);
  }
  archivo_entrada.close();
}

/// @brief Agrega una producción a la gramática
/// @param no_terminal
/// @param produccion
void Gramatica::agregarProduccion(const std::string &no_terminal, const std::vector<char> &produccion)
{
  Produccion nuevaProduccion(no_terminal, produccion);
  producciones_.push_back(nuevaProduccion);
}

/// @brief Agrega una producción a la gramática
/// @param produccion
void Gramatica::agregarProduccion(const Produccion &produccion)
{
  producciones_.push_back(produccion);
}

/// @brief Escribir Gramatica en un fichero en el formato esperado
/// @param nombre_fichero
void Gramatica::writeGramatica(const std::string &nombre_fichero_salida)
{
  std::ofstream archivo_salida(nombre_fichero_salida);
  if (!archivo_salida.is_open())
  {
    std::cerr << "No se pudo abrir el archivo " << nombre_fichero_salida << std::endl;
    return;
  }
  // Escribir el número de terminales
  archivo_salida << terminales_.getCardinal() << std::endl;
  // Escribir cada terminal en una línea separada
  for (const auto &simbolo : terminales_.getAlfabeto())
  {
    archivo_salida << simbolo << std::endl;
  }
  // Escribir el número de no terminales
  archivo_salida << no_terminales_.size() << std::endl;
  // Imprimir el símbolo de arranque en la primera línea
  archivo_salida << simbolo_arranque_ << std::endl;
  // Escribir cada no terminal en una línea separada excepto el símbolo de arranque
  for (const auto &no_terminal : no_terminales_)
  {
    if (no_terminal != simbolo_arranque_)
    {
      archivo_salida << no_terminal << std::endl;
    }
  }
  // Escribir el número total de producciones
  archivo_salida << producciones_.size() << std::endl;
  // Ordenar y agrupar las producciones: imprimir las producciones de cada no terminal
  // Empezar con el símbolo de arranque 'S'
  if (no_terminales_.count(simbolo_arranque_)) {
    for (const auto &produccion : producciones_) {
      if (produccion.getNoTerminal() == simbolo_arranque_) {
        archivo_salida << produccion.getNoTerminal() << " ";
        for (const auto &simbolo : produccion.getProd()) {
          archivo_salida << simbolo;
        }
        archivo_salida << std::endl;
      }
    }
  }
  // Imprimir producciones de los demás no terminales, en orden alfabético
  for (const auto &no_terminal : no_terminales_) {
    if (no_terminal != simbolo_arranque_) {
      for (const auto &produccion : producciones_) {
        if (produccion.getNoTerminal() == no_terminal) {
          archivo_salida << produccion.getNoTerminal() << " ";
          for (const auto &simbolo : produccion.getProd()) {
            archivo_salida << simbolo;
          }
          archivo_salida << std::endl;
        }
      }
    }
  }
  archivo_salida.close();
}

/// @brief Algoritmo para pasar una gramática a la forma normal de Chomsky
/// @return gramatica_chomsky
Gramatica Gramatica::algoritmoFormaNormalChomsky() {
    Gramatica gramatica_chomsky;
    std::map<char, std::string> terminal_contenido_noterminal;
    char nuevo_no_terminal = 'A';
    gramatica_chomsky.setSimboloArranque(simbolo_arranque_);
    // Añadir terminales y no terminales a la gramática en Forma Normal de Chomsky
    for (char terminal : terminales_.getAlfabeto()) {
        gramatica_chomsky.terminales_.insertSymbol(terminal);
    }
    for (std::string no_terminal : no_terminales_) {
        gramatica_chomsky.no_terminales_.insert(no_terminal);
    }
    // Paso 1: Reemplazo de terminales solo en producciones de longitud >= 2
    for (Produccion& produccion_dummy : getProducciones()) {
        std::vector<char> nueva_produccion;
        bool modificada = false;
        if (produccion_dummy.getProd().size() >= 2) {  // Solo reemplazar si la producción tiene longitud > 1
            for (char simbolo : produccion_dummy.getProd()) {
                // Si el símbolo es un terminal
                if (terminales_.isSymbol(simbolo)) {
                    // Si el terminal no tiene un no terminal equivalente, crearlo
                    if (terminal_contenido_noterminal.find(simbolo) == terminal_contenido_noterminal.end()) {
                        std::string no_terminal_nuevo_str(1, nuevo_no_terminal);
                        terminal_contenido_noterminal[simbolo] = no_terminal_nuevo_str;
                        // Crear producción unitaria para el nuevo no terminal
                        std::vector<char> produccion_unitaria = {simbolo};
                        Produccion produccion_nueva(no_terminal_nuevo_str, produccion_unitaria);
                        gramatica_chomsky.agregarProduccion(produccion_nueva);
                        gramatica_chomsky.no_terminales_.insert(no_terminal_nuevo_str);
                        nuevo_no_terminal++;
                    }
                    // Reemplazar el terminal por el no terminal en la producción actual
                    nueva_produccion.push_back(terminal_contenido_noterminal[simbolo][0]);
                    modificada = true;
                } else {
                    // Si es un no terminal, añadirlo tal cual
                    nueva_produccion.push_back(simbolo);
                }
            }
            // Si se modificó la producción original, añadir la versión modificada
            if (modificada) {
                Produccion nueva_produccion_dummy(produccion_dummy.getNoTerminal(), nueva_produccion);
                gramatica_chomsky.agregarProduccion(nueva_produccion_dummy);
            } else {
                gramatica_chomsky.agregarProduccion(produccion_dummy);
            }
        } 
        else {
            // Si la producción es de longitud 1 (producción unitaria), añadirla tal cual
            gramatica_chomsky.agregarProduccion(produccion_dummy);
        }
    }
    // Paso 2: Reemplazo de producciones de longitud >= 3 por no terminales
    for (Produccion& produccion : gramatica_chomsky.getProducciones()) {
        if (produccion.getProd().size() >= 3) {
            std::vector<char> simbolos = produccion.getProd();
            std::string no_terminal_inicial = produccion.getNoTerminal();
            // Generar nuevos no terminales para dividir la producción en binarias
            std::vector<std::string> nuevos_no_terminales;
            for (size_t i = 0; i < simbolos.size() - 2; i++) {
                nuevos_no_terminales.push_back(std::string(1, nuevo_no_terminal++));
            }
            // Crear y agregar las nuevas producciones binarias
            gramatica_chomsky.eliminarProduccion(produccion);  // Eliminar la producción original           
            // Primera producción: A -> B D1
            std::vector<char> prod_1 = {simbolos[0], nuevos_no_terminales[0][0]};
            Produccion primera_produccion(no_terminal_inicial, prod_1);
            gramatica_chomsky.agregarProduccion(primera_produccion);           
            // Producciones intermedias: Di -> Bi+1 Di+1
            for (size_t i = 0; i < nuevos_no_terminales.size() - 1; i++) {
                std::vector<char> prod_intermedia = {simbolos[i + 1], nuevos_no_terminales[i + 1][0]};
                Produccion produccion_intermedia(nuevos_no_terminales[i], prod_intermedia);
                gramatica_chomsky.agregarProduccion(produccion_intermedia);
            }           
            // Última producción: Dm-2 -> Bm-1 Bm
            std::vector<char> prod_final = {simbolos[simbolos.size() - 2], simbolos[simbolos.size() - 1]};
            Produccion produccion_final(nuevos_no_terminales.back(), prod_final);
            gramatica_chomsky.agregarProduccion(produccion_final);
            // Añadir los nuevos no terminales a la gramática
            for (const std::string& no_terminal : nuevos_no_terminales) {
                gramatica_chomsky.no_terminales_.insert(no_terminal);
            }
        }
    }
    return gramatica_chomsky;
}

/// @brief Elimina una producción de la gramática
/// @param produccion
void Gramatica::eliminarProduccion(Produccion produccion)
{
  for (auto it = producciones_.begin(); it != producciones_.end(); it++)
  {
    if (it->getProd() == produccion.getProd())
    {
      producciones_.erase(it);
      break;
    }
  }
}

/// @brief Obtiene una producción de la gramática
/// @param produccion 
/// @return Produccion
Produccion Gramatica::getProduccion(std::vector<char> produccion)
{
  for (const auto &prod : producciones_)
  {
    if (prod.getProd() == produccion)
      return prod;
  }
  return Produccion();
}

/// @brief Comprueba si una producción existe en la gramática
/// @param produccion 
/// @return true || false
bool Gramatica::existeProduccion(std::vector<char> produccion)
{
  for (const auto &prod : producciones_)
  {
    if (prod.getProd() == produccion)
      return true;
  }
  return false;
}

/// @brief Comprueba si la gramática contiene producciones unitarias
/// @return true || false
bool Gramatica::comprobarProduccionesUnitarias()
{
  for (const auto &produccion : producciones_)
  {
    if (produccion.getProd().size() == 1 && no_terminales_.find(std::string(1, produccion.getProd()[0])) != no_terminales_.end())
      return true;
  }
  return false;
}

/// @brief Comprueba si la gramática contiene producciones vacías
/// @return true || false
bool Gramatica::comprobarProduccionesVacias()
{
  for (const auto &produccion : producciones_)
  {
    for (const auto &simbolo : produccion.getProd())
    {
      if (simbolo == '&' && produccion.getNoTerminal() != simbolo_arranque_)
        return true;
    }
  }
  return false;
}