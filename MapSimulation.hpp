#ifndef _MAPSIMULATION_H
#define _MAPSIMULATION_H
#include "Item.hpp"
class MapSimulation
{
		MapItem* items;
		Item getItemAt(int x,int y);
		bool setItemAt(int x,int y, Item item);
		MapSimulation(int width, int height);
};

#endif // _MAPSIMULATION_H
