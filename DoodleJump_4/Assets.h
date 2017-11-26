#pragma once

struct CAssets
{
public:
	CAssets();
	~CAssets();

	void AddTexture(sf::Texture & texture, const std::string & path);
	void AddRepeatedTexture(sf::Texture & texture, const std::string & path);
	void AddFont(sf::Font & font, const std::string & path);
	void AddImage(sf::Image & image, const std::string & path);

	sf::Texture BACKGROUND_TEXTURE;

	sf::Texture PLATE_STATIC_TEXTURE;

	sf::Texture DOODLE_LEFT_TEXTURE;
	sf::Texture DOODLE_RIGHT_TEXTURE;

	sf::Texture BUTTON_ACTIVE_TEXTURE;
	sf::Texture BUTTON_INACTIVE_TEXTURE;

	sf::Image WINDOW_ICON;

	sf::Font ARIAL_FONT;

private:
};
