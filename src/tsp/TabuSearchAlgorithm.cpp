#include "TabuSearchAlgorithm.h"

void TabuSearchAlgorithm::SearchForBestPath()
{
  std::vector<int> optimalPath;
  double optimalDist;
  double optimalPathFitness;

  InitSolution();

  optimalPath = _bestPath;
  optimalDist = _bestDist;
  int iterationNumber = 0;
  for(int i = 0; i < _stepsAmount; i++)
  {
    optimalPath = NewNeighborhood(optimalPath);

    if(iterationNumber >= _criticalIterations)
    {
      Diversification(optimalPath, i);
      iterationNumber = 0;
    }

    optimalDist = CalculateDistance(optimalPath);
    if(optimalDist < _bestDist)
    {
      _bestDist = optimalDist;
      _bestPath = optimalPath;
      std::cout << optimalDist << std::endl;
    }
    else
    {
      iterationNumber++;
    }
  }
}

void TabuSearchAlgorithm::InitSolution()
{
  for(int i = 0; i < matrix -> getMatrixSize(); i++)
  {
    _bestPath.push_back(i);
  }

  _bestPath = GreedySolution();
  _bestDist = CalculateDistance(_bestPath);
}

std::vector<int> TabuSearchAlgorithm::NewNeighborhood(std::vector<int> solution)
{
  std::vector<int> temporarySolution = solution;
  std::vector<int> newSolution;
  double temporarySolutionFitness;

  int firstPrevented, secondPrevented;
  bool firstNeighbor = true;

  for(int i = 0; i < solution.size(); i++)
  {
    for(int j = 0; j < solution.size(); j++)
    {
      if(i == j)
        continue;

      switch(_mutationType)
      {
        case MutationType::Invert:
          Invert(temporarySolution, i, j);
          break;
        case MutationType::Insert:
          Insert(temporarySolution, i, j);
          break;
        case MutationType::Swap:
          Swap(temporarySolution, i, j);
          break;
      }

      temporarySolutionFitness = CalculateFitness(solution, temporarySolution);
      _bestPathFitness = CalculateFitness(solution, solution);
      if(((temporarySolutionFitness > _bestPathFitness) || firstNeighbor) && !_tabuList -> getMoveTenure(i, j))
      {
        firstNeighbor = false;
        firstPrevented = i;
        secondPrevented = j;
        newSolution = temporarySolution;
      }
    }
  }

  if(firstPrevented != 0)
  {
    _tabuList -> DecreaseTenure();
    _tabuList -> IncreaseTenure(firstPrevented, secondPrevented);
  }

  return newSolution;
}

void TabuSearchAlgorithm::Diversification(std::vector<int> &solution, int i)
{
  std::random_shuffle(solution.begin(), solution.end());
}

double TabuSearchAlgorithm::CalculateFitness(std::vector<int> x, std::vector<int> y)
{
  return CalculateDistance(x) - CalculateDistance(y);
}
