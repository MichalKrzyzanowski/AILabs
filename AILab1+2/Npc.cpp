#include "Npc.h"

Npc::Npc(const sf::Vector2f& pos, const sf::Vector2f& dir)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\moon.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading moon" << std::endl;
	}
	m_position = pos;
	m_velocity = 1.0f;
	m_directionNormalized = dir;

	// normalizing the direction
	float dirLen = (m_directionNormalized.x * m_directionNormalized.x) * (m_directionNormalized.y * m_directionNormalized.y);
	dirLen = sqrtf(dirLen);

	if (dirLen != 0.0f)
	{
		m_directionNormalized = m_directionNormalized / dirLen;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(0.4f, 0.4f);
}

void Npc::update(sf::Time dt)
{
	m_position = m_position + (m_directionNormalized * m_velocity);
	m_sprite.setPosition(m_position);

	wrapAround(m_position, m_sprite);
	
}

void Npc::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
