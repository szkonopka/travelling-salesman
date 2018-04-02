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
    distance += matrix->getConnection(i, i + 1);
  }
  distance += matrix->getConnection(i, 0);
  return distance;
}
