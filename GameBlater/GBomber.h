#ifndef __GBOMBER_H__
#define __GBOMBER_H__
#pragma once

#include "GObject.h"

#define NUMBERBOMB_DEFAULT 1
#define LENGTHBOMB_DEFAULT 3
#define VELOC_DEFAULT 5
#define TIMEIMMORTAL_BOMBER 1000

class GBomber : 
	public GObject
{
private:
	GDirections m_direction;
	GColors m_colorBody;
	int m_numberPutBomb;
	int m_numberBomb;
	int m_lengthBomb;
	int m_veloc;

	// Kiểm tra xem Bomber có đặt bomb ko
	bool m_isPutBomb;

	bool m_isImmortal;

	//các biến dùng cho hàm IsElapsedBomber
	long m_lastTickTime;
	long m_lastTickTimeImmortal;
	long m_currentTickTime;

public:
	GBomber();
	GBomber(char sprite, int posX, int posY, int moveX, int moveY, GDirections direction, GColors colorBody, int numberBomb, int lengthBomb, int veloc);	
	int GetNumberPutBomb();
	void SetNumberPutBomb(int numberPutBomb);
	int GetNumberBomb();
	void SetNumberBomb(int numberBomb);
	int GetLengthBomb();
	void SetLengthBomb(int lengthBomb);
	int GetVeloc();
	void SetVeloc(int veloc);
	bool GetIsImmortal();
	void SetIsImmortal(bool isImmortal);
	bool GetIsPutBomb();
	void SetIsPutBomb(bool isPutBomb);
	bool IsElapsedBomber(long elapsedMilisecond);
	bool IsElapsedBomberImmortal(long elapsedMilisecond);
	bool CanMoveUp();
	bool CanMoveDown();
	bool CanMoveLeft();
	bool CanMoveRight();
	virtual void Update();
	virtual void Render();
	~GBomber();
};

#endif

