#include <math.h>
#include <iostream>
#include "Individual.hpp"
#include "Genome.hpp"
#include "NeuralNetwork.hpp"
#include "MapSimulation.hpp"
#include "Robot.hpp"
#include "RobotGenome.hpp"
#include "Item.hpp"

using namespace std;

Robot::Robot(MapSimulation map, NeuralNet net)
{
	
}
void Robot::tick()
{
	double output[] = {0};
	double input[] = {strobeSensor,wallSensor};
	// call neuralNet.tick() and update world, xpos, ypos, score
	neuralNet.tick(input,output);
	leftMotorSpeed = output[0];
	rightMotorSpeed = output[1];
	heading += (rightMotorSpeed - leftMotorSpeed);
	while(heading>360) heading -= 360;
	while(heading<0) heading += 360;
	int oldx = xpos;
	int oldy = ypos;
	xpos += cos(heading/M_PI);
	ypos += sin(heading/M_PI);
	if(!(xpos==oldx && ypos==oldy))
	{
		if(map.getItemAt(xpos,ypos)==EMPTY)
		{
			score -= MOVE_PENALTY;
		}
		else if(isItemSought(map.getItemAt(xpos,ypos)))
		{
			score += SOUGHT_REWARD;
		}
		else if (map.getItemAt(xpos,ypos)==WALL)
		{
			score -= CRASHED_PENALTY;
			xpos = oldx;
			ypos = oldy;
		}
		else
		{
			score -= CRASHED_PENALTY;
		}
		if(!map.setItemAt(xpos,ypos,ROBOT))
			runtimeError(E_CANTSETITEM,xpos,ypos);
		if(!map.setItemAt(oldx,oldy,EMPTY))
			runtimeError(E_CANTSETITEM,xpos,ypos);
	}
	else
	{
		score -= MOVE_PENALTY;
	}
}
bool Robot::isItemSought(int item)
{
	unsigned int i;
	for(i=0;i<sizeof(seeking)/sizeof(seeking[0]);i++)
	{
		if(item==seeking[i]) return 1;
	}
	return 0;
}
// allow genetic recombination (faster, more efficient evolution)
Genome Robot::mate(Robot partner)
{
	Genome rv;
	// TODO: complete stub function
	return rv;
}
void Robot::runtimeError(Error_t errorType)
{
	switch(errorType)
	{
		case E_CANTSETITEM:
			cout << "Error: Can't set item at <unknown location> because the cell probably doesn't exist";
			break;
	}
}
void Robot::runtimeError(Error_t errorType,int arg1, int arg2)
{
	switch(errorType)
	{
		case E_CANTSETITEM:
			cout << "Error: Can't set item at " << arg1 << ", " << arg2 << " because the cell probably doesn't exist";
			break;
	}
}
