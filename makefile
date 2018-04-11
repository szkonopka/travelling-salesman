SRC_DIR=./src
STRUCT_DIR=$(SRC_DIR)/structures
TSP_DIR=$(SRC_DIR)/tsp
HELP_DIR=$(TSP_DIR)/helpers
INT_DIR=$(TSP_DIR)/interfaces
OUT=Main
TEST_DIR=tests

Main: $(SRC_DIR)/Main.o $(SRC_DIR)/Program.o $(TSP_DIR)/GeneticAlgorithm.o $(TSP_DIR)/TabuSearchAlgorithm.o $() $(TSP_DIR)/Algorithm.o $(HELP_DIR)/Metaheuristic.o $(STRUCT_DIR)/MatrixGraph.o $(STRUCT_DIR)/TabuList.o $(ST)
	g++ -I$(SRC_DIR) $(SRC_DIR)/Main.o $(SRC_DIR)/Program.o $(TSP_DIR)/GeneticAlgorithm.o $(TSP_DIR)/TabuSearchAlgorithm.o $(TSP_DIR)/Algorithm.o $(HELP_DIR)/Metaheuristic.o $(STRUCT_DIR)/MatrixGraph.o $(STRUCT_DIR)/TabuList.o -o $(OUT)

clean:
	rm *.o $(SRC_DIR)/*.o $(TSP_DIR)/*.o $(STRUCT_DIR)/*.o $(HELP_DIR)/*.o $(OUT)
