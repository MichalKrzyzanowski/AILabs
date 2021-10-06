#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Utility.h"

class Npc
{
private:
	sf::Vector2f m_position;
	float m_velocity;
	sf::Vector2f m_directionNormalized;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	Npc(const sf::Vector2f& pos, const sf::Vector2f& dir);
	
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);
};

