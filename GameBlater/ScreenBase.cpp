#include "ScreenBase.h"

ScreenBase::ScreenBase()
{
}

void ScreenBase::Init()
{
}

void ScreenBase::Update()
{
}

void ScreenBase::Render()
{
	GRectangle gameRect;
	gameRect.x = 1;
	gameRect.y = 1;
	gameRect.width = 52;
	gameRect.height = 22;
	GDrawRect(gameRect, GColors::LIGHT_WHITE);

	GRectangle infoRect;
	infoRect.x = 56;
	infoRect.y = 1;
	infoRect.width = 19;
	infoRect.height = 25;
	GDrawRect(infoRect, GColors::LIGHT_WHITE);

	GPutStringToBuffer("GAME BLASTER", 60, 2, GColors::LIGHT_WHITE);
	GPutStringToBuffer("##################", 57, 3, GColors::LIGHT_WHITE);
	GPutStringToBuffer("##################", 57, 23, GColors::LIGHT_WHITE);
	GPutStringToBuffer("TEAM", 65, 24, GColors::LIGHT_WHITE);
	GPutStringToBuffer("VMRISE-SE05", 61, 25, GColors::LIGHT_WHITE);
}

ScreenBase::~ScreenBase()
{
}