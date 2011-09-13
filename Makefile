CC=g++
LDFLAGS=
CXXFLAGS=
# IMPORTANT: PRESERVE ORDER
OBJS=Individual.o Robot.o Genome.o RobotGenome.o NeuralNetwork.o

robotTester: main.cpp $(OBJS)
	$(CC) $(LDFLAGS) -o robotTester main.cpp $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $*.o -c $*.cpp
