#include "Player.h"

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& dir)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\ship.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading earth" << std::endl;
	}

	m_position = pos;
	m_speed = 1.0f;
	m_rotation = 0.0f;
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
}

void Player::handleEvents(sf::Event e)
{
	if (sf::Keyboard::Up == e.key.code || sf::Keyboard::W == e.key.code)
	{
		m_speed += 0.5;
	}

	if (sf::Keyboard::Down == e.key.code || sf::Keyboard::S == e.key.code)
	{
		m_speed -= 0.5;
	}
}

void Player::update(sf::Time dt)
{
	m_velocity = m_directionNormalized * m_speed;
	m_position += m_velocity;
	m_sprite.setPosition(m_position);

	wrapAround(m_position, m_sprite);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
