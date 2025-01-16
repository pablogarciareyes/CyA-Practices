/* *
* Universidad de La Laguna
* Escuela Superior de Ingenieria y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 12: Algoritmos Divide y venceras
* Autor: Pablo García de los Reyes
* Correo: alu0101630045@ull.edu.es
* Fecha: 17/12/2024
* Archivo PointSet.h: Header File
* Contiene la declaracion de los metodos y atributos de la clase PointSet
* 15/12/2024 - Creación (primera versión) del código
*/

#ifndef PONITSET_H_
#define PONITSET_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>

namespace CyA {
  typedef std::pair<double,double> point;
  typedef std::pair<point, point> line;
  typedef std::vector<point> point_vector;
 
  enum side {
    LEFT = -1,
    CENTER,
    RIGHT
  };
 
  class PointSet : public point_vector{ 
    public:
        PointSet(const std::vector<point> &points);
        ~PointSet(void);
        void QuickHull(void);
        void WriteHull(std::ostream &os) const;
        void Write(std::ostream &os) const;
        void WriteDot(std::ofstream& archivo_salida);
        inline const point_vector& get_hull(void) const { return hull_; }
        inline const point_vector& get_points(void) const { return *this; }
        void set_top(double new_top);
      private:
        void QuickHull(const line &l, int side);
        double Distance(const line &l, const point &p) const;
        int FindSide(const line &l, const point &p) const;
        void FindBounds(point &min_x, point &max_x) const;
        double Point2Line(const line &l, const point &p) const;
        bool FarthestPoint(const line &l, int side, point &farthest) const;
        point_vector hull_; //Puntos que conformarán la envoltura convexa
        // Modificacion
        double top_dist_;
  };
}

#endif //PONITSET_H_