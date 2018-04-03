#include <vector>
#include <algorithm>
#include "../structures/MatrixGraph.h"

class Algorithm {
protected:
  MatrixGraph *matrix = nullptr;
  std::vector<int> _bestPath;
  double _bestDist;
public:
  Algorithm() {}
  Algorithm(MatrixGraph *matrix) {
    this->matrix = matrix;
  }
  virtual void SearchForBestPath() = 0;
  int getPivot(int size);
  int getRandNumbBeforePivot(int pivot);
  int getRandomNumbAfterPivot(int pivot);
  int CalculateDistance(std::vector<int> order);
  void Swap(std::vector<int> &individual, int indexA, int indexB);
  void Insert(std::vector<int> &individual, int indexA, int indexB);
  void Invert(std::vector<int> &individual, int indexA, int indexB);
  bool IsValueInVector(std::vector<int> vec, int value);
  std::vector<int> GreedySolution();
};
