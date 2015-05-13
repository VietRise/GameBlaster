#include "GGift.h"


GGift::GGift()
	:GObject()
{
	this->m_colorBody = GColors::LIGHT_WHITE;
	this->m_typeGift = GGiftType::NO;

	this->m_isImmortal = true;
	
	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

GGift::GGift(int posX, int posY, int moveX, int moveY, GColors colorBody, GGiftType typeGift)
	:GObject(' ', posX, posY, moveX, moveY)
{
	this->m_colorBody = colorBody;
	this->m_typeGift = typeGift;

	this->m_isImmortal = true;

	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

GGiftType GGift::GetTypeGift()
{
	return this->m_typeGift;
}

void GGift::SetTypeGift(GGiftType typeGift)
{
	this->m_typeGift = typeGift;
}

bool GGift::GetIsImmortal()
{
	return this->m_isImmortal;
}

void GGift::SetIsImmortal(bool isImmortal)
{
	this->m_isImmortal = isImmortal;
}

bool GGift::IsElapsedGift(long elapsedMilisecond)
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

void GGift::Update()
{
	
	if(m_isImmortal && IsElapsedGift(TIME_IMMORTAL))
	{
		if(m_typeGift != GGiftType::WINDOW)
		{
			m_isImmortal = false;
		}
	}
}

void GGift::Render()
{
	switch(m_typeGift)
	{
	case GGiftType::NUMBERBOMB:
		GPutCharToBuffer('N', m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
		break;
	case GGiftType::LENGHTBOMB:
		GPutCharToBuffer('L', m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
		break;
	case GGiftType::VELOC:
		GPutCharToBuffer('V', m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
		break;
	case GGiftType::WINDOW:
		GPutCharToBuffer(178, m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
		break;
	default:
		break;
	}
}

GGift::~GGift()
{
}
