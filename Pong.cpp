
#include "Pong.hpp"
#include "Bat.hpp"
#include "Ball.hpp"

int main()
{
	VideoMode vm(WIDTH, HEIGHT);

	RenderWindow window(vm, "Pong", Style::Fullscreen);

	Bat bat(WIDTH / 2, HEIGHT - 20);
	Ball ball(WIDTH / 2, 0);

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

		// Call the input handling function
		handlePlayerInput(window, bat);
		
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		
		//Check for collison
		checkCollision(window, game, ball, bat);

		//Update the HUD text
		updateHud(hud, game, dt);
		
		//Update the window
		refreshWindow(window, bat, ball, hud);
		
	}
	return (0);
}
