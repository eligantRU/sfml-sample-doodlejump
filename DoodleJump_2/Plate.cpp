#include "stdafx.h"

#include "Plate.h"

CPlate::CPlate()
{
	m_body.setFillColor(BROWN);
	m_body.setSize(PLATE_SIZE);
}

void CPlate::Update() const
{

}

void CPlate::Draw(sf::RenderWindow & window) const
{
	window.draw(m_body);
}

void CPlate::SetPosition(const sf::Vector2f & pos)
{
	m_body.setPosition(pos);
}

sf::Vector2f CPlate::GetPosition() const
{
	return m_body.getPosition();
}
