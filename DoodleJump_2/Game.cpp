#include "stdafx.h"

#include "Game.h"
#include "sheet.h"

CGame::CGame()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, WINDOW_STYLE)
{
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(WINDOW_FRAME_LIMIT);

	m_plates.emplace_back(sf::Vector2f(200, 800));
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
	for (auto & plate : m_plates)
	{
		plate.Update();
	}
	CheckCylinderEffect();

	GeneratePlates();
}

void CGame::Render()
{
	m_window.clear(WHITE);

	for (const auto & plate : m_plates)
	{
		plate.Draw(m_window);
	}
	m_hero.Draw(m_window);
}

void CGame::CheckCylinderEffect()
{
	auto doodlePosition = m_hero.GetPosition();
	if (doodlePosition.x <= -DOODLE_SIZE.x)
	{
		m_hero.SetPosition({ WINDOW_SIZE.x - DOODLE_SIZE.x, doodlePosition.y });
	}
	if (doodlePosition.x >= WINDOW_SIZE.x)
	{
		m_hero.SetPosition({ 0, doodlePosition.y });
	}
}

void CGame::GeneratePlates()
{
	float viewPositionY = DOODLE_INITIAL_POSITION.y; //m_view.getCenter().y;
	for (auto & plate : m_plates)
	{
		if ((plate.GetPosition().y > viewPositionY + WINDOW_SIZE.y / 2) && (m_plates.size() < 10))
		{
			BuildPlate(GetUppermostPlateID());
		}
	}
}

size_t CGame::GetUppermostPlateID()
{
	auto it = std::min_element(m_plates.begin(), m_plates.end(), [](const auto & lhs, const auto & rhs) {
		return (lhs.GetPosition().y < rhs.GetPosition().y);
	});
	return std::distance(m_plates.begin(), it);
}

void CGame::BuildPlate(const size_t basePlateID)
{
	sf::Vector2f startingPoint = GetCenterPlatePosition(basePlateID);
	auto offsetY = rand() % int(DOODLE_MAX_JUMP_HEIGHT);
	auto offsetX = (sqrt(DOODLE_MAX_JUMP_HEIGHT * DOODLE_MAX_JUMP_HEIGHT - offsetY * offsetY));
	if (rand() % 2)
	{
		offsetX *= -1;
	}
	float x = float(int(startingPoint.x + offsetX + WINDOW_SIZE.x - PLATE_SIZE.x)
	                % int(WINDOW_SIZE.x - PLATE_SIZE.x));
	float y = startingPoint.y - offsetY;
	m_plates.emplace_back(sf::Vector2f(x, y));
}

sf::Vector2f CGame::GetCenterPlatePosition(const size_t plateID) const
{
	float x = m_plates[plateID].GetPosition().x + PLATE_SIZE.x / 2;
	float y = m_plates[plateID].GetPosition().y + PLATE_SIZE.y / 2;
	return sf::Vector2f(x, y);
}
