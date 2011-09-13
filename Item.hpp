#ifndef _ITEM_H
#define _ITEM_H

enum Item {
	WALL,
	MINE,
	ROBOT,
	EMPTY
};


class MapItem
{
	int xpos; 
	int ypos;
	Item item;
	public:
		MapItem(int xpos, int ypos, Item item);
		int getXPos();
		int getYPos();
		Item getItem();
		void setItem(Item to);
};

#endif // _ITEM_H
