#include "Population.hpp"
#include "RobotGenome.hpp"

#define SIZE_OF_POPULATION 4U
#define NUMBER_OF_GENERATIONS 50
#define NUMBER_OF_TICKS 1000

int main(void)
{
	int i=0;
	Population pop = Population(RobotGenome(), SIZE_OF_POPULATION);
	for(i=0;i<NUMBER_OF_GENERATIONS;i++)
	{
		pop.simulate(NUMBER_OF_TICKS);
		pop.nextGeneration();
	}
	
	// what is the below line for?
	// RobotGenome g = pop.getCurrentGenome();
	
	return 0;
}
