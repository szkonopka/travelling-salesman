#include "Algorithm.h"

int Algorithm::getPivot(int size) {
  return size / 2;
}

int Algorithm::getRandNumbBeforePivot(int pivot) {
  return rand() % pivot + 0;
}

int Algorithm::getRandomNumbAfterPivot(int pivot) {
  return rand() % pivot + pivot;
}

int Algorithm::CalculateDistance(std::vector<int> order) {
  int distance = 0, i;
  for(i = 0; i < order.size() - 1; i++) {
    distance += matrix->getConnection(order[i], order[i + 1]);
  }
  distance += matrix->getConnection(order[i], 0);
  return distance;
}

void Algorithm::Swap(std::vector<int> &individual, int indexA, int indexB) {
  if(indexA == indexB)
    return;

  int tmp = individual[indexA];
  individual[indexA] = individual[indexB];
  individual[indexB] = tmp;
}

std::vector<int> Algorithm::Insert(std::vector<int> individual, int indexA, int indexB) {

}

std::vector<int> Algorithm::Invert(std::vector<int> individual, int indexA, int indexB) {

}