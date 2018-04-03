#include "Algorithm.h"
#include <iostream>

struct Individual {
  std::vector<int> Order;
  double FitnessScore = 0.0;
  std::vector<int> getOrder() { return Order; }
  double getFitness() { return FitnessScore; }
};

struct Population {
  std::vector<Individual> IndividualList;
  Individual getIndividual(int index) { return IndividualList[index]; }
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
  int _crossoverType = CrossoverType::OX;
  int _mutationType = MutationType::Insert;
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
  void Mutate(std::vector<int> &individual);
  std::vector<int> GreedySolution();
  std::vector<int> TournamentSelection();
  std::vector<int> RouletteSelection();
};
