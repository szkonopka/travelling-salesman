#pragma once
#include <vector>

enum MutationType {
  Invert, Insert, Swap
};

class Metaheuristic
{
public:
  void Swap(std::vector<int> &individual, int indexA, int indexB);
  void Insert(std::vector<int> &individual, int indexA, int indexB);
  void Invert(std::vector<int> &individual, int indexA, int indexB);
};
