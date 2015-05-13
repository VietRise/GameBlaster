#include "GBrick.h"


GBrick::GBrick()
	:GObject()
{
	m_colorBody = GColors::LIGHT_WHITE;
	m_containTypeGift = GGiftType::NO;
}

GBrick::GBrick(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody, GGiftType containTypeGift)
	:GObject(sprite, posX, posY, moveX, moveY)
{
	this->m_colorBody = colorBody;
	this->m_containTypeGift = containTypeGift;
}

GGiftType GBrick::GetContainTypeGift()
{
	return m_containTypeGift;
}

void GBrick::SetContainTypeGift(GGiftType containTypeGift)
{
	this->m_containTypeGift = containTypeGift;
}

void GBrick::Update()
{
}

void GBrick::Render()
{
}

GBrick::~GBrick()
{
}
