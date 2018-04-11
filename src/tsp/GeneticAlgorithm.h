#include "Algorithm.h"
#include "./helpers/Metaheuristic.h"
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
  OX, CX, PMX
};

enum SelectionType {
  Tournament, Roulette
};

enum PopulationInitType {
  FromGreedy, SimilarOrdered, Random, Mixed
};

class GeneticAlgorithm : public Algorithm, public Metaheuristic
{
private:
  int _populationSize = 1000;
  int _generationsAmount = 100000;
  double _mutationRate;
  double _crossoverRate;
  double _newPopulationSelectionRate = 1.0;
  Population _population;
  int _crossoverType = CrossoverType::CX;
  int _mutationType = MutationType::Swap;
  int _populationInitType = PopulationInitType::SimilarOrdered;
  void CalculateFitness();
  void NormalizeFitness();
  void GenerateNewPopulation();
public:
  GeneticAlgorithm() {}
  GeneticAlgorithm(MatrixGraph *matrix, double mutationRate, double crossoverRate) : Algorithm(matrix)
  {
    _mutationRate = mutationRate;
    _crossoverRate = crossoverRate;
  }

  virtual void SearchForBestPath();
  virtual void InitSolution();
  std::vector<int> OrderCrossover(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> CycleCrossover(std::vector<int> firstParent, std::vector<int> secondParent);
  std::vector<int> PartiallyMatchedCrossover(std::vector<int> firstParent, std::vector<int> secondParent);
  void Mutate(std::vector<int> &individual);
  std::vector<int> TournamentSelection();
  std::vector<int> RouletteSelection();
  int getIndexOfTheWorst();
};
