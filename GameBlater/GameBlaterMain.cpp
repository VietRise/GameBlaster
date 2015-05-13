#include "Utils.h"
#include "Support.h"
#include "GBomber.h"
#include "ScreenStartGame.h"
#include "ScreenInGame.h"
#include "ScreenWinGame.h"
#include "ScreenOverGame.h"

int ScreenStartGame::m_highScore = 0;

void main()
{
	init();

	g_screenStartGame = new ScreenStartGame();
	g_screenInGame = new ScreenInGame();
	g_screenWinGame = new ScreenWinGame();
	g_screenOverGame = new ScreenOverGame();

	g_currentScreen = g_screenStartGame;

	((ScreenInGame*)g_currentScreen)->SetLevel(1);
	g_currentScreen->Init();

	while(true)
	{
		GClearBuffer();
		
		g_currentScreen->Update();
		g_currentScreen->Render();

		GFlushBuffer();
	}
}