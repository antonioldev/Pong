#include "Bat.hpp"

// Bat constructor, takes in the starting x and y position and positions the bat there
Bat::Bat(float startX, float startY) : _position(startX, startY)
{
	_shape.setSize(sf::Vector2f(50, 5));
	_shape.setPosition(_position);
}

FloatRect Bat::getPosition()
{
	return _shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return _shape;
}

void Bat::moveLeft()
{
	_isMovingLeft = true;
}

void Bat::moveRight()
{
	_isMovingRight = true;
}

void Bat::stopLeft()
{
	_isMovingLeft = false;
}

void Bat::stopRight()
{
	_isMovingRight = false;
}

void Bat::update(Time dt)
{
	if (_isMovingLeft)
	{
		_position.x -= _speed * dt.asSeconds();
	}

	if (_isMovingRight)
	{
		_position.x += _speed * dt.asSeconds();
	}

	_shape.setPosition(_position);
}