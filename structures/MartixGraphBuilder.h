#include <memory>

class MatrixGraphBuilder {
public:
	static MatrixGraph Generate(const int vertexAmount, const bool symetric, const int minValue, const int maxValue) {
		std::unique_ptr<MatrixGraph> tempGraph(new MatrixGraph());
		int tempValue = 0;

		if(symetric) {
			for(int i = 0; i < vertexAmount; i++) {
				tempGraph.addVertex();
				for(int j = i; j < vertexAmount; j++) {
					if(i != j) {
						tempValue = rand() * maxValue + minValue;
						tempGraph.setConnection(i, j, tempValue);
						tempGraph.setConnection(j, i, tempValue);
					} else {
						tempGraph.setConnection(i, j, 0);
					}
				}
			}
		} else {
			for(int i = 0; i < vertexAmount; i++) {
				tempGraph.addVertex();
				for(int j = 0; j < vertexAmount; j++) {
					if(i != j) {
						tempValue = rand() * maxValue + minValue;
						tempGraph.setConnection(i, j, tempValue);
					} else {
						tempGraph.setConnection(i, j, 0);
					}
				}
			}
		}
		return tempGraph;
	}
};
