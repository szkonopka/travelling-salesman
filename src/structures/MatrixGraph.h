#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class MatrixGraph {
private:
	std::vector<std::vector<int> > _matrix;
	void setConnection(int from, int to, int cost);
	void addVertex();
public:
	static MatrixGraph Generate(const int vertexAmount, const bool symetric, const int minValue, const int maxValue);
	MatrixGraph() {}
	void ToString();
	int getMatrixSize();
	int getConnection(int from, int to);
};
