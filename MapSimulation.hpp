#ifndef _MAPSIMULATION_H
#define _MAPSIMULATION_H
#include "Item.hpp"

// completely arbitrary, 'real-world' code should use custom values
#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 100

class MapSimulation
{
		MapItem* items;
		public:
			Item getItemAt(int x,int y);
			bool setItemAt(int x,int y, Item item);
			MapSimulation();
			MapSimulation(int width, int height);
};

#endif // _MAPSIMULATION_H
