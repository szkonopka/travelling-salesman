#include "Program.h"

void Program::Run() {
	std::cout << "Odpalam program" << std::endl;
	MatrixGraph graph = MatrixGraph::Generate(200, true, 1, 200);
	Algorithm *alg;

	alg = new GeneticAlgorithm(&graph, 0.2, 0.8);
	//alg = new TabuSearchAlgorithm(&graph);
	alg->SearchForBestPath();
}
