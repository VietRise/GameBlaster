#ifndef __GGIFT_H__
#define __GGIFT_H__
#pragma once

#include "gobject.h"

#define TIME_IMMORTAL 1100    // Thời gian bất tử, tính bằng Milisecond

class GGift :
	public GObject
{
private:
	GColors m_colorBody;
	GGiftType m_typeGift;
	bool m_isImmortal;		// Nếu true -> Không bị bomb phá hủy

	//các biến dùng cho hàm IsElapsedGGift
	long m_lastTickTime;
	long m_currentTickTime;
public:
	GGift();
	GGift(int posX, int posY, int moveX, int moveY, GColors colorBody, GGiftType typeGift);
	GGiftType GetTypeGift();
	void SetTypeGift(GGiftType typeGift);
	bool GetIsImmortal();
	void SetIsImmortal(bool isImmortal);
	bool IsElapsedGift(long elapsedMilisecond);
	virtual void Update();
	virtual void Render();
	~GGift();
};

#endif

