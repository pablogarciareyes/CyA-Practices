#include "point_types.h"

#include <iomanip>

/// @brief Sobrecarga del operador de salida para imprimir un vector de puntos
/// @param os 
/// @param ps 
/// @return 
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
    os << ps.size() << std::endl;
    for (const CyA::point &p : ps) {
        os << p << std::endl;
    }
    return os;
}

/// @brief Sobrecarga del operador de salida para imprimir un punto
/// @param os 
/// @param p 
/// @return 
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
    os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;
    return os;
}

/// @brief Sobreacarga del operador de entrada para leer un vector de puntos
/// @param is 
/// @param ps 
/// @return 
std::istream& operator>>(std::istream& is, CyA::point_vector& ps){
    int n;
    is >> n;
    ps.clear();
    for (int i = 0; i < n; ++i) {
        CyA::point p;
        is >> p;

        ps.push_back(p);
    }
    return is;
}

/// @brief Sobrecarga del operador de entrada para leer un punto
/// @param is 
/// @param p 
/// @return 
std::istream& operator>>(std::istream& is, CyA::point& p) {
    is >> p.first >> p.second;
    return is;
}