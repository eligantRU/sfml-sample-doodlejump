#pragma once

#include "Doodle.h"
#include "Plate.h"

class CGame
{
public:
	CGame();

	void DoGameLoop();

private:
	void Update();
	void Render();

	void CheckEvents();
	void CheckKeyboardEvents(const sf::Event & event);
	void CheckKeyPressed(const sf::Event & event, bool & isNeedUpdate);
	void CheckKeyReleased(const sf::Event & event, bool & isNeedUpdate);

	void CheckCylinderEffect();

	sf::RenderWindow m_window;

	std::vector<CPlate> m_plates;
	CDoodle m_hero;
	bool m_isLeft = false;
	bool m_isRight = false;
};
