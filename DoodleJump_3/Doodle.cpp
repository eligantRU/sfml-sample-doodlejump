#include "stdafx.h"

#include "Doodle.h"
#include "sheet.h"

CDoodle::CDoodle()
{
	m_body.setFillColor(GREEN);
	m_body.setSize(DOODLE_SIZE);
	m_body.setPosition(DOODLE_INITIAL_POSITION);
}

void CDoodle::Update()
{
	Move(GetOffset());
}

void CDoodle::Draw(sf::RenderWindow & window)
{
	window.draw(m_body);
}

void CDoodle::UpdateDirection(bool isLeft, bool isRight)
{
	if (isLeft && isRight)
	{
		SetDirection(DirectionX::None);
	}
	else if (isLeft)
	{
		SetDirection(DirectionX::Left);
	}
	else if (isRight)
	{
		SetDirection(DirectionX::Right);
	}
	else
	{
		SetDirection(DirectionX::None);
	}
}

void CDoodle::SetDirection(const DirectionX & newDirection)
{
	m_direction = newDirection;
}

DirectionX CDoodle::GetDirection() const
{
	return m_direction;
}

void CDoodle::SetPosition(const sf::Vector2f & pos)
{
	m_body.setPosition(pos);
}

sf::Vector2f CDoodle::GetPosition() const
{
	return m_body.getPosition();
}

void CDoodle::Move(const sf::Vector2f & deltaPosition)
{
	m_body.move(deltaPosition);
}

sf::Vector2f CDoodle::GetOffset() const
{
	return sf::Vector2f(GetHorizontalOffset(), GetVerticalOffset());
}

float CDoodle::GetHorizontalOffset() const
{
	float positionX = 0;
	switch (GetDirection())
	{
	case DirectionX::Right:
		positionX += STEP;
		break;
	case DirectionX::Left:
		positionX -= STEP;
		break;
	default:
		break;
	}
	return positionX;
}

float CDoodle::GetVerticalOffset() const
{
	return 0;
}
