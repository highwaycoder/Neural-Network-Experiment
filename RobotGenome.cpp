#include <stdlib.h>
#include <time.h>
#include "Genome.hpp"
#include "Individual.hpp"
#include "NeuralNetwork.hpp"
#include "Robot.hpp"
#include "RobotGenome.hpp"

RobotGenome::~RobotGenome() {}
RobotGenome::RobotGenome()
{
	weights = initRandom();
}
RobotGenome::RobotGenome(double w[])
{
	weights = w;
}
RobotGenome::Robot getIndividual()
{
	return new Robot();
}
RobotGenome::int* getShape()
{
	numberOfNeuronsInLayers[0] = LAYERA_NEURONS;
	numberOfNeuronsInLayers[1] = LAYERB_NEURONS;
	return numberOfNeuronsInLayers;
}
RobotGenome::double* getWeights()
{
	return weights;
}
RobotGenome::int numOfInputs()
{
	return NUM_INPUTS;
}
RobotGenome::int numOfOutputs()
{
	return NUM_OUTPUTS;
}
RobotGenome::double* initRandom()
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
