/**
 * @file Automata.cc
 * @brief Archivo que contiene la implementación de la clase Automata.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Autómatas y lenguajes formales
 * Autor: Pablo García de los Reyes
 * Correo: alu0101630045@ull.edu.es
 * Fecha: 20/10/2024
 * 
 * Enlaces de interés:
 * - https://es.wikipedia.org/wiki/Autómata_finito
 * 
 * Historial de revisiones:
 * - 18/10/2024 - Creación (primera versión) del código
 */

#include "Automata.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>

/**
 * @brief Agrega una transición al autómata.
 * 
 * @param origen Estado de origen.
 * @param simbolo Símbolo de la transición.
 * @param destino Estado de destino.
 */
void Automata::agregarTransicion(Estado origen, char simbolo, Estado destino) {
  transiciones_.insert(std::pair<std::pair<Estado, char>, Estado>(std::pair<Estado, char>(origen, simbolo), destino));
}

/**
 * @brief Constructor de la clase Automata. Lee la definición del autómata desde un archivo.
 * 
 * @param nombre_fichero Nombre del archivo que contiene la definición del autómata.
 */
Automata::Automata(const std::string& nombre_fichero) {
  std::ifstream file(nombre_fichero);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo: " << nombre_fichero << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;

  // Leer símbolos del alfabeto
  std::getline(file, line);
  std::istringstream iss(line);
  char simbolo;
  while (iss >> simbolo) {
    alfabeto_.insertSymbol(simbolo);  // Almacenar cada símbolo en el alfabeto
  }

  // Comprobación de que el alfabeto no está vacío
  if (alfabeto_.getCardinal() == 0) {
    std::cerr << "El alfabeto no puede estar vacío." << std::endl;
    exit(EXIT_FAILURE);
  }
  // Comprobación de que el alfabeto no contiene el símbolo epsilon
  if (alfabeto_.hasEpsilon()) {
    std::cerr << "El alfabeto no debe contener el símbolo epsilon (&)." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Leer número total de estados
  std::getline(file, line);
  std::istringstream(line) >> num_estados_;

  // Leer estado de arranque
  std::getline(file, line);
  std::istringstream iss_estado_inicial(line);
  int id_estado_inicial;
  iss_estado_inicial >> id_estado_inicial;
  estado_inicial_ = Estado(id_estado_inicial);  // Crear el estado inicial

  // Comprobación de que solo hay un estado inicial
  int extra;
  if (iss_estado_inicial >> extra) {
    std::cerr << "Debe haber un único estado inicial en la línea correspondiente." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Comprobación de que el estado inicial está dentro del rango permitido
  if (id_estado_inicial < 0 || id_estado_inicial >= num_estados_) {
    std::cerr << "El estado inicial debe pertenecer al conjunto de Estados del Automata." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Leer los estados y sus transiciones
  std::set<int> estados_leidos;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int id_estado;
    iss >> id_estado;

    Estado estado(id_estado);  // Crear un nuevo estado con el identificador

    // Leer si es un estado de aceptación (1 para aceptación, 0 para no aceptación)
    int es_aceptacion;
    iss >> es_aceptacion;
    if (es_aceptacion == 1) {
      estado.setFinal(true);  // Marcar el estado como de aceptación
      estados_finales_.insert(estado);
    }

    // Leer el número de transiciones del estado
    int num_transiciones;
    iss >> num_transiciones;

    // Leer cada transición (símbolo de entrada y el estado destino)
    for (int i = 0; i < num_transiciones; ++i) {
      char simbolo_transicion;
      int estado_destino_id;
      iss >> simbolo_transicion >> estado_destino_id;

      // Comprobación de que el símbolo de la transición pertenece al alfabeto
      if (!alfabeto_.containsSymbol(simbolo_transicion)) {
        std::cerr << "El símbolo " << simbolo_transicion << " de la transición: " << id_estado  << " -> " << estado_destino_id << " no pertenece al alfabeto." << std::endl;
        exit(EXIT_FAILURE);
      }

      // Crear el estado destino
      Estado estado_destino(estado_destino_id);

      // Comprobación de que el estado destino está dentro del rango permitido
      if (estado_destino_id < 0 || estado_destino_id >= num_estados_) {
        std::cerr << "El estado destino " << estado_destino_id << " está fuera del rango de estados permitidos." << std::endl;
        exit(EXIT_FAILURE);
      }
      
      // Insertar la transición
      agregarTransicion(estado, simbolo_transicion, estado_destino);
    }

    // Añadir el estado al conjunto de estados
    estados_.insert(estado);
    estados_leidos.insert(id_estado);
  }

  // Comprobación de que hay una línea en el fichero por cada estado del autómata
  if (estados_leidos.size() != num_estados_) {
    std::cerr << "El fichero no contiene una línea por cada estado del autómata." << std::endl;
    exit(EXIT_FAILURE);
  }

  file.close();
}

/**
 * @brief Escribe la definición del autómata en un archivo.
 * 
 * @param nombre_fichero Nombre del archivo donde se escribirá la definición del autómata.
 */
void Automata::writeAutomata(const std::string& nombre_fichero) {
  std::ofstream file(nombre_fichero, std::ios::app);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo: " << nombre_fichero << std::endl;
    exit(EXIT_FAILURE);
  }

  // Escribir alfabeto
  alfabeto_.writeAlfabeto(nombre_fichero);
  // Escribir número de estados
  file << num_estados_ << std::endl;
  // Escribir estado inicial
  file << estado_inicial_.getId() << std::endl;
  // Escribir estados finales
  for (Estado estado : estados_finales_) {
    file << estado.getId() << " ";
  }
  // Escribir transiciones
  for (Estado estado : estados_) {
    file << std::endl;
    file << estado.getId() << " ";
    if (estado.esFinal()) {
      file << 1 << " ";
    } else {
      file << 0 << " ";
    }
    file << transiciones_.count(std::pair<Estado, char>(estado, ' ')) << " ";
    for (auto it = transiciones_.equal_range(std::pair<Estado, char>(estado, ' ')); it.first != it.second; ++it.first) {
      file << it.first->first.second << " " << it.first->second.getId() << " ";
    }
  }

  file.close();
}
/**
 * @brief Simula el autómata con una cadena de entrada.
 * 
 * @param cadena Cadena de entrada a ser procesada por el autómata.
 * @return true Si la cadena es aceptada por el autómata.
 * @return false Si la cadena es rechazada por el autómata.
 */

bool Automata::simularAutomata(const Cadena& cadena) {
  // Conjunto de estados actuales (puede haber varios en un NFA)
  std::set<Estado> estados_actuales;
  // Inicialmente, agregamos el estado inicial
  estados_actuales.insert(estado_inicial_);
  // Explorar las transiciones epsilon desde el estado inicial
  procesarEpsilonTransiciones(estados_actuales);

  // Procesar cada símbolo de la cadena
  for (char simbolo : cadena.getCadenaVector()) {
    // Conjunto de nuevos estados a los que podemos transitar
    std::set<Estado> nuevos_estados;



    // Para cada estado actual, buscar las transiciones con el símbolo actual
    for (const Estado& estado : estados_actuales) {
      auto range = transiciones_.equal_range(std::make_pair(estado, simbolo));
      // Agregar todos los estados destino posibles por ese símbolo
      for (auto it = range.first; it != range.second; ++it) {
        nuevos_estados.insert(it->second);
      }
    }

    // Si no hay nuevos estados, la cadena es rechazada
    if (nuevos_estados.empty()) {
      return false;
    }

    // Reemplazar los estados actuales por los nuevos
    estados_actuales = nuevos_estados;

    // Procesar las transiciones epsilon desde los nuevos estados
    procesarEpsilonTransiciones(estados_actuales);
  }
  // Al final de la cadena, verificamos si alguno de los estados actuales es un estado final
  for (const Estado& estado : estados_actuales) {
    if (estados_finales_.find(estado) != estados_finales_.end()) {
      return true;  // La cadena es aceptada
    }
  }
  // Si ningún estado actual es de aceptación, la cadena es rechazada
  return false;
}

/**
 * @brief Procesa las transiciones epsilon (&) desde los estados actuales.
 * 
 * @param estados_actuales Conjunto de estados actuales.
 */
void Automata::procesarEpsilonTransiciones(std::set<Estado>& estados_actuales) {
  bool nuevos_estados_agregados;
  do {
    nuevos_estados_agregados = false;
    std::set<Estado> nuevos_estados;
    // Buscar todas las transiciones epsilon (&) desde cada estado actual
    for (const Estado& estado : estados_actuales) {
      auto range = transiciones_.equal_range(std::make_pair(estado, '&'));
      // Agregar todos los estados destino posibles por epsilon
      for (auto it = range.first; it != range.second; ++it) {
        const Estado& estado_destino = it->second;
        // Si el estado destino aún no está en el conjunto de estados actuales, lo agregamos
        if (estados_actuales.find(estado_destino) == estados_actuales.end()) {
          nuevos_estados.insert(estado_destino);
          nuevos_estados_agregados = true;
        }
      }
    }
    // Unir los nuevos estados al conjunto de estados actuales
    estados_actuales.insert(nuevos_estados.begin(), nuevos_estados.end());
  } while (nuevos_estados_agregados);
}

/**
 * @brief Imprime los estados no alcanzables desde el de arranque
 * 
 * @return No return as a void function.
 */
void Automata::imprimirEstadosNoAlcanzablesDesdeArranque() {
  // Vector que indica si un estado es alcanzable (inicialmente todos no alcanzables)
  std::vector<bool> alcanzables(num_estados_, false);
  // Marcar el estado inicial como alcanzable
  alcanzables[estado_inicial_.getId()] = true;
  bool hubo_cambios = true;
  // Iterar hasta que no haya más cambios en los estados alcanzables
  while (hubo_cambios) {
    hubo_cambios = false;
    // Revisamos todos los estados
    for (const Estado& estado : estados_) {
      if (alcanzables[estado.getId()]) { // Si este estado es alcanzable
        // Revisar todas las transiciones desde este estado
        for (char simbolo : alfabeto_.getAlfabeto()) { // MODIFICAR getAlfabeto para poder iterar
          auto range = transiciones_.equal_range(std::make_pair(estado, simbolo));
          for (auto it = range.first; it != range.second; ++it) {
            int estado_destino_id = it->second.getId();
            if (!alcanzables[estado_destino_id]) { // Si el estado destino no era alcanzable
              alcanzables[estado_destino_id] = true;  // Marcarlo como alcanzable
              hubo_cambios = true;  // Hubo un cambio, por lo tanto, continuamos iterando
            }
          }
        }
        // Procesar transiciones epsilon (&)
        auto range_epsilon = transiciones_.equal_range(std::make_pair(estado, '&')); // Funcion procesarEpsilon no sirve porque queremos procesar un solo estado
        for (auto it = range_epsilon.first; it != range_epsilon.second; ++it) {
          int estado_destino_id = it->second.getId();
          if (!alcanzables[estado_destino_id]) { // Si el estado destino no era alcanzable
            alcanzables[estado_destino_id] = true;  // Marcarlo como alcanzable
            hubo_cambios = true;  // Hubo un cambio, continuamos iterando
          }
        }
      }
    }
  }
  // Imprimir los estados no alcanzables
  std::cout << "Estados no alcanzables desde el estado inicial:" << std::endl;
  bool algun_estado_no_alcanzable = false;
  // Verificar todos los estados
  for (const Estado& estado : estados_) {
    if (!alcanzables[estado.getId()]) {  // Si el estado no es alcanzable
      std::cout << "Estado " << estado.getId() << std::endl;
      algun_estado_no_alcanzable = true;
    }
  }
  if (!algun_estado_no_alcanzable) {
    std::cout << "Todos los estados son alcanzables desde el estado inicial." << std::endl;
  }
  std::cout << std::endl; // Para que haya suficiente espacio entre la comprobación de estados y la de las cadenas
}