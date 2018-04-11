#include <vector>

class TabuList
{
private:
  int _tenure;
  int _citiesAmount;
  std::vector<std::vector<int>> _matrix;
  void _initMatrix();
public:
  TabuList() { }
  TabuList(int tenure, int citiesAmount)
  {
    _tenure = tenure;
    _citiesAmount = citiesAmount;
    _initMatrix();
  }
  void DecreaseTenure();
  void IncreaseTenure(int from, int to);
  int getMoveTenure(int from, int to);
};
