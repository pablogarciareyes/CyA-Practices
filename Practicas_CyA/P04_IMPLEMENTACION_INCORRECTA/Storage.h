#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

typedef struct {
  std::vector<std::string> strings;
  std::vector<int> lines;
} vstrings;

class Storage {
  public:
    Storage();
    ~Storage();
    // Métodos para añadir a los vectores las variables enteras declaradas
    void read_int_declared(std::string filename);
    void add_int_declared(std::string line);
    void write_int_declared(std::string filename);
    //Métodos para añadir a los vectores las variables double declaradas
    void read_double_declared(std::string filename);
    void add_double_declared(std::string line);
    void write_double_declared(std::string filename);
    // Métodos para añadir a los vectores los bucles for declarados
    void read_for_declared(std::string filename);
    void add_for_declared(std::string line);
    void write_for_declared(std::string filename);
    // Métodos para añadir a los vectores los bucles while declarados
    void read_while_declared(std::string filename);
    void add_while_declared(std::string line);
    void write_while_declared(std::string filename);
    // Métodos para añadir a los vectores los comentarios de cabecera
    void read_header(std::string filename);
    void add_header(std::string line);
    void write_header(std::string filename);
    void write_header_with_lines(std::string filename);
    // Métodos para añadir a los vectores los comentarios
    void read_comments(std::string filename);
    void add_comments(std::string line);
    void write_comments(std::string filename);
    // Métodos para los comentarios multilinea
    void read_multicomment(std::string filename);
    void write_multicomment(std::string filename);
    // Método para comprobar que hay un main
    void main_exists(std::string filename, std::string fileout);
    // MODIFICACIÓN
    void read_case(std::string filename);
    void add_case_declared(std::string line);
    void write_case(std::string filename);
  private:
    vstrings int_declared_;
    vstrings double_declared_;
    vstrings for_declared_;
    vstrings while_declared_;
    vstrings headers_declared_;
    vstrings comments_declared_;
    vstrings multicomments_declared_;
    // MODIFICACION
    vstrings case_declared_;
};

#endif