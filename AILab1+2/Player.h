#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utility.h"
#include "MyVector3.h"

class Player
{

private:
	const double m_MAX_SPEED{ 500.0 };
	const double m_MIN_SPEED{ 5.0 };
	const double m_SPEED_INC{ 2.0 };

	MyVector3 m_position;
	double m_speed;
	double m_angleInDegrees{ 70.0 };

	MyVector3 m_velocity;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	double m_orientation;
	double m_rotation;

public:
	Player(const MyVector3& pos);

	void handleEvents(sf::Event e);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void applyThrust();
	void slowDown();
	void rotateLeft(double dt);
	void rotateRight(double dt);

	MyVector3 velocity() { return m_velocity; }
	MyVector3 position() { return m_position; }
	double orientation() { return m_orientation; }
};

