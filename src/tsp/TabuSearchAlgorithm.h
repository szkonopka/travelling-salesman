#include "Algorithm.h"
#include "../structures/TabuList.h"

class TabuSearchAlgorithm : virtual public Algorithm {
private:
  TabuList *_tabuList;
  int _stepsAmount = 1000;
  double _bestPathFitness;
  MutationType _mutationType = MutationType::Swap;
public:
  TabuSearchAlgorithm() { }
  TabuSearchAlgorithm(MatrixGraph *matrix) : Algorithm(matrix)
  {
    _tabuList = new TabuList(10, matrix -> getMatrixSize());
  }
  virtual void SearchForBestPath();
  void InitSolution();
  std::vector<int> NewNeighborhood(std::vector<int> solution);
  void Diversification();
  double CalculateFitness(std::vector<int> x, std::vector<int> y);
};
