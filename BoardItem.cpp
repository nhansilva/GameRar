#include "BoardItem.h"

CBoardItem::CBoardItem()
{
	x1 = 330;
	y1 = 40;
	whichItem = 0;
	dagger = new CIDagger(x1, y1, 32, 18);
}


CBoardItem::~CBoardItem()
{

}


void CBoardItem::Draw()
{

	switch (whichItem)
	{
	case 10:
	{
		dagger->Draw2();
	}break;
	default:
	{

	}break;

	}
}

