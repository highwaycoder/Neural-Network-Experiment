#include <stdlib.h>
#include <time.h>
#include "Genome.cpp"
#define NUM_LAYERS 2
#define LAYERA_NEURONS 5
#define LAYERB_NEURONS 2
#define NUM_INPUTS 2
#define NUM_OUTPUTS 2

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

class RobotGenome : Genome
{
		int numberOfNeuronsInLayers[NUM_LAYERS];
		double* weights; //length is the sum of the number of links between layers
				// number of links = neurons in first layer * neurons in second layer
		public:
			RobotGenome()
			{
				weights = initRandom();
			}
			RobotGenome(double w[])
			{
				weights = w;
			}
			Robot getIndividual()
			{
				return new Robot();
			}
			int* getShape()
			{
				numberOfNeuronsInLayers[0] = LAYERA_NEURONS;
				numberOfNeuronsInLayers[1] = LAYERB_NEURONS;
				return numberOfNeuronsInLayers;
			}
			double* getWeights()
			{
				return weights;
			}
			int numOfInputs()
			{
				return NUM_INPUTS;
			}
			int numOfOutputs()
			{
				return NUM_OUTPUTS;
			}
		private:
			double* initRandom()
			{
				int i;
				double* rv;
				srand(time(NULL));
				for(i=0;i < (NUM_INPUTS*LAYERA_NEURONS)+(LAYERA_NEURONS*LAYERB_NEURONS);i++)
				{
					rv[i] = (drand48()*2)-1;
				}
				return rv;
			}
};


