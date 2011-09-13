#ifndef _GENOME_H
#define _GENOME_H

class Genome
{
		
		virtual Individual getIndividual() = 0;
		virtual int* getShape() = 0;
		virtual double* getWeights() = 0;
		virtual int numOfInputs() = 0;
		virtual int numOfOutputs() = 0;
		public:
			virtual ~Genome(){};
};

#endif // _GENOME_H
