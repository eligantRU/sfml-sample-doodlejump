#pragma once

#include "sheet.h"

class CDoodle
{
public:
	CDoodle();
	~CDoodle() = default;

	void Update();
	void Draw(sf::RenderWindow & window);

	void UpdateDirection(bool isLeft, bool isRight);
	void SetDirection(const DirectionX & newDirection);
	DirectionX GetDirection() const;

	void SetPosition(const sf::Vector2f & pos);
	sf::Vector2f GetPosition() const;

	void Move(const sf::Vector2f & deltaPosition);

	sf::Vector2f GetOffset() const;

private:
	float GetVerticalOffset() const;
	float GetHorizontalOffset() const;
	
	DirectionX m_direction = DirectionX::None;

	sf::RectangleShape m_body;
};
