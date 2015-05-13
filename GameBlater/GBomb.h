#ifndef __GBOMB_H__
#define __GBOMB_H__
#pragma once

#include "gobject.h"

#define ANIMATERATE_BOMB 2

class GBomb :
	public GObject
{
private:
	GColors m_colorBody;
	int m_lengthBomb;
	int m_timeLive;

	//các biến dùng cho hàm IsElapsedBomb
	long m_lastTickTime;
	long m_currentTickTime;
public:
	GBomb();
	GBomb(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody, int lengthBomb);
	int GetLengthBomb();
	void SetLengthBomb(int lengthBomb);
	int GetTimeLive();
	void SetTimeLive(int timeLive);
	bool IsElapsedBomb(long elapsedMilisecond);
	virtual void Update();
	virtual void Render();
	~GBomb();
};

#endif

