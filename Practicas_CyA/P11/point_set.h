#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

#include "point_types.h"
#include "sub_tree.h"

namespace EMST {
  typedef std::vector<sub_tree> forest;
  class point_set : public CyA::point_vector {
    public:
      point_set(const CyA::point_vector &points);
      ~point_set(void);
      void EMST(void);
      void WriteTree(std::ostream &os) const;
      void WriteDot(std::string file_name) const;
      void Write(std::ostream &os) const;
      inline const CyA::tree& get_tree(void) const { return emst_; }
      inline const CyA::point_vector& get_points(void) const { return *this; }
      inline const double get_cost(void) const { return ComputeCost(); }
    private:
      CyA::tree emst_;
      double umbral_;
      void ComputeArcVector(CyA::arc_vector &av) const;
      void FindIncidentSubtrees(const forest& st, const CyA::arc &a, int& i, int& j) const;
      void MergeSubtrees(forest& st, const CyA::arc &a, int i, int j) const;
      double ComputeCost(void) const;
      double EuclideanDistance(const CyA::arc& a) const;
  };
}