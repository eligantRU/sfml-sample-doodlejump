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
	float GetVerticalOffset() const;
	float GetHorizontalOffset() const;

private:
	DirectionX m_lastDirection = DirectionX::None;
	DirectionX m_direction = DirectionX::None;
	float m_speedY = 0;
	sf::Vector2f m_positionBeforeDown;

	sf::RectangleShape m_body;
};
