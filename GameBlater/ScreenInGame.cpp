#include "ScreenInGame.h"

ScreenInGame::ScreenInGame()
{
	srand(time(0));
	m_life = 3;
	m_score = 0;
	m_level = 1;
	m_time = 53;
	m_isPause = false;
	m_index = 0;
}

int ScreenInGame::GetLevel()
{
	return this->m_level;
}

void ScreenInGame::SetLevel(int level)
{
	this->m_level = level;
}

void ScreenInGame::Init()
{
	PlaySound(NULL, 0 ,0);

	int rdom;
	if(m_level == 1)
	{
		int tempArrayMap[MAP_HEIGHT][MAP_WIDTH] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0 },
			{ 0, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0 },
			{ 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		};

		for(int i=0; i<MAP_HEIGHT; i++)
			for(int j=0; j<MAP_WIDTH; j++)
				arrMap[i][j] = tempArrayMap[i][j];
		
		m_life = 3;
		m_score = 0;
		m_level = 1;
		m_time = 53;
		m_isPause = false;
		m_index = 0;

		m_killEnemyHeart = 0;
		m_killEnemyDiamond = 0;
		m_killEnemyClub = 0;

		m_taskKillEnemyHeart = 1;
		m_taskKillEnemyDiamond = 1;
		m_taskKillEnemyClub = 1;

		m_lastTickTime = timeGetTime();
		m_currentTickTime = m_lastTickTime;

		m_bomber = new GBomber(2, 25, 10, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, NUMBERBOMB_DEFAULT, LENGTHBOMB_DEFAULT, VELOC_DEFAULT);

		GObject* l_enemy = new GEnemy(3, 0, 0, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(3, 0, 20, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 0, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 20, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(5, 25, 0, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(5, 25, 20, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);

		for(int i=0; i<MAP_HEIGHT; i++)
		{
			for(int j=0; j<MAP_WIDTH; j++)
			{
				if(arrMap[i][j] == 2)
				{
					GObject* l_brick;
					rdom = rand()%100;
					if(rdom < 70)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NO);
					else if(rdom < 80)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NUMBERBOMB);
					else if(rdom < 90)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::LENGHTBOMB);
					else 
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::VELOC);
					m_brick.push_back(l_brick);
				}
			}
		}

		// Random cửa sổ 
		rdom = rand()%(m_brick.size());
		((GBrick*)m_brick[rdom])->SetContainTypeGift(GGiftType::WINDOW);
	}
	else if(m_level == 2)
	{
		int tempArrayMap[MAP_HEIGHT][MAP_WIDTH] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0 },
			{ 0, 0, 2, 0, 0, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 2, 2, 0, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 2, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 0 },
			{ 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 2, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 2, 0, 0, 0, 2, 0, 2, 0, 2, 2, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 0, 2, 0, 2, 2, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		};

		for(int i=0; i<MAP_HEIGHT; i++)
			for(int j=0; j<MAP_WIDTH; j++)
				arrMap[i][j] = tempArrayMap[i][j];
		
		m_level = 2;
		m_time = 53;
		m_isPause = false;
		m_index = 0;

		m_killEnemyHeart = 0;
		m_killEnemyDiamond = 0;
		m_killEnemyClub = 0;

		m_taskKillEnemyHeart = 4;
		m_taskKillEnemyDiamond = 4;
		m_taskKillEnemyClub = 4;

		m_lastTickTime = timeGetTime();
		m_currentTickTime = m_lastTickTime;

		m_bomber = new GBomber(2, 25, 10, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, NUMBERBOMB_DEFAULT, LENGTHBOMB_DEFAULT, VELOC_DEFAULT);

		GObject* l_enemy = new GEnemy(3, 0, 0, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(3, 0, 20, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 0, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 20, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(5, 25, 0, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(5, 25, 20, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);


		for(int i=0; i<MAP_HEIGHT; i++)
		{
			for(int j=0; j<MAP_WIDTH; j++)
			{
				if(arrMap[i][j] == 2)
				{
					GObject* l_brick;
					rdom = rand()%100;
					if(rdom < 70)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NO);
					else if(rdom < 80)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NUMBERBOMB);
					else if(rdom < 90)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::LENGHTBOMB);
					else 
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::VELOC);
					m_brick.push_back(l_brick);
				}
			}
		}

		// Random cửa sổ 
		rdom = rand()%(m_brick.size());
		((GBrick*)m_brick[rdom])->SetContainTypeGift(GGiftType::WINDOW);
	}
	else if(m_level == 3)
	{
		int tempArrayMap[MAP_HEIGHT][MAP_WIDTH] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		};

		for(int i=0; i<MAP_HEIGHT; i++)
			for(int j=0; j<MAP_WIDTH; j++)
				arrMap[i][j] = tempArrayMap[i][j];
		
		m_level = 3;
		m_time = 53;
		m_isPause = false;
		m_index = 0;

		m_killEnemyHeart = 0;
		m_killEnemyDiamond = 0;
		m_killEnemyClub = 0;

		m_taskKillEnemyHeart = 5;
		m_taskKillEnemyDiamond = 5;
		m_taskKillEnemyClub = 5;

		m_lastTickTime = timeGetTime();
		m_currentTickTime = m_lastTickTime;

		m_bomber = new GBomber(2, 25, 10, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, NUMBERBOMB_DEFAULT, LENGTHBOMB_DEFAULT, VELOC_DEFAULT);

		GObject* l_enemy = new GEnemy(3, 0, 0, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(3, 0, 20, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 0, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(4, 50, 20, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
		m_enemies.push_back(l_enemy);		
		l_enemy = new GEnemy(5, 25, 0, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);
		l_enemy = new GEnemy(5, 25, 20, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
		m_enemies.push_back(l_enemy);

		for(int i=0; i<MAP_HEIGHT; i++)
		{
			for(int j=0; j<MAP_WIDTH; j++)
			{
				if(arrMap[i][j] == 2)
				{
					GObject* l_brick;
					rdom = rand()%100;
					if(rdom < 70)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NO);
					else if(rdom < 80)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::NUMBERBOMB);
					else if(rdom < 90)
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::LENGHTBOMB);
					else 
						l_brick = new GBrick(219, j, i, 0, 0, GColors::LIGHT_BLACK, GGiftType::VELOC);
					m_brick.push_back(l_brick);
				}
			}
		}

		// Random cửa sổ 
		rdom = rand()%(m_brick.size());
		((GBrick*)m_brick[rdom])->SetContainTypeGift(GGiftType::WINDOW);
	}
}

void ScreenInGame::Update()
{
	if(m_isPause)
	{
		if(GIsKeyPress(GKeys::KEY_UP))
		{
			m_index--;
			if(m_index < 0)
			{
				m_index = INDEXINGAME_MAX - 1;
			}
		}

		if(GIsKeyPress(GKeys::KEY_DOWN))
		{
			m_index++;
			m_index = m_index%INDEXINGAME_MAX;
		}

		if(GIsKeyPress(GKeys::KEY_ENTER))
		{
			if(m_index == 0)
			{
				m_isPause = false;
			}
			else
			{
				g_currentScreen = g_screenStartGame;
				g_currentScreen->Init();
			}
		}
	}
	else
	{	
		// Update Bomber
		m_bomber->Update();

		// Kiểm tra Bomber có đặt bomb ko?

		if(m_bomber->GetIsPutBomb())
		{
			GObject* l_bomb = new GBomb('o', m_bomber->GetPosX(), m_bomber->GetPosY(), 0, 0, GColors::LIGHT_WHITE, m_bomber->GetLengthBomb());
			m_bomb.push_back(l_bomb);
			// Tăng số bomb đã đặt của Bomber lên
			m_bomber->SetNumberPutBomb(m_bomber->GetNumberPutBomb() + 1);

			// Update lại ma trận 2 chiều tại vị trí bomb được đặt (giá trị là 3)
			arrMap[l_bomb->GetPosY()][l_bomb->GetPosX()] = 3;
		}

		// Update Enemies
		for(int i=0; i<m_enemies.size(); i++)
		{
			m_enemies[i]->Update();
		}

		// Update Bomb
		vector<GObject*>::iterator vectIterB;
		for(vectIterB = m_bomb.begin(); vectIterB != m_bomb.end(); )
		{
			if(((GBomb*)(*vectIterB))->GetTimeLive() < 0)
			{			
				// Chơi âm thanh
				GPlaySound("Sound//explosion", false);
				// Update lại ma trận 2 chiều tại vị trí bomb đã nổ (giá trị là 0)
				arrMap[(*vectIterB)->GetPosY()][(*vectIterB)->GetPosX()] = 0;
				AddEffectExplosion(*vectIterB);        // Thêm hiệu ứng nổ
				vectIterB = m_bomb.erase(vectIterB);    // Xóa đổi tượng bomb đã nổ
				// Giảm số bomb đã đặt của Bomber xuống
				m_bomber->SetNumberPutBomb(m_bomber->GetNumberPutBomb() - 1);
			}
			else
			{
				(*vectIterB)->Update();
				vectIterB++;
			}
		}	

		// Update Explosion
		vector<GObject*>::iterator vecIterE;
		for(vecIterE = m_explosion.begin(); vecIterE != m_explosion.end(); )
		{
			if(((GExplosion*)(*vecIterE))->GetIsDead())
			{
				vecIterE = m_explosion.erase(vecIterE);
			}
			else
			{
				(*vecIterE)->Update();
				vecIterE++;
			}
		}

		// Update Gift
		for(int i=0; i<m_gift.size(); i++)
		{
			m_gift[i]->Update();
		}

		// Kiểm tra va chạm
		CheckCollsion();

		// Update ProgressBarTime
		if(IsElapsedInGame(TIME_PROGRESS))
		{
			m_time--;

			// Thêm enemies (Những mốc thời gian)
			if(m_time == 5 || m_time == 13 || m_time == 21 || m_time == 29 || m_time == 37 || m_time == 45)
			{
				int rdom;
				rdom = rand()%3;
				if(rdom == 0)
				{
					GObject* l_enemy = new GEnemy(3, 0, 0, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
					m_enemies.push_back(l_enemy);
					l_enemy = new GEnemy(4, 50, 0, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
					m_enemies.push_back(l_enemy);
				}
				else if(rdom == 1)
				{
					GObject* l_enemy = new GEnemy(4, 0, 20, 1, 1, GDirections::NONE, GColors::LIGHT_MAGENTA, GEnemyType::DIAMOND);
					m_enemies.push_back(l_enemy);
					l_enemy = new GEnemy(5, 50, 20, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
					m_enemies.push_back(l_enemy);
				}
				else if(rdom == 2)
				{
					GObject* l_enemy = new GEnemy(5, 0, 20, 1, 1, GDirections::NONE, GColors::LIGHT_RED, GEnemyType::CLUB);
					m_enemies.push_back(l_enemy);
					l_enemy = new GEnemy(3, 50, 0, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, GEnemyType::HEART);
					m_enemies.push_back(l_enemy);
				}
			}
		}	

		if(m_time < 0)
		{
			Clear();
			g_currentScreen = g_screenOverGame;
			g_currentScreen->Init();
			((ScreenOverGame*)g_currentScreen)->SetScore(m_score);
		}

		if(GIsKeyPress(GKeys::KEY_ENTER))
		{
			// Chơi âm thanh 
			GPlaySound("Sound//puase", false);
			m_isPause = true;
		}
	}
}

void ScreenInGame::Render()
{
	ScreenBase::Render();

	// Vẽ những đối tượng trong game	

	//---ENEMIES---
	vector<GObject*>::iterator vectIter;
	for(vectIter = m_enemies.begin(); vectIter != m_enemies.end(); vectIter++)
	{
		(*vectIter)->Render();
	}

	//---BOMB---
	for(int i=0; i<m_bomb.size(); i++)
	{
		m_bomb[i]->Render();
	}

	//---BOMBER---
	m_bomber->Render();

	//---EXPLOSION---
	for(int i=0; i<m_explosion.size(); i++)
	{
		m_explosion[i]->Render();
	}

	// ---GIFT---
	for(int i=0; i<m_gift.size(); i++)
	{
		m_gift[i]->Render();
	}

	// Vẽ những đối tượng vật cản như đá và gạch
	RenderBarrier();

	// Vẽ progressbar Time
	RenderProgressBarTime();

	// Vẽ Life, Score, Level
	RenderComponents();

	if(m_isPause)
	{
		GPutStringToBuffer("RESUME", 25, 11, GColors::RED);
		GPutStringToBuffer("EXIT", 26, 13, GColors::RED);

		if(m_index == 0)
		{
			GPutStringToBuffer("->", 22, 11, GColors::RED);
			GPutStringToBuffer("<-", 32, 11, GColors::RED);
		}
		else if(m_index == 1)
		{
			GPutStringToBuffer("->", 23, 13, GColors::RED);
			GPutStringToBuffer("<-", 31, 13, GColors::RED);
		}
	}

}

bool ScreenInGame::IsElapsedInGame(long elapsedMilisecond)
{
	m_currentTickTime = timeGetTime();

	if(m_currentTickTime - m_lastTickTime >= elapsedMilisecond)
	{
		m_lastTickTime = m_currentTickTime;
		return true;
	}
	else
	{
		return false;
	}
}

void ScreenInGame::Clear()
{
	m_enemies.clear();
	m_bomb.clear();
	m_brick.clear();
	m_gift.clear();
	m_explosion.clear();
}

void ScreenInGame::AddEffectExplosion(GObject* bomb)
{
	GPoint2D l_posBomb = {bomb->GetPosX(), bomb->GetPosY()};
	int l_length = ((GBomb*)bomb)->GetLengthBomb();

	GObject* l_explosion = new GExplosion('*', l_posBomb.x, l_posBomb.y, 0, 0, GColors::LIGHT_WHITE);
	m_explosion.push_back(l_explosion);

	for(int i=0; i<4; i++)               // Duyệt qua 4 hướng
	{
		for(int j=1; j<=l_length; j++)   // Duyệt qua độ dài của bomb nổ
		{
			if(i == 0)                   // Hướng lên
			{
				if(l_posBomb.y-j < 0)									// Ra khỏi màn hình				
					break;						
				if(arrMap[l_posBomb.y-j][l_posBomb.x] == 0 || (arrMap[l_posBomb.y-j][l_posBomb.x] == 3))             // Không đụng vào gì cả thì thêm nổ
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x, l_posBomb.y-j, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
				}
				else if(arrMap[l_posBomb.y-j][l_posBomb.x] == 1)		// Đụng vào đá thì ko thêm nổ
					break;
				else if(arrMap[l_posBomb.y-j][l_posBomb.x] == 2)		// Đụng vào gạch thì thêm nổ và kết thúc
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x, l_posBomb.y-j, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
					break;
				}				
			}
			else if(i == 1)					// Hướng xuống
			{
				if(l_posBomb.y+j >= MAP_HEIGHT)							// Ra khỏi màn hình				
					break;						
				if(arrMap[l_posBomb.y+j][l_posBomb.x] == 0 || (arrMap[l_posBomb.y+j][l_posBomb.x] == 3))             // Không đụng vào gì cả thì thêm nổ
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x, l_posBomb.y+j, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
				}
				else if(arrMap[l_posBomb.y+j][l_posBomb.x] == 1)		// Đụng vào đá thì ko thêm nổ
					break;
				else if(arrMap[l_posBomb.y+j][l_posBomb.x] == 2)		// Đụng vào gạch thì thêm nổ và kết thúc
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x, l_posBomb.y+j, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
					break;
				}	
			}
			else if(i == 2)					// Hướng trái
			{
				if(l_posBomb.x-j < 0)							// Ra khỏi màn hình				
					break;						
				if(arrMap[l_posBomb.y][l_posBomb.x-j] == 0 || (arrMap[l_posBomb.y][l_posBomb.x-j] == 3))             // Không đụng vào gì cả thì thêm nổ
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x-j, l_posBomb.y, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
				}
				else if(arrMap[l_posBomb.y][l_posBomb.x-j] == 1)		// Đụng vào đá thì ko thêm nổ
					break;
				else if(arrMap[l_posBomb.y][l_posBomb.x-j] == 2)		// Đụng vào gạch thì thêm nổ và kết thúc
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x-j, l_posBomb.y, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
					break;
				}
			}
			else							// Hướng còn lại -> Hướng phải
			{
				if(l_posBomb.x+j >= MAP_WIDTH)							// Ra khỏi màn hình				
					break;						
				if(arrMap[l_posBomb.y][l_posBomb.x+j] == 0 || (arrMap[l_posBomb.y][l_posBomb.x+j] == 3))             // Không đụng vào gì cả thì thêm nổ
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x+j, l_posBomb.y, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
				}
				else if(arrMap[l_posBomb.y][l_posBomb.x+j] == 1)		// Đụng vào đá thì ko thêm nổ
					break;
				else if(arrMap[l_posBomb.y][l_posBomb.x+j] == 2)		// Đụng vào gạch thì thêm nổ và kết thúc
				{
					GObject* l_explosion = new GExplosion('*', l_posBomb.x+j, l_posBomb.y, 0, 0, GColors::LIGHT_WHITE);
					m_explosion.push_back(l_explosion);
					break;
				}
			}
		}
	}
}

void ScreenInGame::CheckCollsion()
{	
	// KIỂM TRA VA CHAM EXPLOSION VS CÁC ĐỐI TƯỢNG BOMBER, ENEMIES, BOMBS, BRICKS, GIFTS
	for(int i=0; i<m_explosion.size(); i++)
	{
		//--- Kiểm tra va chạm giữa BOMBER vs EXPLOSION
		if(GIsIntersect(m_bomber->GetCollision(), m_explosion[i]->GetCollision()) && !m_bomber->GetIsImmortal())
		{
			// Chết
			if(m_life > 1)
			{
				m_life--;
				// Khởi tạo lại người chơi (Bomber)
				m_bomber = new GBomber(2, 25, 10, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, m_bomber->GetNumberBomb(), m_bomber->GetLengthBomb(), m_bomber->GetVeloc()); 
			}
			else  // Thua
			{
				Clear();
				g_currentScreen = g_screenOverGame;
				g_currentScreen->Init();
				((ScreenOverGame*)g_currentScreen)->SetScore(m_score);
			}
			break;
		}

		//--- Kiểm tra va chạm giữa ENEMIES vs EXPLOSION
		vector<GObject*>::iterator vectIterE;
		for(vectIterE = m_enemies.begin(); vectIterE != m_enemies.end(); )
		{
			if(GIsIntersect((*vectIterE)->GetCollision(), m_explosion[i]->GetCollision()) && !((GEnemy*)(*vectIterE))->GetIsImmortal())
			{
				((GEnemy*)(*vectIterE))->SetBlood(((GEnemy*)(*vectIterE))->GetBlood() - 1);
				((GEnemy*)(*vectIterE))->SetColorBody();
				if(((GEnemy*)(*vectIterE))->GetBlood() <= 0)
				{
					switch(((GEnemy*)(*vectIterE))->GetType())
					{
					case GEnemyType::HEART:
						m_killEnemyHeart++;
						break;
					case GEnemyType::DIAMOND:
						m_killEnemyDiamond++;
						break;
					case GEnemyType::CLUB:
						m_killEnemyClub++;
						break;
					default:
						break;
					}
					m_score += SCORE_ENEMY;
					vectIterE = m_enemies.erase(vectIterE);
				}
			}
			else
			{
				vectIterE++;
			}
		}

		//--- Kiểm tra va chạm giữa BOMB vs EXPLOSION
		vector<GObject*>::iterator vectIterBo;
		for(vectIterBo = m_bomb.begin(); vectIterBo != m_bomb.end(); )
		{
			if(GIsIntersect((*vectIterBo)->GetCollision(), m_explosion[i]->GetCollision()))
			{
				// Update lại ma trận 2 chiều tại vị trí bomb đã nổ (giá trị là 0)
				arrMap[(*vectIterBo)->GetPosY()][(*vectIterBo)->GetPosX()] = 0;
				AddEffectExplosion(*vectIterBo);        // Thêm hiệu ứng nổ
				vectIterBo = m_bomb.erase(vectIterBo);    // Xóa đổi tượng bomb đã nổ
				// Giảm số bomb đã đặt của Bomber xuống
				m_bomber->SetNumberPutBomb(m_bomber->GetNumberPutBomb() - 1);
			}
			else
			{
				vectIterBo++;
			}
		}

		//--- Kiểm tra va chạm giữa BRICKS vs EXPLOSION
		vector<GObject*>::iterator vectIterB;
		for(vectIterB = m_brick.begin(); vectIterB != m_brick.end(); )
		{
			if(GIsIntersect((*vectIterB)->GetCollision(), m_explosion[i]->GetCollision()))
			{
				//// Xuất hiện quà dưới hộp	
				if(((GBrick*)(*vectIterB))->GetContainTypeGift() == GGiftType::NUMBERBOMB)
				{
					GObject* l_gift = new GGift((*vectIterB)->GetPosX(), (*vectIterB)->GetPosY(), 0, 0, GColors::LIGHT_WHITE, GGiftType::NUMBERBOMB);
					m_gift.push_back(l_gift);
				}
				else if(((GBrick*)(*vectIterB))->GetContainTypeGift() == GGiftType::LENGHTBOMB)
				{
					GObject* l_gift = new GGift((*vectIterB)->GetPosX(), (*vectIterB)->GetPosY(), 0, 0, GColors::LIGHT_WHITE, GGiftType::LENGHTBOMB);
					m_gift.push_back(l_gift);
				}
				else if(((GBrick*)(*vectIterB))->GetContainTypeGift() == GGiftType::VELOC)
				{
					GObject* l_gift = new GGift((*vectIterB)->GetPosX(), (*vectIterB)->GetPosY(), 0, 0, GColors::LIGHT_WHITE, GGiftType::VELOC);
					m_gift.push_back(l_gift);
				}
				else if(((GBrick*)(*vectIterB))->GetContainTypeGift() == GGiftType::WINDOW)
				{				
					GObject* l_gift = new GGift((*vectIterB)->GetPosX(), (*vectIterB)->GetPosY(), 0, 0, GColors::LIGHT_WHITE, GGiftType::WINDOW);
					m_gift.push_back(l_gift);
				}								
				arrMap[(*vectIterB)->GetPosY()][(*vectIterB)->GetPosX()] = 0;
				vectIterB = m_brick.erase(vectIterB);

			}
			else
			{
				vectIterB++;
			}
		}

		//--- Kiểm tra va chạm giữa GIFTS vs EXPLOSION
		vector<GObject*>::iterator vectIterG;
		for(vectIterG = m_gift.begin(); vectIterG != m_gift.end(); )
		{
			if((GIsIntersect((*vectIterG)->GetCollision(), m_explosion[i]->GetCollision())) && !((GGift*)(*vectIterG))->GetIsImmortal())
			{
				vectIterG = m_gift.erase(vectIterG);
			}
			else
			{
				vectIterG++;
			}
		}
	}

	// KIỂM TRA VA CHẠM BOMBER vs ENEMIES, BOMBS, GIFTS

	//--- Kiểm tra va chạm giữa BOMBER vs ENEMIES
	vector<GObject*>::iterator vectIterE;
	for(vectIterE = m_enemies.begin(); vectIterE != m_enemies.end(); )
	{
		if(GIsIntersect(m_bomber->GetCollision(), (*vectIterE)->GetCollision()) && !m_bomber->GetIsImmortal())
		{
			// Chết
			if(m_life > 1)
			{
				m_life--;
				// Khởi tạo lại người chơi (Bomber)
				m_bomber = new GBomber(2, 25, 10, 1, 1, GDirections::NONE, GColors::LIGHT_WHITE, m_bomber->GetNumberBomb(), m_bomber->GetLengthBomb(), m_bomber->GetVeloc()); 
			}
			else  // Thua
			{
				Clear();
				g_currentScreen = g_screenOverGame;
				g_currentScreen->Init();
				((ScreenOverGame*)g_currentScreen)->SetScore(m_score);
			}
			break;
		}
		else
		{
			vectIterE++;
		}
	}

	//--- Kiểm tra va chạm giữa BOMBER vs BOMB


	//--- Kiểm tra va chạm giữa BOMBER vs GIFTS
	vector<GObject*>::iterator vectIterG;
	for(vectIterG = m_gift.begin(); vectIterG != m_gift.end(); )
	{
		// Kiểm tra có qua màng ko.

		bool kt = false;
		if((GIsIntersect(m_bomber->GetCollision(), (*vectIterG)->GetCollision())))
		{
			switch(((GGift*)(*vectIterG))->GetTypeGift())
			{
			case GGiftType::NUMBERBOMB:
				m_bomber->SetNumberBomb(m_bomber->GetNumberBomb() + 1);
				vectIterG = m_gift.erase(vectIterG);
				break;
			case GGiftType::LENGHTBOMB:
				m_bomber->SetLengthBomb(m_bomber->GetLengthBomb() + 1);
				vectIterG = m_gift.erase(vectIterG);
				break;
			case GGiftType::VELOC:
				m_bomber->SetVeloc(m_bomber->GetVeloc() + 1);
				vectIterG = m_gift.erase(vectIterG);
				break;
			case GGiftType::WINDOW:
				if(m_killEnemyHeart >= m_taskKillEnemyHeart && m_killEnemyDiamond >= m_taskKillEnemyDiamond && m_killEnemyClub >= m_taskKillEnemyClub)
				{
					// Qua màng
					if(m_level < 3)
					{				
						kt = true;
						m_level++;
						Init();
					}
					else // Thắng
					{
						Clear();
						g_currentScreen = g_screenWinGame;
						((ScreenWinGame*)g_currentScreen)->SetScore(m_score);
						g_currentScreen->Init();
						kt = true;
					}
				}
				vectIterG++;
				break;
			default:
				break;
			}			
		}
		else
		{
			vectIterG++;
		}
		// Nếu qua màng thì ko cần phải xét tiếp
		if(kt)
			break;
	}
}

void ScreenInGame::RenderBarrier()
{
	for(int i=0; i<MAP_HEIGHT; i++)
	{
		for(int j=0; j<MAP_WIDTH; j++)
		{
			if(arrMap[i][j] == 1)
			{
				GPutCharToBuffer(219, j + MAP_LEFT, i + MAP_TOP, GColors::WHITE); 
			}
			else if(arrMap[i][j] == 2)
			{
				GPutCharToBuffer(219, j + MAP_LEFT, i + MAP_TOP, GColors::LIGHT_BLACK); 
			}
		}
	}
}

void ScreenInGame::RenderProgressBarTime()
{
	for(int i=0; i<m_time; i++)
	{
		GPutCharToBuffer(219, i + MAP_LEFT - 1, 25, GColors::RED); 
	}
}

void ScreenInGame::RenderComponents()
{
	// Vẽ life, score, level
	GPutStringToBuffer("LIFE   :", 59, 5, GColors::LIGHT_WHITE);
	GPutStringToBuffer("SCORE  :", 59, 7, GColors::LIGHT_WHITE);
	GPutStringToBuffer("LEVEL  :", 59, 9, GColors::LIGHT_WHITE);

	char buf[10];
	itoa(m_life, buf, 10);	
	GPutStringToBuffer(buf, 69, 5, GColors::LIGHT_WHITE);	
	itoa(m_score, buf, 10);
	GPutStringToBuffer(buf, 69, 7, GColors::LIGHT_WHITE);
	itoa(m_level, buf, 10);
	GPutStringToBuffer(buf, 69, 9, GColors::LIGHT_WHITE);

	// Vẽ N, L, V
	GPutStringToBuffer("N      :", 59, 11, GColors::LIGHT_WHITE);
	GPutStringToBuffer("L      :", 59, 13, GColors::LIGHT_WHITE);
	GPutStringToBuffer("V      :", 59, 15, GColors::LIGHT_WHITE);

	itoa(m_bomber->GetNumberBomb() - NUMBERBOMB_DEFAULT, buf, 10);
	GPutStringToBuffer(buf, 69, 11, GColors::LIGHT_WHITE);
	itoa(m_bomber->GetLengthBomb() - LENGTHBOMB_DEFAULT, buf, 10);
	GPutStringToBuffer(buf, 69, 13, GColors::LIGHT_WHITE);
	itoa(m_bomber->GetVeloc() - VELOC_DEFAULT, buf, 10);
	GPutStringToBuffer(buf, 69, 15, GColors::LIGHT_WHITE);

	// Vẽ nhiệm vụ
	GPutStringToBuffer("Mission", 58, 17, GColors::LIGHT_WHITE);
	GPutStringToBuffer("Finished", 66, 17, GColors::LIGHT_WHITE);
	
	GPutCharToBuffer(3, 58, 19, GColors::LIGHT_WHITE);
	GPutCharToBuffer(4, 58, 20, GColors::LIGHT_WHITE);
	GPutCharToBuffer(5, 58, 21, GColors::LIGHT_WHITE);

	itoa(m_taskKillEnemyHeart, buf, 10);
	GPutStringToBuffer(buf, 60, 19, GColors::LIGHT_WHITE);
	itoa(m_taskKillEnemyDiamond, buf, 10);
	GPutStringToBuffer(buf, 60, 20, GColors::LIGHT_WHITE);
	itoa(m_taskKillEnemyClub, buf, 10);
	GPutStringToBuffer(buf, 60, 21, GColors::LIGHT_WHITE);

	GPutCharToBuffer(3, 67, 19, GColors::LIGHT_WHITE);
	GPutCharToBuffer(4, 67, 20, GColors::LIGHT_WHITE);
	GPutCharToBuffer(5, 67, 21, GColors::LIGHT_WHITE);
	itoa(m_killEnemyHeart, buf, 10);
	GPutStringToBuffer(buf, 69, 19, GColors::LIGHT_WHITE);
	itoa(m_killEnemyDiamond, buf, 10);
	GPutStringToBuffer(buf, 69, 20, GColors::LIGHT_WHITE);
	itoa(m_killEnemyClub, buf, 10);
	GPutStringToBuffer(buf, 69, 21, GColors::LIGHT_WHITE);	
}

ScreenInGame::~ScreenInGame()
{
}