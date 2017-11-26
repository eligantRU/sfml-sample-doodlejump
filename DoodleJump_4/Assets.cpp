#include "stdafx.h"

#include "Assets.h"
#include "sheet.h"

CAssets::CAssets()
{
	AddRepeatedTexture(BACKGROUND_TEXTURE, "res/images/background.png");
	AddTexture(DOODLE_LEFT_TEXTURE, "res/images/Doodle45_45Left.png");
	AddTexture(DOODLE_RIGHT_TEXTURE, "res/images/Doodle45_45Right.png");
	AddTexture(PLATE_STATIC_TEXTURE, "res/images/Plate_63_15_Green.png");

	AddFont(ARIAL_FONT, "res/fonts/arial.ttf");
	AddImage(WINDOW_ICON, "res/images/icon.png");
}

CAssets::~CAssets()
{

}

void CAssets::AddTexture(sf::Texture & texture, const std::string & path)
{
	if (!texture.loadFromFile(path))
	{
		MessageBoxA(nullptr, std::string("File " + path + " not founded").c_str(), "Error", MB_ICONERROR | MB_OK);
		_exit(-1);
	}
	texture.setSmooth(true);
	texture.setRepeated(false);
}

void CAssets::AddRepeatedTexture(sf::Texture & texture, const std::string & path)
{
	AddTexture(texture, path);
	texture.setRepeated(true);
}

void CAssets::AddFont(sf::Font & font, const std::string & path)
{
	if (!font.loadFromFile(path))
	{
		MessageBoxA(nullptr, std::string("File " + path + " not founded").c_str(), "Error", MB_ICONERROR | MB_OK);
		_exit(-1);
	}
}

void CAssets::AddImage(sf::Image & image, const std::string & path)
{
	if (!image.loadFromFile(path))
	{
		MessageBoxA(nullptr, std::string("File " + path + " not founded").c_str(), "Error", MB_ICONERROR | MB_OK);
		_exit(-1);
	}
}
