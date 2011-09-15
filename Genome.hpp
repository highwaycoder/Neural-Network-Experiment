#ifndef _GENOME_H
#define _GENOME_H
#include "Individual.hpp"

class Genome
{
		public:
			Genome(){};
			virtual void getIndividual(Individual *dst){};
			virtual int* getShape(){};
			virtual double* getWeights(){};
			virtual int numOfInputs(){};
			virtual int numOfOutputs(){};
};

#endif // _GENOME_H
