#include "Genome.hpp"
#include "RobotGenome.hpp"
#include "Robot.hpp"


Neuron::Neuron(const double weights[],int numOfWeights)
{
	int i;
	for(i=0;i<numOfWeights;i++)
	{
		myWeights[i] = weights[i];
	}
	myNumOfWeights = numOfWeights;
}
double Neuron::tick(double input[])
{
	int i;
	double rv;
	for(i=0;i<myNumOfWeights;i++)
	{
		rv += input[i]*myWeights[i];
	}
	return rv;
}


NeuronLayer::NeuronLayer(int numNeurons,const double weights[],int numWeights)
{
	int i;
	for(i=0;i<numNeurons;i++)
	{
		neurons[i] = Neuron(weights+(i*(numWeights/numNeurons)),numWeights/numNeurons);
	}
	myNumNeurons = numNeurons;
}
double* NeuronLayer::tick(double* input)
{
	int i;
	double* output;
	for(i=0;i<myNumNeurons;i++)
	{
		output[i] = neurons[i].tick(input);
	}
	return output;
}

NeuralNet::NeuralNet(Genome* g)
{
	int* shape = g->getShape();
	double* weights = g->getWeights();
	int i,
		weightsIndex=0,
		numOfWeights=0;

	numberOfLayers = sizeof(shape) / sizeof(shape[0]);
	for(i=0;i<numberOfLayers;i++)
	{
		numOfWeights = i==0?shape[i]*g->numOfInputs():shape[i]*shape[i-1];
		
		layers[i] = NeuronLayer(shape[i],weights[weightsIndex],numOfWeights);
		weightsIndex += numOfWeights;
	}
}

// call tick for each layer in turn passing result layer to layer
double* NeuralNet::tick(double* input)
{
	int i;
	for(i=0;i<numberOfLayers;i++)
	{
		input = layers[i].tick(input);
	}
	return input;
} 
