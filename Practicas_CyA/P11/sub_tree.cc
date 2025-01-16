#include <iomanip>
#include <cmath>

#include <algorithm>
#include <utility>

#include "sub_tree.h"

namespace EMST
{   
    /// @brief Constructor por defecto
    /// @param  
    sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {}

    /// @brief Destructor
    /// @param  
    sub_tree::~sub_tree(void) {}

    /// @brief Añade un arco al subárbol
    /// @param a 
    void sub_tree::add_arc(const CyA::arc &a)
    {
      arcs_.push_back(a); // Insertamos el arco en el vector de arcos
      points_.insert(a.first); // Insertamos el primer punto del arco en el conjunto de puntos
      points_.insert(a.second); // Insertamos el segundo punto del arco en el conjunto de puntos
    }

    /// @brief Añade un punto al subárbol
    /// @param p 
    void sub_tree::add_point(const CyA::point &p)
    {
      points_.insert(p); // Insertamos el punto en el conjunto de puntos
    }

    /// @brief Comprueba si un punto está en el subárbol
    /// @param p 
    /// @return true or false
    bool sub_tree::Contains(const CyA::point &p) const
    {
      return points_.find(p) != points_.end(); // Devolvemos si el punto está en el conjunto de puntos
    }

    /// @brief Unión de dos subárboles
    /// @param st 
    /// @param a 
    void sub_tree::Merge(const sub_tree &st, const CyA::weigthed_arc &a)
    {
        arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end()); // Insertamos los arcos del subárbol en el vector de arcos
        arcs_.push_back(a.second); // Insertamos el arco en el vector de arcos
        points_.insert(st.points_.begin(), st.points_.end()); // Insertamos los puntos del subárbol en el conjunto de puntos
        cost_ += a.first + st.get_cost(); // Sumamos el coste del arco y el coste del subárbol
    }
}