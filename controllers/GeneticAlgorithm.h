#include "Algorithm.h"
#include <iostream>

struct Individual {
  std::vector<int> Order;
  double FitnessScore = 0.0;
};

struct Population {
  std::vector<Individual> IndividualList;
};

enum CrossType {
  OX, CX
};

enum MutationType {
  Invert, Insert, Swap
};

enum SelectionType {
  Tournament, Roulette
};

class GeneticAlgorithm : virtual public Algorithm {
private:
  int _populationSize = 100;
  int _generationAmount;
  float _mutationRate;
  float _crossoverRate;
  Population _population;
  std::vector<int> _bestPath;
  int _bestDist;
public:
  GeneticAlgorithm() {}
  GeneticAlgorithm(MatrixGraph *matrix, int mutationRate, int crossoverRate) : Algorithm(matrix) { }
  virtual void SearchForBestPath();

  std::vector<int> OrderX(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> CycleX(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> PartiallyMatchedX(std::vector<int> firstParent, std::vector<int> secondParent);
  void InitPopulation();
  void CalculateFitness();
  void NormalizeFitness();
  void GenerateNewPopulation();
  std::vector<int> GreedySolution();
  std::vector<int> TournamentSelection();
  std::vector<int> RouletteSelection();
};
