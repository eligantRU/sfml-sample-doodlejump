#pragma once

class Application
{
public:
	Application();
	~Application() = default;

	void Execute();

private:
	void CheckEvents();
	void Update(float dt);
	void Render();

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	sf::CircleShape m_shape;
	float m_alpha = 0;
};
