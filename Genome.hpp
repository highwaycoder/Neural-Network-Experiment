#ifndef _GENOME_H
#define _GENOME_H
#include "Individual.hpp"

class Genome
{
		virtual Individual getIndividual();
		virtual int* getShape();
		virtual double* getWeights();
		virtual int numOfInputs();
		virtual int numOfOutputs();
		public:
			Genome(){};
			virtual ~Genome(){};
};

#endif // _GENOME_H
