#include "GeneticAlgorithm.h"
#include <algorithm>

void GeneticAlgorithm::SearchForBestPath()
{
  InitSolution();

  for(int i = 0; i < _generationsAmount; i++)
  {
    NormalizeFitness();
    GenerateNewPopulation();
    CalculateFitness();
  }
}

void GeneticAlgorithm::InitSolution()
{
  Individual tempIndividual, tempGreedyIndividual;

  for(int i = 0; i < matrix->getMatrixSize(); i++)
    tempIndividual.Order.push_back(i);

  int i = 0;

  tempGreedyIndividual.Order = GreedySolution();

  switch(_populationInitType)
  {
    case PopulationInitType::FromGreedy:
      while(i < _populationSize)
      {
        _population.IndividualList.push_back(tempGreedyIndividual);
        i++;
      }
      break;
    case PopulationInitType::SimilarOrdered:
      while(i < _populationSize)
      {
        _population.IndividualList.push_back(tempIndividual);
        i++;
      }
      break;
    case PopulationInitType::Random:
      while(i < _populationSize)
      {
        std::random_shuffle(tempIndividual.Order.begin(), tempIndividual.Order.end());
        _population.IndividualList.push_back(tempIndividual);
        i++;
      }
      break;
    case PopulationInitType::Mixed:
      while(i < _populationSize)
      {
        if(i & 1)
          _population.IndividualList.push_back(tempIndividual);
        else
          _population.IndividualList.push_back(tempGreedyIndividual);
        i++;
      }
      break;
    default:
      break;
  }

  CalculateFitness();
}

void GeneticAlgorithm::CalculateFitness()
{
  double temporaryDistance = 0.0;

  for(Individual &individual : _population.IndividualList)
  {
    temporaryDistance = CalculateDistance(individual.Order);
    individual.FitnessScore = (1 / (temporaryDistance + 1));

    if(temporaryDistance < _bestDist)
    {
      _bestDist = temporaryDistance;
      _bestPath = individual.Order;
      std::cout << "CURRENT BEST - " << _bestDist << std::endl;
    }
  }
}

void GeneticAlgorithm::NormalizeFitness()
{
  double fitnessSum = 0;

  for(Individual &individual : _population.IndividualList)
  {
    fitnessSum += individual.FitnessScore;
  }

  for(Individual &individual : _population.IndividualList)
  {
    individual.FitnessScore = (individual.FitnessScore / fitnessSum);
  }
}

void GeneticAlgorithm::GenerateNewPopulation()
{
  Population newPopulation;
  Individual tempIndividual;

  for(int i = 0; i < _populationSize; i++)
  {
    if(_crossoverRate > RandomFromZeroToOne())
    {
      switch(_crossoverType)
      {
        case CrossoverType::OX:
          tempIndividual.Order = OrderCrossover(RouletteSelection(), RouletteSelection());
          break;
        case CrossoverType::PMX:
          tempIndividual.Order = PartiallyMatchedCrossover(RouletteSelection(), RouletteSelection());
          break;
        case CrossoverType::CX:
          tempIndividual.Order = CycleCrossover(RouletteSelection(), RouletteSelection());
          break;
      }
    }
    else
    {
      tempIndividual.Order = _population.IndividualList[i].getOrder();
    }

    Mutate(tempIndividual.Order);
    newPopulation.IndividualList.push_back(tempIndividual);
  }

  _population = newPopulation;
}

void GeneticAlgorithm::Mutate(std::vector<int> &individual)
{
  double probability = RandomFromZeroToOne();

  if(_mutationRate < probability)
    return;

  int indexA, indexB;
  indexA = rand() % (individual.size() - 1) + 0;
  indexB = rand() % (individual.size() - 1) + 0;
  switch(_mutationType) {
    case MutationType::Swap:
      Swap(individual, indexA, indexB);
      break;
    case MutationType::Insert:
      Insert(individual, indexA, indexB);
      break;
    case MutationType::Invert:
      Invert(individual, indexA, indexB);
      break;
    default:
      break;
  }
}

std::vector<int> GeneticAlgorithm::OrderCrossover(std::vector<int> firstParent, std::vector<int> secondParent)
{
  int pivot = getPivot(firstParent.size());
  int start = getRandNumbBeforePivot(pivot);
  int end = getRandomNumbAfterPivot(pivot);

  std::vector<int> child(firstParent.size(), -1);
  std::vector<int> crossSpace((end - start), 0);

  for(int i = start; i < end; i++) {
    child[i] = secondParent[i];
    crossSpace[i - start] = secondParent[i];
  }

  int counter = 0, i = end, j = end;
  int size = child.size();

  while(counter < size) {
    j = j % size;
    i = i % size;

    if(!IsValueInVector(child, firstParent[i]))
    {
      child[j] = firstParent[i];
      j++;
    }

    i++;
    counter++;
  }

  return child;
}

std::vector<int> GeneticAlgorithm::CycleCrossover(std::vector<int> firstParent, std::vector<int> secondParent)
{
  int i = 0;
  int first = firstParent[i], second = secondParent[i], currentPosition, currentIndex;
  std::vector<int> child(firstParent.size(), -1);

  while(first == second)
  {
    i++;
    first = firstParent[i], second = secondParent[i];
    if(i == child.size())
      return firstParent;
  }

  currentPosition = second;
  currentIndex = i;
  child[currentIndex] = firstParent[currentIndex];

  while(first != currentPosition)
  {
    currentIndex = IndexOf(firstParent, currentPosition);
    currentPosition = secondParent[currentIndex];
    child[currentIndex] = firstParent[currentIndex];
  }

  for(int i = 0; i < child.size(); i++)
  {
    if(child[i] == -1)
      child[i] = secondParent[i];
  }

  return child;
}

std::vector<int> GeneticAlgorithm::PartiallyMatchedCrossover(std::vector<int> firstParent, std::vector<int> secondParent)
{
  int pivot = getPivot(firstParent.size());
  int start = getRandNumbBeforePivot(pivot);
  int end = getRandomNumbAfterPivot(pivot);

  std::vector<int> child(firstParent.size(), -1);
  std::vector<int> firstCrossSpace((end - start), 0);
  std::vector<int> secondCrossSpace((end - start), 0);

  for(int i = start; i < end; i++)
  {
    child[i] = secondParent[i];
    firstCrossSpace[i - start] = firstParent[i];
    secondCrossSpace[i - start] = secondParent[i];
  }

  for(int i = 0; i < child.size(); i++)
  {
      if(!IsValueInVector(firstCrossSpace, firstParent[i]) && !IsValueInVector(child, firstParent[i]))
      {
        child[i] = firstParent[i];
      }
  }

  int j = 0;

  for(int i = 0; i < child.size(); i++)
  {
    if(child[i] == -1)
    {
      while(IsValueInVector(child, firstCrossSpace[j]))
        j++;

      child[i] = firstCrossSpace[j];
    }
  }

  return child;
}

std::vector<int> GeneticAlgorithm::TournamentSelection()
{

}

std::vector<int> GeneticAlgorithm::RouletteSelection()
{
  int i = 0;
  double r = RandomFromZeroToOne();

  while((r > (double)0) && (i < _populationSize - 1))
  {
    r = r - _population.getIndividual(i).getFitness();
    i++;
  }

  i = i - 1;

  return _population.getIndividual(i).getOrder();
}

int GeneticAlgorithm::getIndexOfTheWorst()
{
  double worstFitnessScore = 1.1;
  int index = 0;

  while(index < _populationSize)
  {
    if(worstFitnessScore > _population.IndividualList[index].getFitness()) {
      worstFitnessScore = _population.IndividualList[index].getFitness();
    }
    index++;
  }

  return index;
}
