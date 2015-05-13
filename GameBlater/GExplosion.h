#ifndef __GEXPLOSION_H__
#define __GEXPLOSION_H__
#pragma once

#include "gobject.h"

#define TIMELIVE_EXPLOSION 700 // Milisecond

class GExplosion :
	public GObject
{
private:
	GColors m_colorBody;    // Màu
	bool m_isDead;			// Bao nhiêu second

	//các biến dùng cho hàm IsElapsedExplosion
	long m_lastTickTime;
	long m_currentTickTime;
public:
	GExplosion();
	GExplosion(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody);
	bool GetIsDead();
	void SetIsDead(bool isDead);
	bool IsElapsedExplosion(long elapsedMilisecond);
	virtual void Update();
	virtual void Render();
	~GExplosion();
};

#endif
