#include "GEnemy.h"


GEnemy::GEnemy()
	:GObject()
{
	m_direction = GDirections::NONE;
	m_colorBody = GColors::LIGHT_WHITE;
	m_type = GEnemyType::HEART;
	m_blood = 1;

	m_isImmortal = true;

	m_lastTickTime = timeGetTime();
	m_lastTickTimeImmortal = timeGetTime();
	m_currentTickTime = m_lastTickTime;

	m_stepUp = 0;
	m_stepDown = 0;
	m_stepLeft = 0;
	m_stepRight = 0;
}

GEnemy::GEnemy(char sprite, int posX, int posY, int moveX, int moveY, GDirections direction, GColors colorBody, GEnemyType type)
	:GObject(sprite, posX, posY, moveX, moveY)
{
	this->m_direction = direction;
	this->m_colorBody = colorBody;
	this->m_type = type;
	switch(m_type)
	{
	case GEnemyType::HEART:
		this->m_blood = 1;
		break;
	case GEnemyType::DIAMOND:
		this->m_blood = 2;
		break;
	case GEnemyType::CLUB:
		this->m_blood = 3;
		break;
	}
	m_isImmortal = true;

	m_lastTickTime = timeGetTime();
	m_lastTickTimeImmortal = timeGetTime();
	m_currentTickTime = m_lastTickTime;

	m_stepUp = 0;
	m_stepDown = 0;
	m_stepLeft = 0;
	m_stepRight = 0;

	
	switch(rand()%4)
	{
	case 0:
		this->m_direction = GDirections::UP;
		break;
	case 1:
		this->m_direction = GDirections::DOWN;
		break;
	case 2:
		this->m_direction = GDirections::LEFT;
		break;
	case 3:
		this->m_direction = GDirections::RIGHT;
		break;
	}
}

GColors GEnemy::GetColorBody()
{
	return this->m_colorBody;
}

void GEnemy::SetColorBody(GColors colorBody)
{
	m_colorBody = colorBody;
}

void GEnemy::SetColorBody()
{
	m_isImmortal = true;
	m_lastTickTimeImmortal = timeGetTime();
	if(m_blood > 0)
	{
		if(m_blood == 1)
		{
			m_colorBody = GColors::LIGHT_WHITE;
		}
		else if(m_blood == 2)
		{
			m_colorBody = GColors::LIGHT_MAGENTA;
		}
	}
}

GEnemyType GEnemy::GetType()
{
	return this->m_type;
}

void GEnemy::SetType(GEnemyType type)
{
	this->m_type = type;
}

int GEnemy::GetBlood()
{
	return this->m_blood;
}

void GEnemy::SetBlood(int blood)
{
	this->m_blood = blood;
}

bool GEnemy::GetIsImmortal()
{
	return this->m_isImmortal;
}

void GEnemy::SetIsImmortal(bool isImmortal)
{
	this->m_isImmortal = isImmortal;
}

bool GEnemy::IsElapsedEnemy(long elapsedMilisecond)
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

bool GEnemy::IsElapsedEnemyImmortal(long elapsedMilisecond)
{
	m_currentTickTime = timeGetTime();

	if(m_currentTickTime - m_lastTickTimeImmortal >= elapsedMilisecond)
	{
		m_lastTickTimeImmortal = m_currentTickTime;
		return true;
	}
	else
	{
		return false;
	}
}

bool GEnemy::CanMoveUp()
{
	GPoint2D newPosEnemy = {m_pos.x, m_pos.y - 1};
	// Ra ngoài map
	if(newPosEnemy.y < 0)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosEnemy.y][newPosEnemy.x] != 0)
	{
		return false;
	}

	return true;
}

bool GEnemy::CanMoveDown()
{
	GPoint2D newPosEnemy = {m_pos.x, m_pos.y + 1};
	// Ra ngoài map
	if(newPosEnemy.y >= MAP_HEIGHT)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosEnemy.y][newPosEnemy.x] != 0)
	{
		return false;
	}

	return true;
}

bool GEnemy::CanMoveLeft()
{
	GPoint2D newPosEnemy = {m_pos.x - 1, m_pos.y};
	// Ra ngoài map
	if(newPosEnemy.x < 0)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosEnemy.y][newPosEnemy.x] != 0)
	{
		return false;
	}

	return true;
}

bool GEnemy::CanMoveRight()
{
	GPoint2D newPosEnemy = {m_pos.x + 1, m_pos.y};
	// Ra ngoài map
	if(newPosEnemy.x >= MAP_WIDTH)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosEnemy.y][newPosEnemy.x] != 0)
	{
		return false;
	}

	return true;
}
	
void GEnemy::RandomDiretion()
{
	int direction = rand()%3;
	switch(m_direction)
	{
	case GDirections::UP:
		m_stepUp = 0;
		switch(direction)
		{
		case 0:
			m_direction = GDirections::DOWN;
			break;
		case 1:
			m_direction = GDirections::LEFT;
			break;
		case 2:
			m_direction = GDirections::RIGHT;
			break;
		}
		break;
	case GDirections::DOWN:
		m_stepDown = 0;
		switch(direction)
		{
		case 0:
			m_direction = GDirections::UP;
			break;
		case 1:
			m_direction = GDirections::LEFT;
			break;
		case 2:
			m_direction = GDirections::RIGHT;
			break;
		}
		break;
	case GDirections::LEFT:
		m_stepLeft = 0;
		switch(direction)
		{
		case 0:
			m_direction = GDirections::UP;
			break;
		case 1:
			m_direction = GDirections::DOWN;
			break;
		case 2:
			m_direction = GDirections::RIGHT;
			break;
		}
		break;
	case GDirections::RIGHT:
		m_stepRight = 0;
		switch(direction)
		{
		case 0:
			m_direction = GDirections::UP;
			break;
		case 1:
			m_direction = GDirections::DOWN;
			break;
		case 2:
			m_direction = GDirections::LEFT;
			break;
		}
		break;
	default:
		break;
	}
}

void GEnemy::Update()
{
	if(IsElapsedEnemy(1000/ANIMATERATE_ENEMY))
	{
		// Di chuyển, nếu gặp vật cản thì chuyển sang 3 hướng còn lại
		switch(m_direction)
		{
		case GDirections::UP:
			if(CanMoveUp())
			{
				m_pos.y -= m_moveY;
				m_stepUp++;
				if(m_stepUp > STEPCHANGEDIRECTION_MIN)
				{
					int stepChangeDirection = rand()%3;
					if(stepChangeDirection == 0)
					{
						RandomDiretion();
					}
					//RandomDiretion();
				}
			}
			else
			{
				RandomDiretion();
			}
			break;
		case GDirections::DOWN:
			if(CanMoveDown())
			{
				m_pos.y += m_moveY;
				m_stepDown++;
				if(m_stepDown > STEPCHANGEDIRECTION_MIN)
				{
					int stepChangeDirection = rand()%3;
					if(stepChangeDirection == 0)
					{
						RandomDiretion();
					}
					//RandomDiretion();
				}
			}
			else
			{
				RandomDiretion();
			}
			break;
		case GDirections::LEFT:
			if(CanMoveLeft())
			{
				m_pos.x -= m_moveX;
				m_stepLeft++;
				if(m_stepLeft > STEPCHANGEDIRECTION_MIN)
				{
					int stepChangeDirection = rand()%3;
					if(stepChangeDirection == 0)
					{
						RandomDiretion();
					}
					//RandomDiretion();
				}
			}
			else
			{
				RandomDiretion();
			}
			break;
		case GDirections::RIGHT:
			if(CanMoveRight())
			{
				m_pos.x += m_moveX;
				m_stepRight++;
				if(m_stepRight > STEPCHANGEDIRECTION_MIN)
				{
					int stepChangeDirection = rand()%3;
					if(stepChangeDirection == 0)
					{
						RandomDiretion();
					}
					//RandomDiretion();
				}
			}
			else
			{
				RandomDiretion();
			}
			break;
		default:
			break;
		}
	}
	
	if(m_isImmortal)
	{
		if(IsElapsedEnemyImmortal(TIMEIMMORTAL_ENEMY))
		{
			m_isImmortal = false;
		}
	}
}

void GEnemy::Render()
{
	GPutCharToBuffer(m_sprite, m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
}

GEnemy::~GEnemy()
{
}
