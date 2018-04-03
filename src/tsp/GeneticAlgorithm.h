#include "Algorithm.h"
#include <iostream>

struct Individual {
  std::vector<int> Order;
  double FitnessScore = 0.0;
};

struct Population {
  std::vector<Individual> IndividualList;
};

enum CrossoverType {
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
  double _bestDist;
  int _crossoverType = CrossoverType::OX;
  int _mutationType = MutationType::Swap;
public:
  GeneticAlgorithm() {}
  GeneticAlgorithm(MatrixGraph *matrix, int mutationRate, int crossoverRate) : Algorithm(matrix) {
    _mutationRate = mutationRate;
    _crossoverRate = crossoverRate;
  }
  virtual void SearchForBestPath();
  void DisplaySolution();
  std::vector<int> OrderX(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> CycleX(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> PartiallyMatchedX(std::vector<int> firstParent, std::vector<int> secondParent);
  void InitPopulation();
  void CalculateFitness();
  void NormalizeFitness();
  void GenerateNewPopulation();
  void Mutate(std::vector<int> &individualr);
  bool IsValueInVector(std::vector<int> vec, int value);
  std::vector<int> GreedySolution();
  std::vector<int> TournamentSelection();
  std::vector<int> RouletteSelection();
};
