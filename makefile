Main: Main.o Program.o ./controllers/GeneticAlgorithm.o ./controllers/Algorithm.o ./structures/MatrixGraph.o
	g++ Main.o Program.o ./controllers/GeneticAlgorithm.o ./controllers/Algorithm.o ./structures/MatrixGraph.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Program.o: Program.cpp Program.h
	g++ -c Program.cpp

MatrixGraph.o: ./structures/MatrixGraph.cpp ./structures/MatrixGraph.cpp
	g++ -c ./structures/MatrixGraph.cpp -std=c11

GeneticAlgorithm.o: ./controllers/GeneticAlgorithm.cpp ./controllers/GeneticAlgorithm.h
	g++ -c ./controllers/GeneticAlgorithm.cpp ./controllers/GeneticAlgorithm.h -std=c11

Algorithm.o: ./controllers/Algorithm.cpp ./controllers/Algorithm.h
	g++ -c ./controllers/Algorithm.cpp -std=c11
