#pragma once

#include "SFML/Graphics.hpp"
using namespace sf;

class Bat
{
private:
	Vector2f		_position;
	RectangleShape	_shape;
	float			_speed = 1000.0f;
	bool			_isMovingRight = false;
	bool			_isMovingLeft = false;
public:
	Bat(float startX, float startY);
	FloatRect		getPosition();
	RectangleShape	getShape();
	void			moveLeft();
	void			moveRight();
	void			stopLeft();
	void			stopRight();
	void			update(Time dt);
};