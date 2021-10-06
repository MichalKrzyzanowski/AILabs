#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

inline void wrapAround(sf::Vector2f& pos, const sf::Sprite& obj)
{
	//std::cout << pos.x << " " << pos.y << "\n";
	
	std::cout << pos.y << " " << SCREEN_WIDTH << "\n";
	// right border
	if (pos.x > SCREEN_WIDTH)
	{
		pos.x = -obj.getGlobalBounds().width;
	}

	// left border
	if (pos.x + obj.getGlobalBounds().width < 0.0f)
	{
		pos.x = SCREEN_WIDTH;
	}

	// top border
	if (pos.y + obj.getGlobalBounds().height < 0.0f )
	{
		pos.y = SCREEN_HEIGTH;
	}

	// bottom border
	if (pos.y > SCREEN_HEIGTH)
	{
		pos.y = -obj.getGlobalBounds().height;
	}
}