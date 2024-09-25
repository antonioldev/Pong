
#include "Pong.hpp"
#include "Bat.hpp"

int main()
{
	VideoMode vm(WIDTH, HEIGHT);

	RenderWindow window(vm, "Pong", Style::Fullscreen);

	Bat bat(WIDTH / 2, HEIGHT - 20);

	t_game game;
	t_hud hud;
	loadHud(hud);
	
	Clock clock;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		//Handle player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		//Handle player input
		if (Keyboard::isKeyPressed(Keyboard::Left))
			bat.moveLeft();
		else
			bat.stopLeft();
		if (Keyboard::isKeyPressed(Keyboard::Right))
			bat.moveRight();
		else
			bat.stopRight();
		Time dt = clock.restart();
		bat.update(dt);

		//Update the HUD text
		std::stringstream ss;
		ss << "Score: " << game.score << "    Lives: " << game.lives;
		hud.text.setString(ss.str());

		//Update the window
		window.clear();
		window.draw(hud.text);
		
		window.draw(bat.getShape());
		window.display();
	}
	return (0);
}
