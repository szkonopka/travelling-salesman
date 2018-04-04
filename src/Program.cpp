#include "Program.h"

void Program::Run() {
	std::cout << "Odpalam program" << std::endl;
	MatrixGraph graph = MatrixGraph::Generate(200, true, 1, 200);

	std::cout << "Adres w Program: " << &graph << std::endl;
	GeneticAlgorithm *ga = new GeneticAlgorithm(&graph, 0.2, 0.8);
	ga->SearchForBestPath();
}
