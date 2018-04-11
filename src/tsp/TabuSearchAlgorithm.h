#include "Algorithm.h"
#include "../structures/TabuList.h"

enum NeighborType {
  Invert, Insert, Swap
};

class TabuSearch : Algorithm {
private:
  std::vector<std::vector<int> > _tabuList;
  int _stepsAmount = 1000;
  double _bestPathFitness;
  NeighborType _neighborType = NeighborType::Swap;
public:
  virtual void SearchForBestPath();
  void InitSolution();
  void NewNeighborhood();
  void Diversification();
  void CalculateFitness();
};
