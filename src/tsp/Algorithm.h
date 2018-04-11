#pragma once
#include <vector>
#include <algorithm>
#include "../structures/MatrixGraph.h"
#include <stdlib.h>
#include <ctime>
#include <random>
#include <climits>

class Algorithm
{
protected:
  template< class RealType = double >
  class uniform_real_distribution;

  MatrixGraph *matrix = nullptr;
  std::vector<int> _bestPath;
  double _bestDist = INT_MAX;
  std::random_device rd;
public:
  Algorithm() {}
  Algorithm(MatrixGraph *matrix);
  virtual void SearchForBestPath() = 0;
  virtual void InitSolution() = 0;

  std::vector<int> getBestPath();
  void DisplaySolution();
  double getBestDist();

  std::vector<int> GreedySolution();
  int getPivot(int size);
  int getRandNumbBeforePivot(int pivot);
  int getRandomNumbAfterPivot(int pivot);
  int CalculateDistance(std::vector<int> order);
  int IndexOf(std::vector<int> vec, int value);
  bool IsValueInVector(std::vector<int> vec, int value);
  double RandomFromZeroToOne();
};
