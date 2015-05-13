#ifndef __GENEMY_H__
#define __GENEMY_H__
#pragma once

#include "gobject.h"

#define ANIMATERATE_ENEMY 4
#define STEPCHANGEDIRECTION_MIN 5
#define TIMEIMMORTAL_ENEMY 1000

class GEnemy :
	public GObject
{
private:
	GDirections m_direction;
	GColors m_colorBody;
	GEnemyType m_type;
	int m_blood;

	bool m_isImmortal;

	//các biến dùng cho hàm IsElapsedEnemy
	long m_lastTickTime;
	long m_lastTickTimeImmortal;
	long m_currentTickTime;
	
	int m_stepUp;
	int m_stepDown;
	int m_stepLeft;
	int m_stepRight;

public:
	GEnemy();
	GEnemy(char sprite, int posX, int posY, int moveX, int moveY, GDirections direction, GColors colorBody, GEnemyType type);
	bool IsElapsedEnemy(long elapsedMilisecond);
	bool IsElapsedEnemyImmortal(long elapsedMilisecond);
	GColors GetColorBody();
	void SetColorBody(GColors colorBody);
	void SetColorBody();
	GEnemyType GetType();
	void SetType(GEnemyType type);
	int GetBlood();
	void SetBlood(int blood);
	bool GetIsImmortal();
	void SetIsImmortal(bool isImmortal);
	bool CanMoveUp();
	bool CanMoveDown();
	bool CanMoveLeft();
	bool CanMoveRight();
	void RandomDiretion();
	virtual void Update();
	virtual void Render();
	~GEnemy();
};

#endif

