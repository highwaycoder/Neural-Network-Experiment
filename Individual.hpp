#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H

class Individual
{
		public:
			// call neuralNet.tick() and update world, xpos, ypos, score
			virtual void tick() {};
			~Individual(){};
			Individual(){};
};

#endif // _INDIVIDUAL_H
