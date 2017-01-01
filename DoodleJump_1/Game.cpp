#include "stdafx.h"

#include "Game.h"
#include "sheet.h"

CGame::CGame()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, sf::Style::Close)
{
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(WINDOW_FRAME_LIMIT);

	m_view.reset(sf::FloatRect(0, 0, float(WINDOW_SIZE.x), float(WINDOW_SIZE.y)));
	m_view.setCenter(WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y / 2.f);
	m_window.setView(m_view);
}

void CGame::DoGameLoop()
{
	while (m_window.isOpen())
	{
		CheckEvents();
		Update();
		Render();
		m_window.display();
	}
}

void CGame::CheckEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		CheckKeyboardEvents(event);

		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void CGame::CheckKeyboardEvents(const sf::Event & event)
{
	bool isNeedUpdate = false;
	CheckKeyPressed(event, isNeedUpdate);
	CheckKeyReleased(event, isNeedUpdate);

	if (isNeedUpdate)
	{
		m_hero.UpdateDirection(m_isLeft, m_isRight);
	}
}

void CGame::CheckKeyPressed(const sf::Event & event, bool & isNeedUpdate)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::A:
			m_isLeft = true;
			isNeedUpdate = true;
			break;
		case sf::Keyboard::D:
			m_isRight = true;
			isNeedUpdate = true;
			break;
		default:
			break;
		}
	}
}

void CGame::CheckKeyReleased(const sf::Event & event, bool & isNeedUpdate)
{
	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::A:
			m_isLeft = false;
			isNeedUpdate = true;
			break;
		case sf::Keyboard::D:
			m_isRight = false;
			isNeedUpdate = true;
			break;
		default:
			break;
		}
	}
}

void CGame::Update()
{
	m_hero.Update();
	CheckCylinderEffect();
	m_window.setView(m_view);
}

void CGame::Render()
{
	m_window.clear(WHITE);

	m_hero.Draw(m_window);
}

void CGame::CheckCylinderEffect()
{
	auto doodlePosition = m_hero.GetPosition();

	if (doodlePosition.x <= -DOODLE_SIZE.x)
	{
		m_hero.SetPosition(sf::Vector2f(float(WINDOW_SIZE.x - DOODLE_SIZE.x), doodlePosition.y));
	}
	if (doodlePosition.x >= WINDOW_SIZE.x)
	{
		m_hero.SetPosition(sf::Vector2f(0.f, doodlePosition.y));
	}
}
