#include "Algorithm.h"
#include "../structures/TabuList.h"
#include "./helpers/Metaheuristic.h"

class TabuSearchAlgorithm : public Algorithm, public Metaheuristic
{
private:
  TabuList *_tabuList;
  int _stepsAmount = 1000;
  int _criticalIterations = 100;
  double _bestPathFitness;
  MutationType _mutationType = MutationType::Swap;
public:
  TabuSearchAlgorithm() { }
  TabuSearchAlgorithm(MatrixGraph *matrix) : Algorithm(matrix)
  {
    _tabuList = new TabuList(10, matrix -> getMatrixSize());
  }

  virtual void SearchForBestPath();
  virtual void InitSolution();
  std::vector<int> NewNeighborhood(std::vector<int> solution);
  void Diversification(std::vector<int> &solution, int i);
  double CalculateFitness(std::vector<int> x, std::vector<int> y);
};
