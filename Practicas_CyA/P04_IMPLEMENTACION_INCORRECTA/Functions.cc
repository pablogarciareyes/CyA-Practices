#include "Functions.h"

/// @brief Comprueba que el número de parametros pasados desde comando sea correcto, devuelve un mensaje de error en caso contrario.
/// @param argc 
/// @param argv 
void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    std::string help_message;
    std::cerr << "Usage: " << "<filein.txt> " << "<fileout.txt> " << std::endl;
    std::cerr << "Use --help para conocer la utilización del programa" << std::endl;
    std::cin >> help_message;
    if (help_message == "--help") {
      std::cout << "El programa lee un fichero que contenga código en C++ y escribe en otro fichero el resumen de este." << std::endl;
    }
    exit(EXIT_SUCCESS);
  }
}

/// @brief Realiza la escritura de toda la información almacenada en el objeto al fichero de salida.
/// @param filein 
/// @param fileout 
/// @param code_storage 
void analyze_all(std::string filein, std::string fileout, Storage code_storage) {
  // Borra el contenido del archivo de salida
  std::ofstream ofs(fileout, std::ios::out | std::ios::trunc);
  ofs.close();
  std::ofstream file(fileout, std::ios::app);
  file << "PROGRAM: " << filein << std::endl;
  file << "DESCRIPTION: " << std::endl;
  code_storage.read_header(filein);
  code_storage.write_header(fileout);
  file << std::endl << "VARIABLES: " << std::endl;
  code_storage.read_int_declared(filein);
  code_storage.write_int_declared(fileout);
  code_storage.read_double_declared(filein);
  code_storage.write_double_declared(fileout);
  file << std::endl << "STATEMENTS: " << std::endl;
  code_storage.read_for_declared(filein);
  code_storage.write_for_declared(fileout);
  code_storage.read_while_declared(filein);
  code_storage.write_while_declared(fileout);
  code_storage.read_case(filein);
  code_storage.write_case(fileout);
  file << std::endl << "MAIN: " << std::endl;
  code_storage.main_exists(filein, fileout);
  file << std::endl << "COMMENTS: " << std::endl;
  code_storage.read_comments(filein);
  code_storage.write_comments(fileout);
  // code_storage.read_multicomment(filein);
  // code_storage.write_multicomment(fileout);
}