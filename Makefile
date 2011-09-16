CC=g++
LDFLAGS=
CXXFLAGS=
# IMPORTANT: PRESERVE ORDER
OBJS=RobotGenome.o NeuralNetwork.o Robot.o Population.o Item.o MapSimulation.o

robotTester: main.cpp $(OBJS)
	$(CC) $(LDFLAGS) -o robotTester main.cpp $(OBJS)

%.o: %.cpp %.hpp
	$(CC) $(CXXFLAGS) -o $*.o -c $*.cpp

clean:
	@rm -f $(OBJS)
	@rm -f robotTester
	@rm -f main.o

clean-geany:
	@rm -f *.gch
