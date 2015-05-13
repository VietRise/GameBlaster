#ifndef __SCREENOVERGAME_H__
#define __SCREENOVERGAME_H__
#pragma once

#include "screenbase.h"
#include "Support.h"

#define INDEXOVERGAME_MAX 2

class ScreenOverGame :
	public ScreenBase
{
private:
	int m_index;
	int m_score;
public:
	ScreenOverGame();
	int GetScore();
	void SetScore(int score);
	virtual void Init();
	virtual void Update();
	virtual void Render();
	~ScreenOverGame();
};

#endif

