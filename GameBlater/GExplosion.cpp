#include "GExplosion.h"


GExplosion::GExplosion()
{
	this->m_colorBody = GColors::LIGHT_WHITE;
	this->m_isDead = false;

	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

GExplosion::GExplosion(char sprite, int posX, int posY, int moveX, int moveY, GColors colorBody)
	:GObject(sprite, posX, posY, moveX, moveY)
{
	this->m_colorBody = colorBody;
	this->m_isDead = false;

	m_lastTickTime = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

bool GExplosion::GetIsDead()
{
	return this->m_isDead;
}

void GExplosion::SetIsDead(bool isDead)
{
	this->m_isDead = isDead;
}

bool GExplosion::IsElapsedExplosion(long elapsedMilisecond)
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

void GExplosion::Update()
{
	if(IsElapsedExplosion(TIMELIVE_EXPLOSION))
	{
		m_isDead = true;
	}
}

void GExplosion::Render()
{
	GPutCharToBuffer(m_sprite, m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
}

GExplosion::~GExplosion()
{
}
