#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Utility.h"
#include "Seek.h"
#include "Player.h"

enum class AIStates
{
	SEEK,
	WANDER,
	ARRIVE,
	PURSUE,
	NONE
};

class Npc
{
private:
	const double m_MAX_SPEED{ 250.0 };
	const double m_MIN_SPEED{ 5.0 };
	const double m_SPEED_INC{ 2.0 };

	MyVector3 m_position;
	double m_speed;
	double m_angleInDegrees{ 70.0 };

	MyVector3 m_velocity;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Text m_nameText;

	bool m_isDisplayed{ true };
	bool m_fontSet{ false };

	double m_orientation;
	double m_rotation;

	AIStates m_currentState{ AIStates::NONE };
	Player* m_target;

public:
	Npc(const sf::Vector2f& pos, const std::string& filename, const std::string& name, Player* target);
	
	void handleEvents(sf::Event e);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void toggleDisplay();
	void setFont(const sf::Font& font);
};

