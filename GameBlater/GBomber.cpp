#include "GBomber.h"


GBomber::GBomber()
	:GObject()
{
	this->m_direction = GDirections::NONE;
	this->m_colorBody = GColors::LIGHT_WHITE;
	this->m_numberPutBomb = 0;
	this->m_numberBomb = 1;
	this->m_lengthBomb = 3;
	this->m_veloc = 4;

	this->m_isImmortal = true;

	m_lastTickTime = timeGetTime();
	m_lastTickTimeImmortal = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

GBomber::GBomber(char sprite, int posX, int posY, int moveX,int moveY, GDirections direction, GColors colorBody, int numberBomb, int lengthBomb, int veloc)
	:GObject(sprite, posX, posY, moveX, moveY)
{
	this->m_direction = direction;
	this->m_colorBody = colorBody;
	this->m_numberPutBomb = 0;
	this->m_numberBomb = numberBomb;
	this->m_lengthBomb = lengthBomb;
	this->m_veloc = veloc;

	this->m_isImmortal = true;

	m_lastTickTime = timeGetTime();
	m_lastTickTimeImmortal = timeGetTime();
	m_currentTickTime = m_lastTickTime;
}

int GBomber::GetNumberPutBomb()
{
	return this->m_numberPutBomb;
}

void GBomber::SetNumberPutBomb(int numberPutBomb)
{
	this->m_numberPutBomb = numberPutBomb;
}

int GBomber::GetNumberBomb()
{
	return this->m_numberBomb;
}

void GBomber::SetNumberBomb(int numberBomb)
{
	this->m_numberBomb = numberBomb;
}

int GBomber::GetLengthBomb()
{
	return this->m_lengthBomb;
}

void GBomber::SetLengthBomb(int lengthBomb)
{
	this->m_lengthBomb = lengthBomb;
}

int GBomber::GetVeloc()
{
	return this->m_veloc;
}

void GBomber::SetVeloc(int veloc)
{
	this->m_veloc = veloc;
}

bool GBomber::GetIsImmortal()
{
	return this->m_isImmortal;
}

void GBomber::SetIsImmortal(bool isImmortal)
{
	this->m_isImmortal = isImmortal;
}

bool GBomber::GetIsPutBomb()
{
	return this->m_isPutBomb;
}

void GBomber::SetIsPutBomb(bool isPutBomb)
{
	this->m_isPutBomb = isPutBomb;
}

bool GBomber::IsElapsedBomber(long elapsedMilisecond)
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

bool GBomber::IsElapsedBomberImmortal(long elapsedMilisecond)
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

bool GBomber::CanMoveUp()
{
	GPoint2D newPosBomber = {m_pos.x, m_pos.y - 1};
	// Ra ngoài map
	if(newPosBomber.y < 0)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bomb)
	if(arrMap[newPosBomber.y][newPosBomber.x] != 0)
	{
		return false;
	}

	return true;
}

bool GBomber::CanMoveDown()
{
	GPoint2D newPosBomber = {m_pos.x, m_pos.y + 1};
	// Ra ngoài map
	if(newPosBomber.y >= MAP_HEIGHT)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosBomber.y][newPosBomber.x] != 0)
	{
		return false;
	}

	return true;
}

bool GBomber::CanMoveLeft()
{
	GPoint2D newPosBomber = {m_pos.x - 1, m_pos.y};
	// Ra ngoài map
	if(newPosBomber.x < 0)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosBomber.y][newPosBomber.x] != 0)
	{
		return false;
	}

	return true;
}

bool GBomber::CanMoveRight()
{
	GPoint2D newPosBomber = {m_pos.x + 1, m_pos.y};
	// Ra ngoài map
	if(newPosBomber.x >= MAP_WIDTH)
	{
		return false;
	}

	// Gặp vật cản (Có thể đá ,gạch hoặc bom)
	if(arrMap[newPosBomber.y][newPosBomber.x] != 0)
	{
		return false;
	}

	return true;
}


void GBomber::Update()
{
	bool l_isPressUp = GIsKeyPress(GKeys::KEY_UP);
	bool l_isPressDown = GIsKeyPress(GKeys::KEY_DOWN);
	bool l_isPressLeft = GIsKeyPress(GKeys::KEY_LEFT);
	bool l_isPressRight = GIsKeyPress(GKeys::KEY_RIGHT);

	bool l_isKeyUp = GIsKeyDown(VK_UP);
	bool l_isKeyDown = GIsKeyDown(VK_DOWN);
	bool l_isKeyLeft = GIsKeyDown(VK_LEFT);
	bool l_isKeyRight = GIsKeyDown(VK_RIGHT);

	if(l_isPressUp || l_isPressDown || l_isPressLeft || l_isPressRight)
	{
			if(l_isPressUp && !(l_isPressDown || l_isPressLeft || l_isPressRight))
			{
				m_direction = GDirections::UP;
				if(CanMoveUp())
				{
					m_pos.y -= m_moveY;
				}
			}

			if(l_isPressDown && !(l_isPressUp || l_isPressLeft || l_isPressRight))
			{
				m_direction = GDirections::DOWN;
				if(CanMoveDown())
				{
					m_pos.y += m_moveY;
				}
			}

			if(l_isPressLeft && !(l_isPressUp || l_isPressDown || l_isPressRight))
			{
				m_direction = GDirections::LEFT;
				if(CanMoveLeft())
				{
					m_pos.x -= m_moveX;
				}
			}

			if(l_isPressRight && !(l_isPressUp || l_isPressDown || l_isPressLeft))
			{
				m_direction = GDirections::RIGHT;
				if(CanMoveRight())
				{
					m_pos.x += m_moveX;
				}
			}

			m_lastTickTime = timeGetTime();
	}
	else
	{
		if(l_isKeyUp && !(l_isKeyDown || l_isKeyLeft || l_isKeyRight))
		{
			if(IsElapsedBomber(1000/m_veloc))
			{
				m_direction = GDirections::UP;
				if(CanMoveUp())
				{
					m_pos.y -= m_moveY;
				}
			}
		}

		if(l_isKeyDown && !(l_isKeyUp || l_isKeyLeft || l_isKeyRight))
		{
			if(IsElapsedBomber(1000/m_veloc))
			{
				m_direction = GDirections::DOWN;
				if(CanMoveDown())
				{
					m_pos.y += m_moveY;
				}
			}
		}

		if(l_isKeyLeft && !(l_isKeyUp || l_isKeyDown || l_isKeyRight))
		{
			if(IsElapsedBomber(1000/m_veloc))
			{
				m_direction = GDirections::LEFT;
				if(CanMoveLeft())
				{
					m_pos.x -= m_moveX;
				}
			}
		}

		if(l_isKeyRight && !(l_isKeyUp || l_isKeyDown || l_isKeyLeft))
		{
			if(IsElapsedBomber(1000/m_veloc))
			{
				m_direction = GDirections::RIGHT;
				if(CanMoveRight())
				{
					m_pos.x += m_moveX;
				}
			}
		}
		
	}

	// Đặt bomb (số bomb đặt nhỏ hơn số bomb có thể đặt)
	m_isPutBomb = GIsKeyPress(GKeys::KEY_SPACE);
	if(m_isPutBomb && m_numberPutBomb >= m_numberBomb)
	{
		m_isPutBomb = false;
	}

	// Kiểm tra bất tử
	if(m_isImmortal)
	{
		if(IsElapsedBomberImmortal(TIMEIMMORTAL_BOMBER))
		{
			m_isImmortal = false;
		}
	}
}

void GBomber::Render()
{
	GPutCharToBuffer(m_sprite, m_pos.x + MAP_LEFT, m_pos.y + MAP_TOP, m_colorBody);
}

GBomber::~GBomber()
{
}
