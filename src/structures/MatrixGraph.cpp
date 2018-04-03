#include "MatrixGraph.h"

MatrixGraph MatrixGraph::Generate(const int vertexAmount, const bool symetric, const int minValue, const int maxValue) {
	srand(time(NULL));
	std::cout << "Tworzenie grafu" << std::endl;
	MatrixGraph tempGraph;
	int tempValue = 0;

	for(int i = 0; i < vertexAmount; i++) {
		tempGraph.addVertex();
	}

	if(symetric) {
		for(int i = 0; i < vertexAmount; i++) {
			for(int j = 0; j < vertexAmount; j++) {
				if(i != j) {
					tempValue = std::rand() % maxValue + minValue;
					tempGraph.setConnection(i, j, tempValue);
					tempGraph.setConnection(j, i, tempValue);
				} else {
					tempGraph.setConnection(i, j, 0);
				}
			}
		}
	} else {
		for(int i = 0; i < vertexAmount; i++) {
			for(int j = 0; j < vertexAmount; j++) {
				if(i != j) {
					tempValue = std::rand() % maxValue + minValue;
					tempGraph.setConnection(i, j, tempValue);
				} else {
					tempGraph.setConnection(i, j, 0);
				}
			}
		}
	}
	std::cout << "Zwracam graf" << std::endl;
	return tempGraph;
}

void MatrixGraph::setConnection(int from, int to, int cost) {
	_matrix[from][to] = cost;
}

void MatrixGraph::addVertex() {
	for(std::vector<int> &row : _matrix) {
		row.push_back(0);
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

int MatrixGraph::getMatrixSize() {
	return _matrix.size();
}

int MatrixGraph::getConnection(int from, int to) {
	return _matrix[from][to];
}
