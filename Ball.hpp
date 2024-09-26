#pragma once

#include "SFML/Graphics.hpp"
using namespace sf;

class Ball
{
private:
	Vector2f		_position;
	RectangleShape	_shape;
	CircleShape		_circle;
	float			_speed = 2000.0f;
	float			_directionX = 0.2f;
	float			_directionY = 0.2f;
public:
	Ball(float startX, float startY);
	FloatRect		getPosition();
	RectangleShape	getShape();
	CircleShape		getShapeCircle();
	float			getXVelocity();
	void			reboundSides();
	void			reboundBatorTop();
	void			reboundBottom();
	void			update(Time dt);
};
