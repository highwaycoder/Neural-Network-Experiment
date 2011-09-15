#include "Genome.hpp"
#include "Individual.hpp"

class Population
{
	private:
		Individual individuals[];
		Genome* currentGenome;
	public:
		void simulate(int numberOfTicks);
		void nextGeneration(); //perform reproduction and mutation to get a new array of individuals
		Genome* getCurrentGenome();
		Population(Genome* g,unsigned int size);
		void populate(Genome* g, unsigned int size);
};
