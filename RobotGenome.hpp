#ifndef _ROBOTGENOME_H
#define _ROBOTGENOME_H

#define NUM_LAYERS 2
#define LAYERA_NEURONS 5
#define LAYERB_NEURONS 2
#define NUM_INPUTS 2
#define NUM_OUTPUTS 2

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif
#include "Robot.hpp"
#include "Genome.hpp"
#include "MapSimulation.hpp"

class RobotGenome : public Genome
{
		int numberOfNeuronsInLayers[NUM_LAYERS];
		double* weights; //length is the sum of the number of links between layers
				// number of links = neurons in first layer * neurons in second layer
		public:
			~RobotGenome();
			virtual void getIndividual(MapSimulation map,Robot *dst);
			RobotGenome();
			RobotGenome(double w[]);
			virtual Robot *getIndividual();
			int* getShape();
			double* getWeights();
			int numOfInputs();
			int numOfOutputs();
		private:
			void initRandom(double* w);
};


#endif // _ROBOTGENOME_H
