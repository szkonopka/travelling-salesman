SRC_DIR=./src
STRUCT_DIR=$(SRC_DIR)/structures
TSP_DIR=$(SRC_DIR)/tsp
OUT=Main
TEST_DIR=tests

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clear

Algorithm.o: $(TSP_DIR)/Algorithm.cpp $(TSP_DIR)/Algorithm.h
	g++ -c -I$(TSP_DIR) $(TSP_DIR)/Algorithm.cpp -std=c11

TabuSearchAlgorithm.o: $(TSP_DIR)/TabuSearchAlgorithm.cpp $(TSP_DIR)/TabuSearchAlgorithm.h
	g++ -c -I$(TSP_DIR) $(TSP_DIR)/TabuSearchAlgorithm.cpp -std=c11

GeneticAlgorithm.o: $(TSP_DIR)/GeneticAlgorithm.cpp $(TSP_DIR)/GeneticAlgorithm.h
	g++ -c -I$(TSP_DIR) $(TSP_DIR)/GeneticAlgorithm.cpp -std=c11

TabuList.o: $(STRUCT_DIR)/TabuList.cpp $(STRUCT_DIR)/TabuList.h
	g++ -c -I$(STRUCT_DIR) $(STRUCT_DIR)/TabuList.cpp -std=c11

MatrixGraph.o: $(STRUCT_DIR)/MatrixGraph.cpp $(STRUCT_DIR)/MatrixGraph.h
	g++ -c -I$(STRUCT_DIR) $(STRUCT_DIR)/MatrixGraph.cpp -std=c11

Program.o: $(SRC_DIR)/Program.cpp $(SRC_DIR)/Program.h
	g++ -c -I$(SRC_DIR) $(SRC_DIR)/Program.cpp

Main.o: $(SRC_DIR)/Main.cpp
	g++ -c -I$(SRC_DIR) $(SRC_DIR)/Main.cpp

Main: $(SRC_DIR)/Main.o $(SRC_DIR)/Program.o $(TSP_DIR)/GeneticAlgorithm.o $(TSP_DIR)/TabuSearchAlgorithm.o $(TSP_DIR)/Algorithm.o $(STRUCT_DIR)/MatrixGraph.o $(STRUCT_DIR)/TabuList.o
	g++ -I$(SRC_DIR) $(SRC_DIR)/Main.o $(SRC_DIR)/Program.o $(TSP_DIR)/GeneticAlgorithm.o $(TSP_DIR)/TabuSearchAlgorithm.o $(TSP_DIR)/Algorithm.o $(STRUCT_DIR)/MatrixGraph.o $(STRUCT_DIR)/TabuList.o -o $(OUT)

clean:
	rm *.o $(SRC_DIR)/*.o $(TSP_DIR)/*.o $(STRUCT_DIR)/*.o $(OUT)
