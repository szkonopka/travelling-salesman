#include <vector>
#include <iostream>

class MatrixGraph {
private:
	std::vector<std::vector<int> > _matrix;
	void setConnection();
	void addVertex();
public:
	MatrixGraph() {}
	void ToString();
};
