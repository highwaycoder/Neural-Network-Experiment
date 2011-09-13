#ifndef _ROBOT_H
#define _ROBOT_H

class Robot : Individual
{
	private:
		int xpos;
		int ypos;
		double strobeSensor; // radar/sonar sensor that can tell us how close we are to a seekable
		double wallSensor; // lidar sensor that can tell us what is directly in front of the robot (and how far away it is)
		NeuralNet neuralNet;
		int score; //updated after every tick with -n for crashes and +m for sought objects
		MapSimulation map;
		Item* seeking;
		Item* avoiding;
		int leftMotorSpeed;
		int rightMotorSpeed;
		int heading;
	public:
		Robot(MapSimulation map, NeuralNetwork net);
		void tick();
		bool isItemSought(int item);
		Genome mate(Robot partner);
};

#endif // _ROBOT_H
