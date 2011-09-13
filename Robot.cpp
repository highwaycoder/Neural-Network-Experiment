#include <math.h>
#include "Individual.hpp"
#include "Genome.hpp"
#include "NeuralNetwork.hpp"
#include "MapSimulation.hpp"
#include "Robot.hpp"
#include "RobotGenome.hpp"



Robot::Robot(MapSimulation map, NeuralNetwork net)
{
	
}
Robot::void tick()
{
	double* output;
	double* input;
	input[0] = strobeSensor;
	input[1] = wallSensor;
	// call neuralNet.tick() and update world, xpos, ypos, score
	output = neuralNet.tick(input);
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
	int i;
	for(i=0;i<sizeof(seeking)/sizeof(seeking[0]);i++)
	{
		if(item==seeking[i]) return 1;
	}
	return 0;
}
Genome Robot::mate(Robot partner)
{
	// allowing genetic recombination (faster, more efficient evolution)
	
}
void Robot::runtimeError(Error_t errorType)
{
	switch(errorType)
	{
		case E_CANTSETITEM:
			printf("Error: Can't set item at <unknown location> because the cell probably doesn't exist");
			break;
	}
}
void Robot::runtimeError(Error_t errorType,int arg1, int arg2)
{
	switch(errorType)
	{
		case E_CANTSETITEM:
			printf("Error: Can't set item at %d, %d because the cell probably doesn't exist",arg1,arg2);
			break;
	}
}
