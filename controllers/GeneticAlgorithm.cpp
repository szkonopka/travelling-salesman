#include "GeneticAlgorithm.h"

std::vector<int> GeneticAlgorithm::OrderX(std::vector<int> firstParent, std::vector<int> secondParent) {
  int pivot = getPivot(firstParent.size());
  int start = getRandNumbBeforePivot(pivot);
  int end = getRandomNumbAfterPivot(pivot);
}

std::vector<int> GeneticAlgorithm::CycleX(std::vector<int> firstParent, std::vector<int> secondParent) {

}

std::vector<int> GeneticAlgorithm::PartiallyMatchedX(std::vector<int> firstParent, std::vector<int> secondParent) {

}

void GeneticAlgorithm::SearchForBestPath() {
  std::cout << "Odpalam algorytm genetyczny" << std::endl;
  InitPopulation();

  for(Individual individual : _population.IndividualList) {
    for(int value : individual.Order) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "FitnessScore: " << individual.FitnessScore << std::endl;
  }
  CalculateFitness();
  NormalizeFitness();
  GenerateNewPopulation();
}

void GeneticAlgorithm::InitPopulation() {
  Individual tempIndividual;
  for(int i = 0; i < matrix->getMatrixSize(); i++)
    tempIndividual.Order.push_back(i);
  std::cout << "SIZE: " << _populationSize << std::endl;
  for(int i = 0; i < _populationSize; i++) {
    _population.IndividualList.push_back(tempIndividual);
  }
}

void GeneticAlgorithm::CalculateFitness() {
  for(Individual individual : _population.IndividualList) {
    //individual.FitnessScore
  }
}

void GeneticAlgorithm::NormalizeFitness() {

}

void GeneticAlgorithm::GenerateNewPopulation() {

}

std::vector<int> GeneticAlgorithm::TournamentSelection() {

}

std::vector<int> GeneticAlgorithm::RouletteSelection() {

}

std::vector<int> GeneticAlgorithm::GreedySolution() {
  std::vector<int> visited(matrix->getMatrixSize(), 0);
  std::vector<int> temporarySolution(matrix->getMatrixSize(), 0);

  /*for(int i = 0; i < temporarySolution.size(); i++)
    temporarySolution[i] = i;

  int counter = 0, i = 0, j = 0, tempBest = 99999999;
  while(counter < visited.size()) {
    tempBest = 99999999;
    for(j = 0; j < temporarySolution.size(); j++) {
      if(!visited[j] && tempBest > matrix.getConnection(i, j)) {
        tempBest = matrix.getConnection(i, j);
        counter++;
      }
    }
    i = j;
    visited[i] = 1;  ``
    temporarySolution[i][j] = matrix.getConnection(i, j);
    j = 0;
  }*/
  return temporarySolution;
}
