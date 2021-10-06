#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utility.h"

class Player
{

private:
	const float m_SPEED_LIMIT{ 5.0f };

	sf::Vector2f m_position;
	float m_speed;
	sf::Vector2f m_velocity;
	sf::Vector2f m_directionNormalized;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_rotation;

public:
	Player(const sf::Vector2f& pos, const sf::Vector2f& dir);

	void handleEvents(sf::Event e);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void rotate();
	sf::Vector2f normalized(sf::Vector2f vec);
};

