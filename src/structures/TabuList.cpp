#include "TabuList.h"

void TabuList::DecreaseTenure()
{
  for(int i = 0; i < _matrix.size(); i++)
  {
    for(int j = 0; j < _matrix.size(); j++)
    {
      if(_matrix[i][j] > 0)
      {
        _matrix[i][j] -= 1;
        _matrix[j][i] -= 1;
      }
    }
  }
}

void TabuList::IncreaseTenure(int from, int to)
{
  _matrix[from][to] += _tenure;
  _matrix[to][from] += _tenure;
}
