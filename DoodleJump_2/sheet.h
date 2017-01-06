#pragma once

static const sf::Vector2u WINDOW_SIZE = { 600, 800 };
static const std::string WINDOW_TITLE = "DoodleJump: Demo #2";
static const auto WINDOW_STYLE = sf::Style::Close;
static const unsigned WINDOW_FRAME_LIMIT = 60;

static const sf::Vector2f DOODLE_SIZE = { 50, 80 };
static const sf::Vector2f DOODLE_INITIAL_POSITION = 0.5f * (sf::Vector2f(WINDOW_SIZE) - DOODLE_SIZE);
static const float DOODLE_MAX_JUMP_HEIGHT = 100.f; // TODO: fix magic number!

static const sf::Vector2f PLATE_SIZE = { 80, 20 };
static const size_t NUMBER_PLATES = 80; //2 * (WINDOW_SIZE.y / PLATE_SIZE.y);

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
