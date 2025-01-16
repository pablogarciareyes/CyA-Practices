#include "point_set.h"

namespace EMST {
    /// @brief Constructor de la clase point_set
    /// @param points
    point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points) {}

    /// @brief Destructor de la clase point_set
    point_set::~point_set(void) {}

    /// @brief Lógica del algoritmo de Kruskal
    /// @param  
    void point_set::EMST(void) {
        std::cin >> umbral_;
        CyA::arc_vector av;
        ComputeArcVector(av);
        forest st;
        for (const CyA::point &p : *this) {
            sub_tree s;
            s.add_point(p);
            st.push_back(s);
        }
        for (const CyA::weigthed_arc &a : av) {
            int i, j;
            FindIncidentSubtrees(st, a.second, i, j);
            if (i != j) {
                MergeSubtrees(st, a.second, i, j);
            }
        }
        emst_ = st[0].get_arcs();
    }

    /// @brief Crea el vector de arcos con coste según la distancia
    /// @param av 
    void point_set::ComputeArcVector(CyA::arc_vector &av) const {
        av.clear();
        const int n = size();
        for (int i = 0; i < n - 1; ++i) {
            const CyA::point &p_i = (*this)[i];
            for (int j = i + 1; j < n; ++j) {
                const CyA::point &p_j = (*this)[j];
                const double dist = EuclideanDistance(std::make_pair(p_i, p_j));
                if (dist >= umbral_) {
                    av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
                }
            }
        }
        std::sort(av.begin(), av.end());
    }

    /// @brief Encuentra los subárboles incidentes a un arco
    /// @param st
    /// @param a
    /// @param i
    /// @param j
    void point_set::FindIncidentSubtrees(const forest& st, const CyA::arc &a, int& i, int& j) const {
        i = j = -1;
        for (int k = 0; k < st.size(); ++k) {
            if (st[k].Contains(a.first)) {
                i = k;
            }
            if (st[k].Contains(a.second)) {
                j = k;
            }
            if (i != -1 && j != -1) {
                break;
            }
        }
    }

    /// @brief Fusiona dos subárboles
    /// @param st
    /// @param a
    /// @param i
    /// @param j
    void point_set::MergeSubtrees(forest& st, const CyA::arc &a, int i, int j) const {
        // Normalizar el arco (asegurar orden consistente de los puntos)
        CyA::arc normalized_arc = (a.first < a.second) ? a : std::make_pair(a.second, a.first);

        // Fusionar subárboles `st[i]` y `st[j]` en `st[i]`
        st[i].Merge(st[j], std::make_pair(EuclideanDistance(normalized_arc), normalized_arc));

        // Evitar duplicados: si el arco ya existe, no se vuelve a añadir
        if (!st[i].Contains(normalized_arc.first) || !st[i].Contains(normalized_arc.second)) {
            st[i].add_arc(normalized_arc);
        }

        // Eliminar el subárbol fusionado (posición `j`)
        st.erase(st.begin() + j);
    }


    /// @brief Calcula el coste del árbol
    /// @param
    /// @return coste
    double point_set::ComputeCost(void) const {
        double cost = 0;
        for (const CyA::arc &a : emst_) {
            cost += EuclideanDistance(a);
        }
        return cost;
    }

    /// @brief Calcula la distancia euclídea entre dos puntos
    /// @param a
    /// @return distancia
    double point_set::EuclideanDistance(const CyA::arc& a) const {
        const double dx = a.first.first - a.second.first;
        const double dy = a.first.second - a.second.second;
        return std::sqrt(dx * dx + dy * dy);
    }

    /// @brief Write the points to the output stream
    /// @param os
    void point_set::Write(std::ostream &os) const {
        for (const CyA::point &p : *this) {
            os << p.first << " " << p.second << std::endl;
        }
    }

    /// @brief Write the tree to the output stream
    /// @param os
    void point_set::WriteTree(std::ostream &os) const {
        double coste = 0;
        for (const CyA::arc &a : emst_) {
            coste += EuclideanDistance(a);
            os << "(" << a.first.first << ", " << a.first.second << ")" << " - (" << a.second.first << ", " << a.second.second << ")" << std::endl;
        }
        os << "Coste total: " << coste << std::endl;
    }

    /// @brief Write the tree to a file in DOT format
    /// @param file_name
    void point_set::WriteDot(std::string file_name) const {
        std::ofstream file(file_name);
        if (!file.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo de salida" << std::endl;
            exit(1);
        }
        file << "graph {" << std::endl << std::endl;
        for (size_t i = 0; i < this->size(); ++i) {
            const auto &point = this->at(i);
            file << "  " << i << " [pos=\"" << point.first << "," << point.second << "!\"];" << std::endl;
        }
        file << std::endl;
        // Escritura de los arcos
        for (const auto& arc : emst_) {
            size_t indice1 = std::distance(this->begin(), std::find(this->begin(), this->end(), arc.first));
            size_t indice2 = std::distance(this->begin(), std::find(this->begin(), this->end(), arc.second));
            file << "  " << indice1 << " -- " << indice2 << ";" << std::endl; 
        }
        file << "}" << std::endl;
        file.close();
    }
}