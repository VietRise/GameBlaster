#ifndef __GBRICK_H__
#define __GBRICK_H__
#pragma once

#include "gobject.h"

class GBrick :
	public GObject
{
private:	
	GColors m_colorBody;
	GGiftType m_containTypeGift;
public:
	GBrick();
	GBrick(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody, GGiftType containTypeGift);	
	GGiftType GetContainTypeGift();
	void SetContainTypeGift(GGiftType containTypeGift);
	virtual void Update();
	virtual void Render();
	~GBrick();
};

#endif

