# NB: this makefile does not use header dependancies
# this is a major issue which will be addressed in future versions.
CC=g++
LDFLAGS=
CXXFLAGS=
# IMPORTANT: PRESERVE ORDER
OBJS=Robot.o RobotGenome.o NeuralNetwork.o MapSimulation.o Population.o Item.o

robotTester: main.cpp $(OBJS)
	$(CC) $(LDFLAGS) -o robotTester main.cpp $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $*.o -c $*.cpp
