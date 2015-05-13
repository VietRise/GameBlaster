#ifndef __SCREENINGAME_H__
#define __SCREENINGAME_H__
#pragma once

#include "ScreenBase.h"
#include "ScreenWinGame.h"
#include "ScreenOverGame.h"
#include "GBomber.h"
#include "GBomb.h"
#include "GBrick.h"
#include "GEnemy.h"
#include "GGift.h"
#include "GExplosion.h"
#include <vector>
#include <time.h>

#define INDEXINGAME_MAX 2
#define SCORE_ENEMY 10
#define TIME_PROGRESS 5000

using namespace std;

class ScreenInGame: public ScreenBase
{
private:
	GBomber* m_bomber;
	vector<GObject*> m_enemies;
	vector<GObject*> m_bomb;
	vector<GObject*> m_brick;
	vector<GObject*> m_gift;
	vector<GObject*> m_explosion;

	// Các thành phần của game
	int m_life;
	int m_score;
	int m_level;
	int m_time;
	bool m_isPause;
	int m_index;

	int m_killEnemyHeart;
	int m_killEnemyDiamond;
	int m_killEnemyClub;

	int m_taskKillEnemyHeart;
	int m_taskKillEnemyDiamond;
	int m_taskKillEnemyClub;

	//các biến dùng cho hàm IsElapsedBomber
	long m_lastTickTime;
	long m_currentTickTime;

public:
	ScreenInGame();
	int GetLevel();
	void SetLevel(int level);
	virtual void Init();
	virtual void Update();
	virtual void Render();
	bool IsElapsedInGame(long elapsedMilisecond);
	void Clear();
	void AddEffectExplosion(GObject* bomb); // Thêm hiệu ứng nổ của Bomb 
	void CheckCollsion();					// Kiểm tra va chạm
	void RenderBarrier();					// Vẽ các vật cản
	void RenderProgressBarTime();			// Vẽ thanh thời gian
	void RenderComponents();				// Vẽ Life, Score, Level VS NumberBomb, LengthBomb, Veloc
	~ScreenInGame();
};

#endif