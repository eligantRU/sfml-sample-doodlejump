#pragma once

#include <vector>

#include "Doodle.h"
#include "Assets.h"
#include "Plate.h"

class CGameScene
{
public:
	CGameScene() = delete;
	CGameScene(sf::RenderWindow & window, CAssets & assets);
	~CGameScene() = default;

	SceneInfo Advance(float dt);

private:
	void Update(float dt);
	void Render();

	void CheckEvents();
	void CheckKeyboardEvents(const sf::Event & event);
	void CheckKeyPressed(const sf::Event & event, bool & isNeedUpdate);
	void CheckKeyReleased(const sf::Event & event, bool & isNeedUpdate);

	void CheckCylinderEffect();

	void GeneratePlates();
	unsigned GetUppermostPlateIndex() const;
	void BuildPlate(const unsigned basePlateID, const unsigned replacingPlateID);
	sf::Vector2f GetCenterPlatePosition(const unsigned plateID) const;

	CAssets & m_assets;
	sf::RenderWindow & m_window;

	sf::View m_view;

	sf::Sprite m_background;
	std::vector<CPlate> m_plates;
	CDoodle m_hero;
	bool m_isLeft = false;
	bool m_isRight = false;

	float m_posY = DOODLE_INITIAL_POSITION.y;
	bool m_isUp = false;
	bool m_isDown = false;

	SceneType m_nextSceneType = SceneType::GameScene;
};
