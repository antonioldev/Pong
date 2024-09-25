#include "Pong.hpp"

using namespace sf;

void loadHud(t_hud& hud)
{
	hud.fontText.loadFromFile("fonts/CollegiateOutlineFLF.ttf");
	//hud.fontBorder.loadFromFile("fonts/CollegiateOutlineFLF.ttf");
	
	hud.text.setFont(hud.fontText);
	hud.text.setCharacterSize(75);
	hud.text.setPosition(20, 20);
	hud.text.setFillColor(Color::White);

	/*hud.border.setFont(hud.fontBorder);
	hud.border.setCharacterSize(75);
	hud.border.setPosition(20, 20);
	hud.border.setFillColor(Color::White);*/
}