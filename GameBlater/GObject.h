#ifndef __GOBJECT_H__
#define __GOBJECT_H__
#pragma once

#include "Utils.h"

class GObject
{
protected:
	char m_sprite;
	GPoint2D m_pos;
	int m_moveX, m_moveY;

public:
	GObject();
	GObject(char sprite, int posX, int posY, int moveX,int moveY);
	int GetPosX();
	void SetPosX(int posX);
	int GetPosY();
	void SetPosY(int posY);
	GRectangle GetCollision();
	virtual void Update();
	virtual void Render();
	~GObject();
};

#endif