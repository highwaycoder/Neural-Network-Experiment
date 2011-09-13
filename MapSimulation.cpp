#include "MapSimulation.hpp"

Item MapSimulation::getItemAt(int x,int y)
{
	unsigned int i=0;
	while(i<sizeof(items)/sizeof(items[0]))
	{
		if((items[i].getXPos() == x) && (items[i].getYPos() == y))
			return items[i].getItem();
	}
	return EMPTY;
}
bool MapSimulation::setItemAt(int x,int y, Item item)
{
	unsigned int i=0;
	bool success = false;
	while(i<sizeof(items)/sizeof(items[0]))
	{
		if((items[i].getXPos() == x) && (items[i].getYPos() == y))
		{
			items[i].setItem(item);
			success = true;
		}
		i++;
	}
	return success;
}
MapSimulation::MapSimulation(int width, int height)
{
	
}
MapSimulation::MapSimulation()
{
	MapSimulation(DEFAULT_WIDTH,DEFAULT_HEIGHT);
}
