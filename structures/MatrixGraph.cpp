#include "MatrixGraph.h"

void MatrixGraph::setConnection(int pointA, int pointB, int cost) {
	_matrix[pointA][pointB] = cost;
}

void MatrixGraph::addVertex() {
	if(_matrix.empty()) {
		std::vector<int> temporary(1, 0);
		_matrix.push_back(temporary);
	} else {
		for(std::vector<int> row : _matrix) {
			row.push_back(0);
		}
	}
	std::vector<int> temporary(_matrix.size() + 1, 0);
	_matrix.push_back(temporary);
}

void MatrixGraph::ToString() {
	for(std::vector<int> row : _matrix) {
		for(int value : row) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}
