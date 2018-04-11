#include "Algorithm.h"

class DynamicAlgorithm : public Algorithm
{
private:
  std::vector<int> previousElements, subElements;
  
public:
  DynamicAlgorithm() { }
  DynamicAlgorithm(MatrixGraph *matrix) : Algorithm(matrix)
  {

  }

  virtual void SearchForBestPath();
  virtual void InitSolution();
};
