#pragma once

static const sf::Vector2u WINDOW_SIZE = { 600, 800 };
static const std::string WINDOW_TITLE = "DoodleJump: Demo #2";
static const auto WINDOW_STYLE = sf::Style::Close;
static const unsigned WINDOW_FRAME_LIMIT = 60;

static const float ACCELERATION = 1.f;
static const float PLATE_DELTA_VELOCITY = 22.f;

static const sf::Vector2f DOODLE_SIZE = { 50, 80 };
static const sf::Vector2f DOODLE_INITIAL_POSITION = 0.5f * (sf::Vector2f(WINDOW_SIZE) - DOODLE_SIZE);
static const float DOODLE_MAX_JUMP_HEIGHT = 242.f; // t * PLATE_DELTA_VELOCITY - 0.5 * t^2, t = 22

static const sf::Vector2f PLATE_SIZE = { 80, 20 };
static const unsigned NUMBER_PLATES = 80; // = 2 * (WINDOW_SIZE.y / PLATE_SIZE.y);
static const sf::Vector2f PLATE_INITIAL_POSITION = { WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y + DOODLE_INITIAL_POSITION.y };

static const auto STEP = 6.f;

static const sf::Color GREEN = { 0, 127, 0 };
static const sf::Color BROWN = { 65, 25, 0 };
static const sf::Color WHITE = { 255, 255, 255 };

enum class DirectionX
{
	None = 0,
	Left,
	Right
};
