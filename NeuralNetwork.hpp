#ifndef _NEURALNET_H
#define _NEURALNET_H
#include "Genome.hpp"

class Neuron
{
	private:
		double myWeights[];
		int myNumOfWeights;
	public:
		Neuron(const double weights[],int numOfWeights);
		double tick(double input[]);
};

class NeuronLayer
{
	private:
		Neuron neurons[];
		int myNumNeurons;
	public:
		NeuronLayer(int numNeurons,const double weights[],int numWeights);
		void tick(double* input,double* output);
};

class NeuralNet
{
		private:
			NeuronLayer layers[];
			int numberOfLayers;
		public:
			NeuralNet();
			NeuralNet(Genome* g);
		
			void tick(double* input,double* output);
};




#endif // _NEURALNET_H
