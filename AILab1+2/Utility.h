#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include "MyVector3.h"

inline void wrapAround(MyVector3& pos, const sf::Sprite& obj)
{	
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

inline float DegToRadConvert(float deg)
{
	return deg * (PI / 180.0f);
}

inline float RadToDegConvert(float rad)
{
	return rad * (180.0f / PI);
}