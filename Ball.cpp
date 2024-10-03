#include "Ball.hpp"

Ball::Ball(float startX, float startY) : _position(startX, startY)
{
	_shape.setSize(sf::Vector2f(10, 10));
	_shape.setPosition(_position);
	_circle.setFillColor(Color::Red);
	_circle.setRadius(8.0f);
	_circle.setPosition(_position);
}

FloatRect Ball::getPosition()
{
	return _shape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return _shape;
}

CircleShape		Ball::getShapeCircle()
{
	return _circle;
}

float Ball::getXVelocity()
{
	return _directionX;
}

void Ball::reboundSides()
{
	_directionX = -_directionX;
}

void Ball::reboundBatorTop()
{
	_directionY = -_directionY;
}


void Ball::reboundBottom()
{
	_position.y = 0;
	_position.x = 500;
}

void Ball::update(Time dt)
{
	_position.y += _directionY * _speed * dt.asSeconds();
	_position.x += _directionX * _speed * dt.asSeconds();
	_shape.setPosition(_position);
	_circle.setPosition(_position);
}

void Ball::increaseSpeed(float add)
{
	_speed += add;
}