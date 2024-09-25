#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <sstream>
#include <cstdlib>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_game {
	int score = 0;
	int lives = 3;
} t_game;

typedef struct s_hud {
	sf::Text text;
	//sf::Text border;
	sf::Font fontText;
	//sf::Font fontBorder;

} t_hud;

void loadHud(t_hud& hud);