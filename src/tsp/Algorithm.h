#include <vector>
#include <algorithm>
#include "../structures/MatrixGraph.h"
#include <stdlib.h>
#include <ctime>
#include <random>
#include <climits>

class Algorithm {
protected:
  template< class RealType = double >
  class uniform_real_distribution;

  MatrixGraph *matrix = nullptr;
  std::vector<int> _bestPath;
  double _bestDist = INT_MAX;
  std::random_device rd;
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
  int IndexOf(std::vector<int> vec, int value);
  void Swap(std::vector<int> &individual, int indexA, int indexB);
  void Insert(std::vector<int> &individual, int indexA, int indexB);
  void Invert(std::vector<int> &individual, int indexA, int indexB);
  bool IsValueInVector(std::vector<int> vec, int value);
  std::vector<int> GreedySolution();
  double RandomFromZeroToOne();
  void DisplaySolution();
};
