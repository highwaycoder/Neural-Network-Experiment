#ifndef _ROBOT_H
#define _ROBOT_H
#include "MapSimulation.hpp"
#include "NeuralNetwork.hpp"
#include "Item.hpp"
#include "Genome.hpp"
#include "Individual.hpp"

enum Error_t {
	E_CANTSETITEM,
};

enum Score_Modifier_t {
	MOVE_PENALTY=1,
	SOUGHT_REWARD=1,
	CRASHED_PENALTY=5
};

class Robot : public Individual
{
	private:
		int xpos;
		int ypos;
		double strobeSensor; // radar/sonar sensor that can tell us how close we are to a seekable
		double wallSensor; // lidar sensor that can tell us what is directly in front of the robot (and how far away it is)
		NeuralNet *neuralNet;
		int score; //updated after every tick with -n for crashes and +m for sought objects
		MapSimulation *map;
		Item* seeking;
		Item* avoiding;
		int leftMotorSpeed;
		int rightMotorSpeed;
		int heading;
	public:
		Robot(MapSimulation *map, NeuralNet *net);
		void tick();
		bool isItemSought(int item);
		Genome mate(Robot partner);
		void runtimeError(Error_t errorType);
		void runtimeError(Error_t errorType, int arg1, int arg2);
};

#endif // _ROBOT_H
