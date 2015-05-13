#ifndef __SCREENBASE_H__
#define __SCREENBASE_H__
#pragma once

#include "Utils.h"

class ScreenBase
{
protected:
	
public:
	ScreenBase();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	~ScreenBase();
};

#endif
