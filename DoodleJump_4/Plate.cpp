#include "stdafx.h"

#include "Plate.h"

CPlate::CPlate(CAssets & assets)
	:m_assets(assets)
{
	SetTexture(m_assets.PLATE_STATIC_TEXTURE);
}

void CPlate::Update(float dt) const
{
	(void)&dt;
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

void CPlate::SetTexture(const sf::Texture & texture)
{
	m_body.setTextureRect(sf::IntRect(0, 0, int(texture.getSize().x), int(texture.getSize().y)));
	m_body.setTexture(texture);
}
