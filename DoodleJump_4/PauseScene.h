#pragma once

#include "sheet.h"
#include "Assets.h"
#include "Button.h"

class CPauseScene
{
public:
	CPauseScene() = delete;
	CPauseScene(sf::RenderWindow & window, CAssets & assets);
	~CPauseScene() = default;

	SceneInfo Advance(float dt);

private:
	void Update(float dt);
	void Render();

	void CheckEvents();
	void ÑheckMouseOnButtons(const sf::Vector2i & mousePosition);
	void CheckMouseClick(sf::RenderWindow & window, sf::Event & event);

	CAssets & m_assets;
	sf::RenderWindow & m_window;

	CButton m_backButton;

	sf::View m_view;

	SceneType m_nextSceneType = SceneType::PauseScene;
};
