void TabuSearchAlgorithm::SearchForBestPath()
{
  std::vector<std::vector<int> > optimalPath;
  double optimalDist;
  double optimalPathFitness;

  InitSolution();

  for(int i = 0; i < _stepsAmount; i++)
  {
    NewNeighborhood();
    if(optimalPathFitness > _bestPathFitness)
    {

    }
  }
}

void NewNeighborhood(std::vector<std::vector<int>> solution)
{
  std::vector<std::vector<int>> newSolution = solution;
  double newSolutionFitness;
  int firstPrevented, secondPrevented;

  for(int i = 0; i < this->getMatrixSize(); i++)
  {
    for(int j = 0; j < this->getMatrixSize(); j++)
    {
      if(i == j)
        continue;

      switch(NeighborType)
      {
        case NeighborType::Invert:
          Invert(&newSolution, i, j);
          break;
        case NeighborType::Insert:
          Insert(&newSolution, i, j);
          break;
        case NeighborType::Swap:
          Swap(&newSolution, i, j);
          break;
      }
    }

    generatedIndividualFitness = CalculateFitness(solution, newSolution);

  }
}

void InitSolution()
{

}

void Diversification()
{

}

void CalculateFitness()
{

}
