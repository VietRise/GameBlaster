#include "ScreenOverGame.h"


ScreenOverGame::ScreenOverGame()
{
	m_index = 0;
	m_score = 0;
}

int ScreenOverGame::GetScore()
{
	return m_score;
}

void ScreenOverGame::SetScore(int score)
{
	this->m_score = score;
}

void ScreenOverGame::Init()
{
	m_index = 0;
	m_score = 0;

	GPlaySound("Sound//gameover", false);
}

void ScreenOverGame::Update()
{
	if(GIsKeyPress(GKeys::KEY_UP))
	{
		m_index--;
		if(m_index < 0)
		{
			m_index = INDEXOVERGAME_MAX - 1;
		}
	}

	if(GIsKeyPress(GKeys::KEY_DOWN))
	{
		m_index++;
		m_index = m_index%INDEXOVERGAME_MAX;
	}

	if(GIsKeyPress(GKeys::KEY_ENTER))
	{
		switch(m_index)
		{
		case 0:
			g_currentScreen = g_screenStartGame;
			g_screenStartGame->Init();
			break;
		
		case 1:
			exit(0);
			break;
		}
	}
}

void ScreenOverGame::Render()
{
	ScreenBase::Render();

	GPutStringToBuffer("GAME OVER", 22, 11, GColors::LIGHT_WHITE);

	GPutStringToBuffer("Score : ", 22, 13, GColors::LIGHT_WHITE);

	char buf[5];
	itoa(m_score, buf, 10);
	GPutStringToBuffer(buf, 30, 13, GColors::LIGHT_WHITE);

	GPutStringToBuffer("PLAY AGAIN", 61, 6, GColors::LIGHT_WHITE);
	GPutStringToBuffer("EXIT", 63, 8, GColors::LIGHT_WHITE);

	switch(m_index)
	{
	case 0:
		GPutStringToBuffer("->", 58, 6, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 71, 6, GColors::LIGHT_WHITE);
		break;
	case 1:
		GPutStringToBuffer("->", 60, 8, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 68, 8, GColors::LIGHT_WHITE);
		break;
	}
}

ScreenOverGame::~ScreenOverGame()
{
}
