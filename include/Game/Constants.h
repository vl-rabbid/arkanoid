#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Arkanoid
{
	const int AUDIO_TRACK_COUNT = 2;
	const unsigned int RENDER_WIDTH = 240;
	const unsigned int RENDER_HEIGHT = 180;
	const std::string GAME_NAME = "Arkanoid";

	const std::string CONFIG_FILE_NAME = "config.ini";
	const int LEADERBOARD_SIZE = 15;

	const int MAX_MENU_BUTTONS = 4;
	const int DISPLAYED_LEVEL_COUNT = 3;
	const float SELECTOR_SPEED = 40.f;
	const float SLIDER_SPEED = 30.f;
	const float INPUT_MARKER_INTERVAL = 0.5f;
	const int LEADERBOARD_DISPLAYED = 5;

	const float DELAY_COUNTDOWN = 3.2f;
	const float DELAY_GAME_OVER = 1.5f;

	const float PADDLE_SPEED = 300.f;
	const float PADDLE_HEIGHT = 10.f;

	const sf::Color COLOR_TINT(0, 0, 0, 100);
	const sf::Color COLOR_SHADOW(0, 0, 0, 150);
	const sf::Color COLOR_TEXT(54, 46, 40);
	const sf::Color COLOR_INPUT_TEXT(184, 159, 128);
}
