#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Utility.h"
#include "Seek.h"
#include "Wander.h"
#include "Arrive.h"
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
	double m_maxSpeed;
	double m_minSpeed;
	double m_initialMaxSpeed;

	MyVector3 m_position;
	double m_speed{ m_minSpeed };
	double m_angleInDegrees{ 70.0 };

	MyVector3 m_velocity{};

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Text m_nameText;

	bool m_isDisplayed{ true };
	bool m_fontSet{ false };

	double m_orientation{};
	double m_rotation;
	Seek m_seek;
	Wander m_wander;
	Arrive m_arrive;
	AIStates m_currentState{ AIStates::NONE };

	Player* m_target;

public:
	Npc(const sf::Vector2f& pos,
		const std::string& filename,
		const std::string& name,
		Player* target,
		double maxSpeed = 100.0,
		double minSpeed = 10.0);

	void handleEvents(sf::Event e);
	void update(sf::Time dt);
	void render(sf::RenderWindow& window);

	void toggleDisplay();
	void setFont(const sf::Font& font);

	// getters
	double speed() { return m_speed; }
	double maxSpeed() { return m_maxSpeed; }
	double initialMaxSpeed() { return m_initialMaxSpeed; }
	double minSpeed() { return m_minSpeed; }
	MyVector3& velocity() { return m_velocity; }
	MyVector3 position() { return m_position; }
	double orientation() { return m_orientation; }
	Player* target() { return m_target; }

	// setters
	void setVelocity(MyVector3 vel) { m_velocity = vel; }
	void setSpeed(double speed) { m_speed = speed; }
	void setMaxSpeed(double maxSpeed) { m_maxSpeed = maxSpeed; }
	void setBehaviour(AIStates behaviour) { m_currentState = behaviour; }
};

#endif // !NPC_H