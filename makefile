Main: Main.o Program.o MainGraph.o MainGraphBuilder.o
	g++ Main.o Program.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Program.o: Program.cpp
	g++ -c Program.cpp

MainGraph.o: structures/MainGraph.cpp
	g++ -c MainGraph.cpp

MainGraphBuilder.o: structures/MainGraphBuilder.cpp
	g++ -c MainGraphBuilder.cpp -std=c11
