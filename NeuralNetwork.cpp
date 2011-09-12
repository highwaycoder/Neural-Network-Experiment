class Neuron
{
	private:
		double myWeights[];
		int myNumOfWeights;
	public:
		Neuron(const double weights[],int numOfWeights)
		{
			int i;
			for(i=0;i<numOfWeights;i++)
			{
				myWeights[i] = weights[i];
			}
			myNumOfWeights = numOfWeights;
		}
		double tick(double input[])
		{
			int i;
			double rv;
			for(i=0;i<myNumOfWeights;i++)
			{
				rv += input[i]*myWeights[i];
			}
			return rv;
		}
}

class NeuronLayer
{
	private:
		Neuron neurons[];
		int myNumNeurons;
	public:
		NeuronLayer(int numNeurons,const double weights[],int numWeights)
		{
			int i;
			for(i=0;i<numNeurons;i++)
			{
				neurons[i] = Neuron(weights+(i*(numWeights/numNeurons)),numWeights/numNeurons);
			}
			myNumNeurons = numNeurons;
		}
		double* tick(double* input)
		{
			int i;
			double* output;
			for(i=0;i<myNumNeurons;i++)
			{
				output[i] = neurons[i].tick(input);
			}
			return output;
		}
}

class NeuralNet
{
		private:
			NeuronLayer layers[];
			int numberOfLayers;
		public:
			NeuralNet(Genome g)
			{
				int[] shape = g.getShape();
				double[] weights = g.getWeights();
				int i,weightsIndex=0,numOfWeights=0;
				numberOfLayers = sizeof(shape) / sizeof(shape[0]);
				for(i=0;i<numberOfLayers;i++)
				{
					numOfWeights = i==0?shape[i]*g.numOfInputs():shape[i]*shape[i-1];
					NeuronLayer[i] = new NeuronLayer(shape[i],weights[weightsIndex],numOfWeights);
					weightsIndex += numOfWeights;
				}
			}
		
			double* tick(double* input)
			{
				int i;
				for(i=0;i<numberOfLayers;i++)
				{
					input = layers[i].tick(input);
				}
				return input;
			} //call tick for each layer in turn passing result layer to layer
}




