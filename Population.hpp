#include "Genome.hpp"
#include "Individual.hpp"

class Population
{
	private:
		Individual indivuduals[];
	public:
		void simulate(int numberOfTicks);
		void nextGeneration(); //perform reproduction and mutation to get a new array of individuals
		Genome currentGenome();
		Population(Genome g,unsigned int size);
};
