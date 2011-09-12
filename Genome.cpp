class Genome
{
		// virtual Individual getIndividual() = 0;
		virtual int* getShape() = 0;
		virtual double* getWeights() = 0;
		virtual int numOfInputs() = 0;
		virtual int numOfOutputs() = 0;
};
