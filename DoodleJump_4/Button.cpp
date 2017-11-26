#include "stdafx.h"

#include "sheet.h"
#include "Button.h"

namespace
{

static const sf::Vector2f BUTTON_SIZE(100, 29);

}

CButton::CButton(const std::string & text, const sf::Vector2f & position, CAssets & assets)
	:m_assets(assets)
{
	SetTexture(m_assets.BUTTON_INACTIVE_TEXTURE);
	SetPosition(position);
	SetText(text);
	m_text.setFont(m_assets.ARIAL_FONT);
	m_text.setCharacterSize(20);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::Black);
}

void CButton::SetTexture(sf::Texture & texture)
{
	m_body.setTexture(texture);
}

void CButton::SetPosition(sf::Vector2f position)
{
	m_body.setPosition(position);
	SetText(m_text.getString());
}

float CButton::GetStringLengthPx(const std::string & str) const
{
	sf::Text text;
	text.setFont(m_assets.ARIAL_FONT);
	text.setCharacterSize(20);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setString(str);
	return (text.findCharacterPos(str.length()).x - text.findCharacterPos(0).x);
}

void CButton::SetText(const std::string & text)
{
	// http://stackoverflow.com/questions/13244928/getting-dimensions-of-text-in-sfml
	// NOTE: getLocalBounds/getGlobalBounds and sf::FloatRect::contains(sf::Vector2f const& point)

	m_text.setString(text);
	const float width = m_body.getPosition().x + (BUTTON_SIZE.x - GetStringLengthPx(text)) / 2;
	const float height = m_body.getPosition().y;
	m_text.setPosition(width, height);
}

void CButton::OnMouse(sf::Vector2i mousePosition)
{
	const auto buttonPosition = m_body.getPosition();
	if (((mousePosition.y >= buttonPosition.y) && (mousePosition.y <= buttonPosition.y + BUTTON_SIZE.y)
		&& (mousePosition.x >= buttonPosition.x) && (mousePosition.x <= buttonPosition.x + BUTTON_SIZE.x)))
	{
		SetTexture(m_assets.BUTTON_ACTIVE_TEXTURE);
	}
	else
	{
		SetTexture(m_assets.BUTTON_INACTIVE_TEXTURE);
	}
}

bool CButton::OnClick(sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		auto buttonPosition = m_body.getPosition();
		const sf::Vector2i mousePosition(event.mouseButton.x, event.mouseButton.y);
		if (((mousePosition.y >= buttonPosition.y) && (mousePosition.y <= buttonPosition.y + BUTTON_SIZE.y)
			&& (mousePosition.x >= buttonPosition.x) && (mousePosition.x <= buttonPosition.x + BUTTON_SIZE.x)))
		{
			SetTexture(m_assets.BUTTON_INACTIVE_TEXTURE);
			return true;
		}
	}
	return false;
}

void CButton::Draw(sf::RenderWindow & window) const
{
	window.draw(m_body);
	window.draw(m_text);
}
