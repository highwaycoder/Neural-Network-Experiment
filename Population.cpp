#include "Population.hpp"

void Population::simulate(int numberOfTicks)
{
	unsigned int i=0,j=0;
	while(i<(sizeof(individuals)/sizeof(individuals[0]))
	&& j<numberOfTicks)
	{
		individuals[i].tick();
		if(i==(sizeof(individuals)/sizeof(individuals[0])-1))
		{
			i=0;j++;
		}
	}
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
		g.getIndividual(&individuals[i]);
	}
}
Population::Population(Genome g,unsigned int size)
{
	populate(g,size);
}
