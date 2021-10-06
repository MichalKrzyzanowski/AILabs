#include "Player.h"

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& dir)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\ship.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading earth" << std::endl;
	}

	m_position = pos;
	m_velocity = sf::Vector2f{ 0, 0 };
	m_speed = 1.0f;
	m_rotation = 0.0f;
	m_directionNormalized = dir;
	m_directionNormalized = normalized(m_directionNormalized);
	// normalizing the direction
	/*float dirLen = (m_directionNormalized.x * m_directionNormalized.x) + (m_directionNormalized.y * m_directionNormalized.y);
	dirLen = sqrtf(dirLen);

	if (dirLen != 0.0f)
	{
		m_directionNormalized = m_directionNormalized / dirLen;
	}*/

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);

	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0f, m_sprite.getGlobalBounds().height / 2.0f);
}

void Player::handleEvents(sf::Event e)
{
	if (sf::Keyboard::Up == e.key.code || sf::Keyboard::W == e.key.code)
	{
		m_speed += 0.5;

		if (m_speed >= m_SPEED_LIMIT) m_speed = m_SPEED_LIMIT;

	}

	if (sf::Keyboard::Down == e.key.code || sf::Keyboard::S == e.key.code)
	{
		m_speed -= 0.5;

		if (m_speed <= -m_SPEED_LIMIT) m_speed = -m_SPEED_LIMIT;
	}

	if (sf::Keyboard::Left == e.key.code || sf::Keyboard::A == e.key.code)
	{
		m_sprite.setRotation(m_sprite.getRotation() - 5.0f);
	}

	if (sf::Keyboard::Right == e.key.code || sf::Keyboard::D == e.key.code)
	{
		m_sprite.setRotation(m_sprite.getRotation() + 5.0f);
	}
}

void Player::update(sf::Time dt)
{
	//m_velocity = m_directionNormalized * m_speed;
	m_velocity.x = (cosf(m_sprite.getRotation() / 180 * PI) * m_speed);
	m_velocity.y = (sinf(m_sprite.getRotation() / 180 * PI) * m_speed);

	m_position += m_velocity;
	m_sprite.setPosition(m_position);

	wrapAround(m_position, m_sprite);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::rotate()
{
	float rotationInRads = m_rotation * (PI / 180);

	m_directionNormalized.x = m_directionNormalized.x * cosf(rotationInRads) - m_directionNormalized.y * sinf(rotationInRads);
	m_directionNormalized.y = m_directionNormalized.x * sinf(rotationInRads) + m_directionNormalized.y * cosf(rotationInRads);
	m_directionNormalized = normalized(m_directionNormalized);

	m_sprite.setRotation(m_rotation);
}

sf::Vector2f Player::normalized(sf::Vector2f vec)
{
	float vecLen = (vec.x * vec.x) + (vec.y * vec.y);
	vecLen = sqrtf(vecLen);

	if (vecLen != 0.0f)
	{
		return vec / vecLen;
	}

	return sf::Vector2f{ 0, 0 };
}
