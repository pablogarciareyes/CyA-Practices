#include "Storage.h"

/// @brief Constructor de la clase Storage
Storage::Storage() {
  int_declared_ = {};
  double_declared_ = {};
  for_declared_ = {};
  while_declared_= {};
  headers_declared_ = {};
  comments_declared_ = {};
  case_declared_ = {};
}

/// @brief Destructor de la clase Storage
Storage::~Storage() {}

/// @brief Lee las variables enteras declaradas en un archivo
/// @param filename 
void Storage::read_int_declared(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  // Lee los enteros
  std::string line;
  std::regex int_declared("^\\s*int\\s+\\w+\\s*(;|=\\s*\\d*)");
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, int_declared)) {
      add_int_declared(line);
      int_declared_.lines.push_back(i);
    }
    i++;
  }
}

/// @brief Añade las variables enteras declaradas a un vector
/// @param line 
void Storage::add_int_declared(std::string line) {
  int_declared_.strings.push_back(line);
}

/// @brief Escribir las variables enteras declaradas en un archivo
/// @param filename 
void Storage::write_int_declared(std::string filename) {
  // Usando fstream para escribir las variables enteras declaradas en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < int_declared_.strings.size(); i++) {
    std::string linea = int_declared_.strings[i];
    int linea_num = int_declared_.lines[i];
    // Eliminar espacios antes de la primera letra
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] INT: ";
    for (int j = 4; j < linea.size() - 1; j++) {
      file << linea[j];
    }
    file << std::endl;
  }
  file.close();
}

/// @brief Lee las variables double de un fichero y las almacena en el vector correspondiente del objeto
/// @param filename 
void Storage::read_double_declared(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  // Lee los enteros
  std::string line;
  std::regex double_declared("^\\s*double\\s+\\w+\\s*(;|=\\s*\\d*)");
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, double_declared)) {
      add_double_declared(line);
      double_declared_.lines.push_back(i);
    }
    i++;
  }
}

/// @brief Añade una linea donde se haya declarado un double a el vector correspondiente de strings
/// @param line 
void Storage::add_double_declared(std::string line) {
  double_declared_.strings.push_back(line);
}

/// @brief Escribe en el fichero de salida las declaraciones de double en el fichero de entrada
/// @param filename 
void Storage::write_double_declared(std::string filename) {
  // Usando fstream para escribir las variables enteras declaradas en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < double_declared_.strings.size(); i++) {
    std::string linea = double_declared_.strings[i];
    int linea_num = double_declared_.lines[i];
    // Eliminar espacios antes de la primera letra
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] DOUBLE: ";
    for (int j = 7; j < linea.size() - 1; j++) {
      file << linea[j];
    }
    file << std::endl;
  }
  file.close();
}

/// @brief Lee los bucles for declarados en un archivo
/// @param filename 
void Storage::read_for_declared(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  // Lee los bucles for
  std::string line;
  std::regex for_declared("^\\s*for.*");
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, for_declared)) {
      add_for_declared(line); // Cambiar a add_loops_declared
      for_declared_.lines.push_back(i);
    }
    i++;
  }
  file.close();
}

/// @brief Añade los bucles for declarados a un vector
/// @param line
void Storage::add_for_declared(std::string line) {
  for_declared_.strings.push_back(line);
}

/// @brief Escribir los bucles for declarados en un archivo
/// @param filename
void Storage::write_for_declared(std::string filename) {
  // Usando fstream para escribir los bucles for declarados en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < for_declared_.strings.size(); i++) {
    std::string linea = for_declared_.strings[i];
    int linea_num = for_declared_.lines[i];
    // Eliminar espacios antes de la primera letra
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] LOOP: ";
    for (int j = 0; j < 4; j++) {
      file << linea[j];
    }
    file << std::endl;
  }
  file.close();
}

/// @brief Lee los bucles for declarados en un archivo
/// @param filename 
void Storage::read_while_declared(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  // Lee los bucles while
  std::string line;
  std::regex while_declared("^\\s*while.*");
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, while_declared)) {
      add_while_declared(line);
      while_declared_.lines.push_back(i);
    }
    i++;
  }
  file.close();
}

/// @brief Añade los bucles for declarados a un vector
/// @param line
void Storage::add_while_declared(std::string line) {
  while_declared_.strings.push_back(line);
}

/// @brief Escribe los bucles while declarados en el fichero de salida
/// @param filename 
void Storage::write_while_declared(std::string filename) {
  // Usando fstream para escribir los bucles for declarados en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < while_declared_.strings.size(); i++) {
    std::string linea = while_declared_.strings[i];
    int linea_num = while_declared_.lines[i];
    // Eliminar espacios antes de la primera letra
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] LOOP: ";
    for (int j = 0; j < 6; j++) {
      file << linea[j];
    }
    file << std::endl;
  }
  file.close();
}

/// @brief Añade los comentarios de cabecera a un vector
/// @param line
void Storage::read_header(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  std::string line;
  std::regex header_start("^/\\*\\*");
  std::regex header_end("^ \\*/");
  bool in_header = false;
  while (std::getline(file, line)) {
    if (std::regex_search(line, header_start)) {
      in_header = true;
    }
    
    if (in_header) {
      headers_declared_.strings.push_back(line);
    }
    
    if (std::regex_search(line, header_end)) {
      in_header = false;
    }
  }
  file.close();
}

/// @brief Escribir los comentarios de cabecera en un archivo
/// @param filename
void Storage::write_header(std::string filename) {
  // Usando fstream para escribir los comentarios de cabecera en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < headers_declared_.strings.size(); i++) {
    std::string linea = headers_declared_.strings[i];
    file << linea << std::endl;
  }
  file.close();
}

/// @brief Añade los comentarios a un vector
/// @param line
void Storage::add_comments(std::string line) {
  comments_declared_.strings.push_back(line);
}

/// @brief Añade los comentarios a un vector
/// @param line
void Storage::read_comments(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  int i = 1;
  std::string line;
  std::regex comment("^\\s*//.*");
  while (std::getline(file, line)) {
    if (std::regex_search(line, comment)) {
      add_comments(line);
      comments_declared_.lines.push_back(i);
    }
    i++;
  }
  file.close();
}

/// @brief Escribir los comentarios en un archivo
/// @param filename
void Storage::write_comments(std::string filename) {
  write_header_with_lines(filename);
  // Usando fstream para escribir los comentarios en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < comments_declared_.strings.size(); i++) {
    std::string linea = comments_declared_.strings[i];
    int linea_num = comments_declared_.lines[i];
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] " << linea << std::endl; 
  }
  file.close();
}

/// @brief Escribir los comentarios de cabecera en un archivo con rango de líneas
/// @param filename
void Storage::write_header_with_lines(std::string filename) {
  if (headers_declared_.strings.empty()) {
    return;
  }
  
  std::ofstream file(filename, std::ios::app);
  int start_line = 1; // Asumiendo que empieza en la línea 1
  int end_line = start_line + headers_declared_.strings.size() - 1;
  
  file << "[Line " << start_line << " - " << end_line << "] DESCRIPTION" << std::endl;
  file.close();
}

/// @brief Lee los comentarios multilinea
/// @param filename 
void Storage::read_multicomment(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  std::string line;
  std::regex header_start("^/\\*");
  std::regex header_end("^\\*/");
  bool in_header = false;
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, header_start)) {
      in_header = true;
      multicomments_declared_.lines.push_back(i);
    }
    
    if (in_header) {
      multicomments_declared_.strings.push_back(line);
    }
    
    if (std::regex_search(line, header_end)) {
      in_header = false;
      multicomments_declared_.lines.push_back(i);
    }
    i++;
  }
  file.close();
}

void Storage::write_multicomment(std::string filename) {
  // Usando fstream para escribir los bucles for declarados en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < multicomments_declared_.strings.size(); i += 2) {
    file << "[Line " << multicomments_declared_.lines[i] 
    << " - " << multicomments_declared_.lines[i + 1] << "] MULTICOMMENT";
    file << std::endl;
  }
  file.close();
}

/// @brief Comprueba si hay un main en el archivo
/// @param filename
void Storage::main_exists(std::string filename, std::string fileout) {
  std::ifstream filein(filename);
  std::ofstream file(fileout, std::ios::app);
  if (!filein.is_open()) {
    exit(EXIT_SUCCESS);
  }
  std::string line;
  std::regex main("int\\s+main\\s*\\(\\s*\\)\\s*\\{");
  while (std::getline(filein, line)) {
    if (std::regex_search(line, main)) {
      file << "True" << std::endl;
      return;
    }
  }
  file << "False" << std::endl;
  file.close();
}


// MODIFICACION

/// @brief Lee las instaciaciones de case en el fichero de entrada
/// @param filename 
void Storage::read_case(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    exit(EXIT_SUCCESS);
  }
  // Lee las instanciaciones case
  std::string line;
  std::regex case_declared("^\\s*(case\\s*(\\w|\"\\w\")):|(default:)");
  int i = 1;
  while (std::getline(file, line)) {
    if (std::regex_search(line, case_declared)) {
      add_case_declared(line);
      case_declared_.lines.push_back(i);
    }
    i++;
  }
  file.close();
}

/// @brief Introduce las coincidencias con la expresión regular en el struct
/// @param line 
void Storage::add_case_declared(std::string line) {
  case_declared_.strings.push_back(line);
}


/// @brief Escribe las coincidencias de case en el fichero de salida
/// @param filename 
void Storage::write_case(std::string filename) {
  // Usando fstream para escribir los bucles for declarados en un archivo
  std::ofstream file(filename, std::ios::app);
  for (int i = 0; i < case_declared_.strings.size(); i++) {
    std::string linea = case_declared_.strings[i];
    int linea_num = case_declared_.lines[i];
    // Eliminar espacios antes de la primera letra
    linea.erase(0, linea.find_first_not_of(" \t"));
    file << "[Line " << linea_num << "] CASE: ";
    if (linea == "default:") {
      file << "default" << std::endl;
    }
    else if (linea.size() > 7) {
      file << linea[6] << std::endl;
    }
    else {
      file << linea[5] << std::endl;
    }
  }
  file.close();
}

