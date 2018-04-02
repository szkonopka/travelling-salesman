#include "GeneticAlgorithm.h"
#include <algorithm>

std::vector<int> GeneticAlgorithm::OrderX(std::vector<int> firstParent, std::vector<int> secondParent) {
  int pivot = getPivot(firstParent.size());
  int start = getRandNumbBeforePivot(pivot);
  int end = getRandomNumbAfterPivot(pivot);
  std::vector<int> child(firstParent.size(), -1);
  std::vector<int> crossSpace(end - start, 0);

  for(int i = start; i < end; i++) {
    child[i] = secondParent[i];
    crossSpace[i - start] = secondParent[i];
  }

  int counter = 0, i = end, j = end;
  int size = child.size();
  while(counter < size) {
    j = j % size;
    i = i % size;
    if(std::find(crossSpace.begin(), crossSpace.end(), firstParent[i]) != crossSpace.end()) {
      child[j] = firstParent[i];
      j++;
    }
    i++;
    counter++;
  }
  return child;
}

std::vector<int> GeneticAlgorithm::CycleX(std::vector<int> firstParent, std::vector<int> secondParent) {

}

std::vector<int> GeneticAlgorithm::PartiallyMatchedX(std::vector<int> firstParent, std::vector<int> secondParent) {

}

void GeneticAlgorithm::SearchForBestPath() {
  std::cout << "Odpalam algorytm genetyczny" << std::endl;
  InitPopulation();
  for(int i = 0; i < 10000; i++) {
    CalculateFitness();
    NormalizeFitness();
    GenerateNewPopulation();
    std::cout << "CURRENT BEST - " << _bestDist << std::endl;
  }
}

void GeneticAlgorithm::InitPopulation() {
  Individual tempIndividual;
  for(int i = 0; i < matrix->getMatrixSize(); i++)
    tempIndividual.Order.push_back(i);

  for(int i = 0; i < _populationSize; i++) {
    _population.IndividualList.push_back(tempIndividual);
  }

  _bestDist = CalculateDistance(tempIndividual.Order);
}

void GeneticAlgorithm::CalculateFitness() {
  double temporaryDistance = 0.0;
  for(Individual &individual : _population.IndividualList) {
    temporaryDistance = CalculateDistance(individual.Order);
    std::cout << temporaryDistance << std::endl;
    individual.FitnessScore = (1 / (temporaryDistance + 1));
    if(temporaryDistance < _bestDist) {
      _bestDist = temporaryDistance;
      _bestPath = individual.Order;
    }
  }
}

void GeneticAlgorithm::NormalizeFitness() {
  double fitnessSum = 0;
  for(Individual &individual : _population.IndividualList) {
    fitnessSum += individual.FitnessScore;
  }

  for(Individual &individual : _population.IndividualList) {
    individual.FitnessScore = (individual.FitnessScore / fitnessSum);
  }
}

void GeneticAlgorithm::GenerateNewPopulation() {
  Population newPopulation;
  Individual tempIndividual;

  for(int i = 0; i < _populationSize - 1; i++) {
    tempIndividual.Order = OrderX(_population.IndividualList[i].Order, _population.IndividualList[i + 1].Order);
    newPopulation.IndividualList.push_back(tempIndividual);
  }
  _population.IndividualList = newPopulation.IndividualList;
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
