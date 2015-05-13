#include "GBomb.h"


GBomb::GBomb()
	:GObject()
{
	m_colorBody = GColors::LIGHT_WHITE;
	m_lengthBomb = 3;
	m_timeLive = 4;

	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

GBomb::GBomb(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody, int lengthBomb)
	:GObject(sprite, posX, posY, moveX, moveY)
{
	this->m_colorBody = colorBody;
	this->m_lengthBomb = lengthBomb;

	m_timeLive = 4;

	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

int GBomb::GetLengthBomb()
{
	return this->m_lengthBomb;
}

void GBomb::SetLengthBomb(int lengthBomb)
{
	this->m_lengthBomb = lengthBomb;
}

int GBomb::GetTimeLive()
{
	return this->m_timeLive;
}

void GBomb::SetTimeLive(int timeLive)
{
	this->m_timeLive = timeLive;
}

bool GBomb::IsElapsedBomb(long elapsedMilisecond)
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

void GBomb::Update()
{
	if(IsElapsedBomb(1000/ANIMATERATE_BOMB))
	{
		m_timeLive--;
		if(m_sprite == 'o')
		{
			m_sprite = 'O';
		}
		else
		{
			m_sprite = 'o';
		}
	}
}

void GBomb::Render()
{
	GPutCharToBuffer(m_sprite, m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
}

GBomb::~GBomb()
{
}
