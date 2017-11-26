#pragma once

#include "sheet.h"
#include "Assets.h"

class CPlate
{
public:
	CPlate(CAssets & assets);

	void Update(float dt) const;
	void Draw(sf::RenderWindow & window) const;

	void SetPosition(const sf::Vector2f & pos);
	sf::Vector2f GetPosition() const;

	void SetTexture(const sf::Texture & texture);

private:
	CAssets & m_assets;

	sf::Sprite m_body;
};
