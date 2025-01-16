#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Storage.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

void Usage(int argc, char* argv[]);
void analyze_all(std::string filein, std::string fileout, Storage code_storage);

#endif