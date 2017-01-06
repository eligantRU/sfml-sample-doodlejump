#pragma once

#include <array>

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

	void GeneratePlates();
	size_t GetUppermostPlateID();
	void BuildPlate(const size_t basePlateID, const size_t replacingPlateID);
	sf::Vector2f GetCenterPlatePosition(const size_t plateID) const;

	sf::RenderWindow m_window;
	sf::View m_view;

	std::array<CPlate, NUMBER_PLATES> m_plates;
	CDoodle m_hero;
	bool m_isLeft = false;
	bool m_isRight = false;

	float m_posY = DOODLE_INITIAL_POSITION.y;
	bool m_isUp = false;
	bool m_isDown = false;
};