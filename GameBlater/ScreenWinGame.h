#ifndef __SCREENWINGAME_H__
#define __SCREENWINGAME_H__
#pragma once

#include "ScreenBase.h"
#include "ScreenStartGame.h"
#include "Support.h"
#include <fstream>

#define INDEXWINGAME_MAX 2

using namespace std;

class ScreenWinGame :
	public ScreenBase
{
private:
	int m_index;
	int m_score;
public:
	ScreenWinGame();
	int GetScore();
	void SetScore(int socre);
	virtual void Init();
	virtual void Update();
	virtual void Render();
	~ScreenWinGame();
};

#endif

