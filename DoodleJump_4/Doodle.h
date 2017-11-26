#pragma once

#include "sheet.h"
#include "Assets.h"

class CDoodle
{
public:
	CDoodle(CAssets & assets);

	void Update(float dt);
	void Draw(sf::RenderWindow & window);

	void UpdateDirection(bool isLeft, bool isRight);
	void SetDirection(const DirectionX & newDirection);
	DirectionX GetDirection() const;

	void SetPosition(const sf::Vector2f & pos);
	sf::Vector2f GetPosition() const;

	void Move(const sf::Vector2f & deltaPosition);

	sf::Vector2f GetOffset() const;

	void SetTexture(const sf::Texture & texture);

private:
	float GetVerticalOffset() const;
	float GetHorizontalOffset() const;

	DirectionX m_direction = DirectionX::None;

	CAssets m_assets;

	sf::Sprite m_body;
};
