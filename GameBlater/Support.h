
#ifndef __SUPPORT_H__
#define __SUPPORT_H__

#pragma once

#include "Utils.h"
#include "ScreenBase.h"

extern ScreenBase* g_currentScreen;
extern ScreenBase* g_screenStartGame;
extern ScreenBase* g_screenInGame;
extern ScreenBase* g_screenWinGame;
extern ScreenBase* g_screenOverGame;

//init window
void init(void);



#endif
