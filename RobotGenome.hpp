#ifndef _ROBOTGENOME_CPP
#define _ROBOTGENOME_CPP

#define NUM_LAYERS 2
#define LAYERA_NEURONS 5
#define LAYERB_NEURONS 2
#define NUM_INPUTS 2
#define NUM_OUTPUTS 2

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif
#include "Robot.hpp"

class RobotGenome : Genome
{
		int numberOfNeuronsInLayers[NUM_LAYERS];
		double* weights; //length is the sum of the number of links between layers
				// number of links = neurons in first layer * neurons in second layer
		public:
			~RobotGenome() {}
			RobotGenome();
			RobotGenome(double w[]);
			Robot getIndividual();
			int* getShape();
			double* getWeights();
			int numOfInputs();
			int numOfOutputs();
		private:
			double* initRandom();
};


#endif // _ROBOTGENOME_CPP
