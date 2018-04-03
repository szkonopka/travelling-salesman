#include <vector>
#include "../structures/MatrixGraph.h"

class Algorithm {
protected:
  MatrixGraph *matrix = nullptr;
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
  std::vector<int> Insert(std::vector<int> individual, int indexA, int indexB);
  std::vector<int> Invert(std::vector<int> individual, int indexA, int indexB);
};
