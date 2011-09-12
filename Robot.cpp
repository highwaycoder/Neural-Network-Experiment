#include <math.h>

enum REWARD_SYSTEM {
	SOUGHT_REWARD = 1,
	MOVE_PENALTY = 1,
	CRASHED_PENALTY = 5
};

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
		Robot(MapSimulation map, NeuralNetwork net)
		{
			
		}
		void tick()
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
				map.setItemAt(xpos,ypos,ROBOT);
				map.setItemAt(oldx,oldy,EMPTY);
			}
			else
			{
				score -= MOVE_PENALTY;
			}
		}
		bool isItemSought(int item)
		{
			int i;
			for(i=0;i<sizeof(seeking)/sizeof(seeking[0]);i++)
			{
				if(item==seeking[i]) return 1;
			}
			return 0;
		}
		Genome mate(Robot partner)
		{
			// allowing genetic recombination (faster, more efficient evolution)
			
		}
}
