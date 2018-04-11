#include <vector>

class TabuList
{
private:
  int _tenure;
  int _citiesAmount;
  std::vector<std::vector<int>> _matrix;
public:
  void DecreaseTenure();
  void IncreaseTenure(int from, int to);
};
