#include "stdafx.h"

#include "Game.h"
#include "sheet.h"

CGame::CGame()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, WINDOW_STYLE)
{
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(WINDOW_FRAME_LIMIT);

	m_view.reset(sf::FloatRect(0, 0, float(WINDOW_SIZE.x), float(WINDOW_SIZE.y)));

	for (auto & plate : m_plates)
	{
		plate.SetPosition(sf::Vector2f(WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y / 2 + DOODLE_INITIAL_POSITION.y));
	}
	m_plates[0].SetPosition(DOODLE_INITIAL_POSITION);

	m_plates[1].SetPosition(sf::Vector2f(150, 600));
	m_plates[2].SetPosition(sf::Vector2f(200, 400));
	m_plates[3].SetPosition(sf::Vector2f(270, 500));
	m_plates[4].SetPosition(sf::Vector2f(90, 40));
	m_plates[5].SetPosition(sf::Vector2f(340, -100));
}

void CGame::DoGameLoop()
{
	while (m_window.isOpen())
	{
		CheckEvents();
		Update();
		m_window.setView(m_view);
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
		if (m_isUp)
		{
			m_posY -= STEP;
		}
		if (m_isDown)
		{
			m_posY += STEP;
		}
		m_hero.UpdateDirection(m_isLeft, m_isRight);
		m_hero.SetPosition(sf::Vector2f(m_hero.GetPosition().x, m_posY));
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
		case sf::Keyboard::W:
			m_isUp = true;
			isNeedUpdate = true;
			break;
		case sf::Keyboard::S:
			m_isDown = true;
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
		case sf::Keyboard::W:
			m_isUp = false;
			isNeedUpdate = true;
			break;
		case sf::Keyboard::S:
			m_isDown = false;
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

	m_view.setCenter(m_hero.GetPosition());

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
	auto viewPositionY = m_view.getCenter().y;
	for (int i = 0; i < NUMBER_PLATES; ++(++i))
	{
		if ((m_plates[i].GetPosition().y > viewPositionY + WINDOW_SIZE.y / 2) &&
		    (m_plates[i + 1].GetPosition().y > viewPositionY + WINDOW_SIZE.y / 2))
		{
			auto uppermostPlateID = GetUppermostPlateID();
			BuildPlate(uppermostPlateID, i);
			BuildPlate(uppermostPlateID, i + 1);
		}
	}
}

size_t CGame::GetUppermostPlateID() const
{
	auto it = std::min_element(m_plates.begin(), m_plates.end(), [](const auto & lhs, const auto & rhs) {
		return (lhs.GetPosition().y < rhs.GetPosition().y);
	});
	return std::distance(m_plates.begin(), it);
}

void CGame::BuildPlate(const size_t basePlateID, const size_t replacingPlateID)
{
	auto startingPoint = GetCenterPlatePosition(basePlateID);
	auto offsetY = rand() % int(DOODLE_MAX_JUMP_HEIGHT);
	auto offsetX = sqrt(DOODLE_MAX_JUMP_HEIGHT * DOODLE_MAX_JUMP_HEIGHT - offsetY * offsetY);
	if (rand() % 2)
	{
		offsetX *= -1;
	}
	auto x = float(int(startingPoint.x + offsetX + WINDOW_SIZE.x - PLATE_SIZE.x)
	               % int(WINDOW_SIZE.x - PLATE_SIZE.x));
	auto y = startingPoint.y - offsetY;
	m_plates[replacingPlateID].SetPosition(sf::Vector2f(x, y));
}

sf::Vector2f CGame::GetCenterPlatePosition(const size_t plateID) const
{
	auto x = m_plates[plateID].GetPosition().x + PLATE_SIZE.x / 2;
	auto y = m_plates[plateID].GetPosition().y + PLATE_SIZE.y / 2;
	return sf::Vector2f(x, y);
}
