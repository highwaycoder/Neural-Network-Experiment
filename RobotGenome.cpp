#include <stdlib.h>
#include <time.h>
#include "Genome.hpp"
#include "Individual.hpp"
#include "NeuralNetwork.hpp"
#include "Robot.hpp"
#include "RobotGenome.hpp"
#include "MapSimulation.hpp"

RobotGenome::~RobotGenome() 
{
	
}
RobotGenome::RobotGenome()
{
	initRandom(weights);
}
RobotGenome::RobotGenome(double w[])
{
	weights = w;
}
Robot *RobotGenome::getIndividual(MapSimulation map)
{	
	NeuralNet net(this);
	return new Robot(map,net);
}
int* RobotGenome:: getShape()
{
	numberOfNeuronsInLayers[0] = LAYERA_NEURONS;
	numberOfNeuronsInLayers[1] = LAYERB_NEURONS;
	return numberOfNeuronsInLayers;
}
double* RobotGenome::getWeights()
{
	return weights;
}
int RobotGenome::numOfInputs()
{
	return NUM_INPUTS;
}
int RobotGenome::numOfOutputs()
{
	return NUM_OUTPUTS;
}
void RobotGenome::initRandom(double* w)
{
	int i;
	srand(time(NULL));
	for(i=0;i < (NUM_INPUTS*LAYERA_NEURONS)+(LAYERA_NEURONS*LAYERB_NEURONS);i++)
	{
		w[i] = (drand48()*2)-1;
	}
}
