#pragma once

#include "sheet.h"

class CPlate
{
public:
	CPlate();

	void Update(float dt) const;
	void Draw(sf::RenderWindow & window) const;

	void SetPosition(const sf::Vector2f & pos);
	sf::Vector2f GetPosition() const;

private:
	sf::RectangleShape m_body;
};
