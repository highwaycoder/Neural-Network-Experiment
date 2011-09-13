#include "Item.hpp"

MapItem::MapItem(int xpos, int ypos, Item item)
{
	
}
int MapItem::getXPos()
{
	return xpos;
}
int MapItem::getYPos()
{
	return ypos;
}

Item MapItem::getItem()
{
	return item;
}

void MapItem::setItem(Item to)
{
	item = to;
}
