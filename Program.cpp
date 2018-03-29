#include "Program.h"

void Program::Run() {
	MatrixGraph graph = MatrixGraphBuilder.Generate(20, true, 1, 20);
	graph.ToString();
}
