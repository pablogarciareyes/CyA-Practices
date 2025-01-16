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
* Archivo PointSet.cc: Source File
* Contiene la declaracion de los metodos y atributos de la clase PointSet
* 15/12/2024 - Creación (primera versión) del código
*/

#include "PointSet.h"

namespace CyA {
  int profundidad;
  /// @brief Calcula el QuickHull, que determina el envolvente convexo de un conjunto de puntos
  void PointSet::QuickHull(void) {
    top_dist_ = 0;
    // Limpiar la envolvente convexa
    hull_.clear();
    // Encontrar los puntos con las coordenadas x mínima y máxima
    CyA::point min_x_point; 
    CyA::point max_x_point;
    // Calcular la x mínima y la x máxima de point_vector
    FindBounds(min_x_point, max_x_point);
    // Calcular la envolvente convexa
    QuickHull(CyA::line(min_x_point, max_x_point), side::LEFT);
    QuickHull(CyA::line(min_x_point, max_x_point), side::RIGHT);
    // Profundidad
    std::cout << profundidad;
    // Remove duplicates
    std::sort(hull_.begin(), hull_.end());
    hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
  }

  /// @brief Realiza el cálculo del QuickHull recursivamente para un lado específico de la línea
  /// @param l La línea que se está considerando
  /// @param side El lado de la línea para dividir el conjunto de puntos
  void PointSet::QuickHull(const CyA::line &l, int side){
    CyA::point farthest;
    profundidad++;
    if (FarthestPoint(l, side, farthest)) {
      QuickHull(CyA::line(l.first, farthest), -FindSide(CyA::line(l.first, farthest), l.second));
      QuickHull(CyA::line(farthest, l.second), -FindSide(CyA::line(farthest, l.second), l.first));
    }
    else {
      hull_.push_back(l.first);
      hull_.push_back(l.second);
    }
  }

  /// @brief Encuentra el punto más alejado de la línea en un lado específico
  /// @param l La línea
  /// @param side El lado de la línea donde se busca el punto más alejado
  /// @param farthest El punto más alejado encontrado
  /// @return Devuelve true si se encontró un punto más alejado, de lo contrario false
  bool PointSet::FarthestPoint(const CyA::line &l, int side, CyA::point &farthest) const{
    farthest = CyA::point_vector::at(0);
    double max_dist = 0;
    bool found = false;
    for (const CyA::point &p : *this){
      const double dist = Distance(l, p);
      if (FindSide(l, p) == side && dist > max_dist) {
        farthest = p;
        max_dist = dist;
        found = true;
      }
    }
    return found;
  }

  /// @brief Calcula el determinante asociado a la posición del punto con respecto a la línea
  /// @param l La línea
  /// @param p El punto
  /// @return El valor del determinante
  double PointSet::Point2Line(const CyA::line &l, const CyA::point &p) const{
    const CyA::point &p1 = l.first;
    const CyA::point &p2 = l.second;
    return (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
  }

  /// @brief Calcula la distancia perpendicular entre un punto y una línea
  /// @param l La línea
  /// @param p El punto
  /// @return La distancia perpendicular entre el punto y la línea
  double PointSet::Distance(const CyA::line &l, const CyA::point &p) const{
    return fabs(Point2Line(l, p));
  }

  /// @brief Encuentra los puntos con las coordenadas x mínima y máxima en el conjunto de puntos
  /// @param min_x El punto con la coordenada x mínima
  /// @param max_x El punto con la coordenada x máxima
  void PointSet::FindBounds(point &min_x, point &max_x) const {
    min_x = (*this)[0]; 
    max_x = (*this)[0];
    // Calcular la x mínima y la x máxima de point_vector
    for(const auto& p : *this) {
      if (p.first < min_x.first) { 
        min_x = p;
      }
      if (p.first > max_x.first) { 
        max_x = p;
      }
    }
  }

  /// @brief Determina en qué lado de la línea se encuentra el punto
  /// @param l La línea
  /// @param p El punto
  /// @return LEFT si el punto está a la izquierda, RIGHT si está a la derecha, CENTER si está sobre la línea
  int PointSet::FindSide(const line &l, const point &p) const {
    // Calcular el determinante
    double det = (l.second.first - l.first.first) * (p.second - l.first.second) -
                 (l.second.second - l.first.second) * (p.first - l.first.first);

    // Ver el lado según el signo del determinante
    if (det > 0) return LEFT;    // Punto a la izquierda de la línea
    if (det < 0) return RIGHT;   // Punto a la derecha de la línea
    return CENTER; 
  }

  /// @brief Constructor que asigna un conjunto de puntos a la estructura
  /// @param points Conjunto de puntos a asignar
  PointSet::PointSet(const std::vector<point> &points){
    this->assign(points.begin(), points.end());
  }

  /// @brief Escribe el envolvente convexo en un flujo de salida
  /// @param os Flujo de salida donde se escribirá el envolvente
  void PointSet::WriteHull(std::ostream &os) const{
    for (const auto& point : hull_ ){
      os << "(" << point.first <<", " <<point.second<<")\n";
    }
  }

  /// @brief Destructor de la clase PointSet
  PointSet::~PointSet(void){
  }

  /// @brief Metodo para escribir el archivo .dot
  /// @param archivo_salida 
  void PointSet::WriteDot(std::ofstream& archivo_salida){
   // Escribimos todos los puntos
    archivo_salida << "graph {\n\n";
    for(size_t i = 0; i < this->size(); i++){ 
      const auto& point = this->at(i);
      archivo_salida << " " << i << " [pos = \"" << point.first << ", " << point.second << "!\"]\n";
    }

   
    // Escribimos las conexiones entre los puntos de la envolvente convexa de acuerdo a la cercanía
    for (size_t i = 0; i < hull_.size(); ++i) {
      // Encontrar el punto más cercano al punto i
      size_t closest = (i + 1) % hull_.size(); // Inicializamos con el siguiente punto
      double min_dist = std::hypot(hull_[i].first - hull_[closest].first, hull_[i].second - hull_[closest].second);

      for (size_t j = i + 1; j < hull_.size(); ++j) {
        if (i != j) {
          double dist = std::hypot(hull_[i].first - hull_[j].first, hull_[i].second - hull_[j].second);
          if (dist < min_dist) {
            closest = j;
            min_dist = dist;
          }
        }
      }

      // Ahora tenemos el punto más cercano en "closest", se conecta
      size_t index1 = std::distance(this->begin(), std::find(this->begin(), this->end(), hull_[i]));
      size_t index2 = std::distance(this->begin(), std::find(this->begin(), this->end(), hull_[closest]));

      archivo_salida << " " << index1 << " -- " << index2 << "\n";

      // Evitar conectar los puntos más cercanos ya conectados
      std::swap(hull_[i + 1], hull_[closest]);
    }

    // Cerramos la declaración de la gráfica
    archivo_salida << "}\n";
  }

  void PointSet::set_top(double new_top) {
    top_dist_ = new_top;
  }
}

