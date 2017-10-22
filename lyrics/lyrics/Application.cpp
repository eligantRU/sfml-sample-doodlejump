#include "stdafx.h"

#include "Application.h"

namespace
{

static const auto WINDOW_TITLE = "Application";
static const sf::Vector2u WINDOW_SIZE = { 600, 600 };

static const auto CIRCLE_RADIUS = 20.f;
static const auto CIRCLE_PRECIZION = 50;
static const auto INITIAL_CIRCLE_POSITION = 0.5f * sf::Vector2f(
	WINDOW_SIZE.x - 2 * CIRCLE_RADIUS,
	WINDOW_SIZE.y - 2 * CIRCLE_RADIUS
);

static const auto ORBIT_RADIUS = 200.f;
static const auto ANGULAR_VELOCITY = static_cast<float>(M_PI / 2);

}

Application::Application()
	:m_window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE)
	,m_shape(CIRCLE_RADIUS, CIRCLE_PRECIZION)
{
	m_shape.setPosition(INITIAL_CIRCLE_POSITION);
	m_shape.setFillColor(sf::Color::White);
}

void Application::Execute()
{
	while (m_window.isOpen())
	{
		const auto dt = m_clock.restart().asSeconds();

		CheckEvents();
		Update(dt);
		Render();
		m_window.display();
	}
}

void Application::CheckEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Application::Update(float dt)
{
	m_alpha += ANGULAR_VELOCITY * dt;
	const sf::Vector2f position = {
		ORBIT_RADIUS * cosf(m_alpha),
		ORBIT_RADIUS * sinf(m_alpha)
	};

	m_shape.setPosition(INITIAL_CIRCLE_POSITION + position);
}

void Application::Render()
{
	m_window.clear();

	m_window.draw(m_shape);
}
