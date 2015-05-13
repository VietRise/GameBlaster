#include "ScreenStartGame.h"


ScreenStartGame::ScreenStartGame()
{
	this->m_index = 0;

	// Đọc file hightsocre.txt	
	ifstream file;
	file.open("highscore.txt");
	if(file.is_open())
	{
		file>>m_highScore;
		file.close();
	}

	ifstream file1;
	file1.open("symbol.txt");
	int i = 0;
	if(file1.is_open())
	{
		while(!file1.eof())
		{
			file1.getline(stringSymbol[i], 50);
			i++;
		}
	}

}

void ScreenStartGame::Init()
{
	this->m_index = 0;

	GPlaySound("Sound//backSound.wav", true);
}

void ScreenStartGame::Update()
{
	if(GIsKeyPress(GKeys::KEY_UP))
	{
		m_index--;
		if(m_index < 0)
		{
			m_index = INDEXSTARTGAME_MAX - 1;
		}
	}

	if(GIsKeyPress(GKeys::KEY_DOWN))
	{
		m_index++;
		m_index = m_index%INDEXSTARTGAME_MAX;
	}

	if(GIsKeyPress(GKeys::KEY_ENTER))
	{
		switch(m_index)
		{
		case 0:
			g_currentScreen = g_screenInGame;
			((ScreenInGame*)g_currentScreen)->SetLevel(1);
			g_screenInGame->Init();
			break;
		case 1:
		case 2:
			break;
		case 3:
			exit(EXIT_SUCCESS);			
			break;
		default:
			break;
		}
	}

}

void ScreenStartGame::Render()
{
	ScreenBase::Render();

	// Vẽ các dòng chữ START - HIGHSCORE - TUTORIAL - EXIT
	GPutStringToBuffer("START", 63, 6, GColors::LIGHT_WHITE);
	GPutStringToBuffer("HIGHSCORE", 61, 8, GColors::LIGHT_WHITE);
	GPutStringToBuffer("HELP", 63, 10, GColors::LIGHT_WHITE);
	GPutStringToBuffer("EXIT", 63, 12, GColors::LIGHT_WHITE);
	
	
	switch(m_index)
	{
	case 0:
		for(int i=0; i<20; i++)
		{
			GPutStringToBuffer(stringSymbol[i], 5, 3 + i, GColors::RED);
		}

		GPutStringToBuffer("->", 60, 6, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 69, 6, GColors::LIGHT_WHITE);
		break;
	case 1:
		GPutStringToBuffer("HIGH SCORE", 23, 9, GColors::LIGHT_WHITE);

		char buf[10];
		itoa(m_highScore, buf, 10);
		GPutStringToBuffer(buf, 26, 12, GColors::LIGHT_WHITE);

		GPutStringToBuffer("->", 58, 8, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 71, 8, GColors::LIGHT_WHITE);
		break;
	case 2:
		// Vẽ hướng dẫn
		GPutStringToBuffer("TUTORIAL", 23, 3, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-Player will get a mission for each level", 2, 4, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-In order to pass the current level, you have to", 2, 5, GColors::LIGHT_WHITE);
		GPutStringToBuffer("finish the mission and find out the door to get out", 2, 6, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-Your mission is to kill a given number of enemy.", 2, 7, GColors::LIGHT_WHITE);
		GPutStringToBuffer("There are three types of enemy", 2, 8, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-You have a definite time for each level. You will ", 2, 9, GColors::LIGHT_WHITE);
		GPutStringToBuffer("lose if the time is off and you can noto find out", 2, 10, GColors::LIGHT_WHITE);
		GPutStringToBuffer("the window", 2, 11, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-When you destroy the boxes, you can get bonus:", 2, 12, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    N: increase number of bombs", 2, 13, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    L: increase the effective scope of bombs", 2, 14, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    V: increase the velocity of bomber", 2, 15, GColors::LIGHT_WHITE);
		GPutStringToBuffer("-How to move and install a bomb:", 2, 16, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    Key_Up: move up", 2, 17, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    Key_Down: move down", 2, 18, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    Key_Left: move left", 2, 19, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    Key_Right: move right", 2, 20, GColors::LIGHT_WHITE);
		GPutStringToBuffer("    Key_Space: install a bomb", 2, 21, GColors::LIGHT_WHITE);

		GPutStringToBuffer("->", 60, 10, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 68, 10, GColors::LIGHT_WHITE);
		break;
	case 3:
		GPutStringToBuffer("->", 60, 12, GColors::LIGHT_WHITE);
		GPutStringToBuffer("<-", 68, 12, GColors::LIGHT_WHITE);
		break;
	default:
		break;
	}
}

ScreenStartGame::~ScreenStartGame()
{
}
