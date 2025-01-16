#include "Functions.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  Storage code_storage;
  analyze_all(argv[1], argv[2], code_storage);
  return 0;
}