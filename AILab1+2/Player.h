#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utility.h"
#include "MyVector3.h"

class Player
{

private:
	const float m_SPEED_LIMIT{ 5.0f };

	MyVector3 m_position;
	MyVector3 m_acceleration{};
	float m_speed;

	MyVector3 m_velocity;
	MyVector3 m_directionNormalized;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_orientation;
	float m_rotation;

	bool m_isStopping{ true };

public:
	Player(const MyVector3& pos, const MyVector3& dir);

	void handleEvents(sf::Event e);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void applyThrust();
	void slowDown();
	float getOrientation(float currentOrientation, MyVector3& velocity);

	void rotate();
	MyVector3 normalized(MyVector3 vec);
};

