#include "Metaheuristic.h"
#include <algorithm>

void Metaheuristic::Swap(std::vector<int> &individual, int indexA, int indexB)
{
  if(indexA == indexB)
    return;

  int tmp = individual[indexA];
  individual[indexA] = individual[indexB];
  individual[indexB] = tmp;
}

void Metaheuristic::Insert(std::vector<int> &individual, int indexA, int indexB) {
  if(indexA == indexB)
    return;

  if(indexA < indexB)
  {
    individual.insert(individual.begin() + indexA, individual[indexB]);
    individual.erase(individual.begin() + indexB + 1);
  }
  else
  {
    individual.insert(individual.begin() + indexB, individual[indexA]);
    individual.erase(individual.begin() + indexA + 1);
  }
}

void Metaheuristic::Invert(std::vector<int> &individual, int indexA, int indexB)
{
  if(indexA == indexB)
    return;

  std::reverse(individual.begin() + indexA, individual.begin() + indexB);
}
