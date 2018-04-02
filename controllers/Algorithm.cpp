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

int Algorithm::CalculateDistance(std::vector<std::vector<int> > matrix, int from, int to) {
  return matrix[from][to];
}
