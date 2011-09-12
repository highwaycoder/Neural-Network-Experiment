#define SIZE_OF_POPULATION 4
#define NUMBER_OF_GENERATIONS 50
#define NUMBER_OF_TICKS 1000

int main(void)
{
	Population pop = new Population(new RobotGenome(), SIZE_OF_POPULATION);
	for(NUMBER_OF_GENERATIONS):
		pop.simulate(NUMBER_OF_TICKS)
		pop.nextGeneration()
	
	RobotGenome g = pop.currentGenome()
	
	return 0;
}
