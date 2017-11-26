#pragma once

#include "sheet.h"
#include "Assets.h"

class CButton
{
public:
	CButton() = delete;
	CButton(const std::string & text, const sf::Vector2f & position, CAssets & assets);
	~CButton() = default;

	void OnMouse(sf::Vector2i mousePosition);
	bool OnClick(sf::Event & event);
	void SetText(const std::string & text);
	void SetPosition(sf::Vector2f position);
	void SetTexture(sf::Texture & texture);
	void Draw(sf::RenderWindow & window) const;

private:
	float GetStringLengthPx(const std::string & str) const;

	CAssets & m_assets;
	sf::Sprite m_body;
	sf::Text m_text;
};
