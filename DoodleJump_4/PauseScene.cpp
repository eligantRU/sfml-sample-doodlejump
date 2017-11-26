#include "stdafx.h"

#include "PauseScene.h"

namespace
{

static const auto BUTTON_TEXT = "Back";

static const sf::Vector2f BUTTON_POSITION(248, 200);

}

CPauseScene::CPauseScene(sf::RenderWindow & window, CAssets & assets)
	:m_window(window)
	,m_assets(assets)
	,m_backButton(BUTTON_TEXT, BUTTON_POSITION, m_assets)
{
	m_view.reset(sf::FloatRect(0, 0, float(WINDOW_SIZE.x), float(WINDOW_SIZE.y)));
}

SceneInfo CPauseScene::Advance(float dt)
{
	m_nextSceneType = SceneType::PauseScene;
	CheckEvents();
	Update(dt);
	m_window.setView(m_view);
	Render();
	m_window.display();

	return SceneInfo(m_nextSceneType);
}

void CPauseScene::CheckEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		ÑheckMouseOnButtons(sf::Mouse::getPosition(m_window));
		CheckMouseClick(m_window, event);

		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void CPauseScene::ÑheckMouseOnButtons(const sf::Vector2i & mousePosition)
{
	m_backButton.OnMouse(mousePosition);
}

void CPauseScene::CheckMouseClick(sf::RenderWindow & window, sf::Event & event)
{
	if (m_backButton.OnClick(event))
	{
		m_nextSceneType = SceneType::GameScene;
	}
}

void CPauseScene::Update(float dt)
{
	(void)&dt;
}

void CPauseScene::Render()
{
	m_window.clear(sf::Color::White);

	m_backButton.Draw(m_window);
}
