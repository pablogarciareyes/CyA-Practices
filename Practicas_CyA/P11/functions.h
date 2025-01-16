#pragma once
#define FUNCTIONS_H

#include <fstream>

#include "point_set.h"
#include "point_types.h"
#include "sub_tree.h"

void Usage(int argc, char *argv[]);
void ReadPoints(CyA::point_vector &pv, std::string file_name);
void IsDot(char* option, EMST::point_set &ps);