#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H

class Individual
{
		// call neuralNet.tick() and update world, xpos, ypos, score
		virtual void tick() {};
		virtual ~Individual(){};
		Individual(){};
};

#endif // _INDIVIDUAL_H
