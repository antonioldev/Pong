#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Bat.hpp"
#include "Ball.hpp"
#include <sstream>
#include <cstdlib>
#include <iomanip>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_game {
	int score = 0;
	int lives = 3;
} t_game;

typedef struct s_sound
{
	sf::SoundBuffer hitBuffer;
	sf::Sound hit;
	sf::SoundBuffer scoreBuffer;
	sf::Sound score;
	sf::SoundBuffer lostBuffer;
	sf::Sound lost;
	sf::Music music;

} t_sound;

typedef struct s_hud {
	sf::Text text;
	sf::Font fontText;
	sf::Text fps;
	sf::Font fontFps;
	int counter = 0;
} t_hud;

void loadHud(t_hud& hud);
void loadSound(t_sound& sound);
void handlePlayerInput(RenderWindow& window, Bat& bat);
void refreshWindow(RenderWindow& window, Bat& bat, Ball& ball, t_hud& hud);
void updateHud(t_hud& hud, t_game& game, Time dt);
void checkCollision(RenderWindow& window, t_game& game, t_sound& sound, Ball& ball, Bat& bat);