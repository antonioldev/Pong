#include "Pong.hpp"

using namespace sf;

void loadHud(t_hud& hud)
{
	hud.fontText.loadFromFile("fonts/CollegiateOutlineFLF.ttf");
	hud.fontFps.loadFromFile("fonts/CollegiateFLF.ttf");

	hud.text.setFont(hud.fontText);
	hud.text.setString("Score: 0    Lives: 3");
	hud.text.setCharacterSize(75);
	hud.text.setPosition(20, 20);
	hud.text.setFillColor(Color::White);

	hud.fps.setFont(hud.fontFps);
	hud.fps.setString("0 fps");
	hud.fps.setCharacterSize(15);
	hud.fps.setFillColor(Color::White);
	hud.fps.setPosition(1800, 20);

}

void loadSound(t_sound& sound)
{
	sound.hitBuffer.loadFromFile("wav/hit.wav");
	sound.hit.setBuffer(sound.hitBuffer);

	sound.scoreBuffer.loadFromFile("wav/score.wav");
	sound.score.setBuffer(sound.scoreBuffer);

	sound.lostBuffer.loadFromFile("wav/lost.wav");
	sound.lost.setBuffer(sound.lostBuffer);

	sound.music.openFromFile("wav/bgMusic.mp3");
}

void refreshWindow(RenderWindow& window, Bat& bat, Ball& ball, t_hud& hud)
{

	window.clear();
	window.draw(hud.text);
	window.draw(hud.fps);
	window.draw(bat.getShape());
	window.draw(ball.getShape());
	window.draw(ball.getShapeCircle());
	window.display();
}

void updateHud(t_hud& hud, t_game& game, Time dt)
{
	hud.counter++;
	if (hud.counter == 500)
	{
		hud.counter = 0;
		std::stringstream ss;
		ss << "Score: " << game.score << "    Lives: " << game.lives;
		hud.text.setString(ss.str());

		std::stringstream ss2;
		ss2 << std::fixed << std::setprecision(2);
		float fps = 1.0f / dt.asSeconds();
		ss2 << std::setw(7) << std::setfill(' ') << fps;
		ss2 << " fps";
		hud.fps.setString(ss2.str());
		hud.counter = 0;
	}
}

void checkCollision(RenderWindow& window, t_game& game, t_sound& sound, Ball& ball, Bat& bat)
{
	if (ball.getPosition().top < 0)
	{
		ball.reboundBatorTop();
		sound.score.play();
		game.score++;
		if (game.score % 3 == 0)
			ball.increaseSpeed(250.0f);
	}
	else if (ball.getPosition().top > window.getSize().y)
	{
		ball.reboundBottom();
		game.lives--;
		sound.lost.play();
		if (game.lives < 1)
		{
			game.score = 0;
			game.lives = 3;
		}
	}
	else if (ball.getPosition().intersects(bat.getPosition()))
	{
		sound.hit.play();
		ball.reboundBatorTop();
	}
	if (ball.getPosition().left < 0
		|| ball.getPosition().left + ball.getPosition().width > window.getSize().x)
	{
		ball.reboundSides();
	}
}

void handlePlayerInput(RenderWindow& window, Bat& bat)
{
	//Handle player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
		window.close();

	//Handle player input
	if (Keyboard::isKeyPressed(Keyboard::Left) && bat.getPosition().left > 0 )
		bat.moveLeft();
	else
		bat.stopLeft();
	if (Keyboard::isKeyPressed(Keyboard::Right) && ((bat.getPosition().left + bat.getPosition().width) < WIDTH))
		bat.moveRight();
	else
		bat.stopRight();
}