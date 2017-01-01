#pragma once

#include "Doodle.h"

class CGame
{
public:
	CGame();
	~CGame() = default;

	void DoGameLoop();

private:
	void Update();
	void Render();

	void CheckEvents();
	void CheckKeyboardEvents(const sf::Event & event);
	void CheckKeyPressed(const sf::Event & event, bool & isNeedUpdate);
	void CheckKeyReleased(const sf::Event & event, bool & isNeedUpdate);

	void CheckCylinderEffect();

	sf::View m_view;
	sf::RenderWindow m_window;

	CDoodle m_hero;
	bool m_isLeft = false;
	bool m_isRight = false;
};
