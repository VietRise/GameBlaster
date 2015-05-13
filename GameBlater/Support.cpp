
#include "Support.h"

ScreenBase* g_currentScreen;
ScreenBase* g_screenStartGame;
ScreenBase* g_screenInGame;
ScreenBase* g_screenWinGame;
ScreenBase* g_screenOverGame;

void init(void)
{
	//title
	SetConsoleTitle("GAME BLASTER");

	//position
	GSetWindowPosition(200, 200);

	//hide mouse
	GSetCursorVisiable(false);

	//color
	GSetTextColor(GColors::LIGHT_WHITE);
	GSetBGColor(GColors::BLACK);

	//set default font
	//font này là font duy nhất có dạng vuông
	GSetFont(16, 16, 100, GFontFamilys::MODERN);

	//no scroll bar
	GSetNoScroolBar();
}
