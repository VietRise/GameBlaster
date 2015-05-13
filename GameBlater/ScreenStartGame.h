#ifndef __SCREENSTARTGAME_H__
#define __SCREENSTARTGAME_H__
#pragma once

#include "screenbase.h"
#include "ScreenInGame.h"
#include "Support.h"
#include <fstream>
#include <string>

#define INDEXSTARTGAME_MAX 4

using namespace std;

class ScreenStartGame :
	public ScreenBase
{
private:
	int m_index;
	char stringSymbol[20][50];
public:
	static int m_highScore;					// Biến lưu trữ điểm cao nhất

	ScreenStartGame();
	virtual void Init();					// Khởi tạo
	virtual void Update();					// Update
	virtual void Render();					// Vẽ
	~ScreenStartGame();
};

#endif
