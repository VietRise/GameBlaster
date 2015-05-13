#include "GObject.h"


GObject::GObject()
{
	m_sprite = 'o';
	m_pos.x = 0;
	m_pos.y = 0;
	m_moveX = 0;
	m_moveY = 0;
}

GObject::GObject(char sprite, int posX, int posY, int moveX, int moveY)
{
	this->m_sprite = sprite;
	this->m_pos.x = posX;
	this->m_pos.y = posY;
	this->m_moveX = moveX;
	this->m_moveY = moveY;
}

int GObject::GetPosX()
{
	return this->m_pos.x;
}

void GObject::SetPosX(int posX)
{
	this->m_pos.x = posX;
}

int GObject::GetPosY()
{
	return this->m_pos.y;
}

void GObject::SetPosY(int posY)
{
	this->m_pos.y = posY;
}

GRectangle GObject::GetCollision()
{
	GRectangle rect;	
	rect.x = m_pos.x + 0.1;
	rect.y = m_pos.y + 0.1;
	rect.width = 1 - 2*0.1;
	rect.height = 1 - 2*0.1;
	return rect;
}

void GObject::Update()
{
}

void GObject::Render()
{
}

GObject::~GObject()
{
}
