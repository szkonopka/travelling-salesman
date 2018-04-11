#include "Algorithm.h"

Algorithm::Algorithm(MatrixGraph *matrix)
{
  this->matrix = matrix;
}

int Algorithm::getPivot(int size)
{
  return size / 2;
}

int Algorithm::getRandNumbBeforePivot(int pivot)
{
  return rand() % pivot + 0;
}

int Algorithm::getRandomNumbAfterPivot(int pivot)
{
  return rand() % pivot + pivot;
}

int Algorithm::IndexOf(std::vector<int> vec, int value)
{
  for(int i = 0; i < vec.size(); i++)
    if(vec[i] == value)
      return i;

  return 0;
}

int Algorithm::CalculateDistance(std::vector<int> order)
{
  int distance = 0, i;

  for(i = 0; i < order.size() - 1; i++)
  {
    distance += matrix->getConnection(order[i], order[i + 1]);
  }

  distance += matrix->getConnection(order[i], 0);

  return distance;
}

bool Algorithm::IsValueInVector(std::vector<int> vec, int value)
{
  for(int _value : vec)
  {
    if(_value == value)
      return true;
  }

  return false;
}

std::vector<int> Algorithm::GreedySolution()
{
  std::vector<int> visited(matrix->getMatrixSize(), 0);
  std::vector<int> temporarySolution(matrix->getMatrixSize(), 0);

  for(int i = 0; i < temporarySolution.size(); i++)
    temporarySolution[i] = i;

  int counter = 0, i = 0, nextOne = 0, j = 0, tempBest = INT_MAX;

  while(counter < visited.size())
  {
    nextOne = -1;
    tempBest = INT_MAX;

    for(j = 0; j < temporarySolution.size(); j++)
    {
      if(visited[j] == 0 && tempBest > matrix -> getConnection(i, j))
      {
        tempBest = matrix -> getConnection(i, j);
        nextOne = j;
      }
    }

    visited[nextOne] = 1;
    temporarySolution[counter] = nextOne;
    i = nextOne;
    counter++;
  }

  return temporarySolution;
}

double Algorithm::RandomFromZeroToOne()
{
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> randomValue(0.0, 1.0);

  return randomValue(gen);
}


void Algorithm::DisplaySolution()
{
  for(int value : _bestPath)
  {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

double Algorithm::getBestDist() { return _bestDist; }

std::vector<int> Algorithm::getBestPath() { return _bestPath; }
