#include "Population.hpp"

void Population::simulate(int numberOfTicks)
{
	
}
//perform reproduction and mutation to get a new array of individuals
void Population::nextGeneration()
{
	
}
Genome Population::getCurrentGenome()
{
	return currentGenome;
}
void Population::populate(Genome g, unsigned int size)
{
	unsigned int i=0;
	while(i<size)
	{
		individuals[i] = g.getIndividual();
		i++;
	}
}
Population::Population(Genome g,unsigned int size)
{
	populate(g,size);
}
