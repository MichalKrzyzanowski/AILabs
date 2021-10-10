#include "Player.h"

Player::Player(const MyVector3& pos, const MyVector3& dir)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\ship.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading earth" << std::endl;
	}

	m_position = pos;
	m_velocity = MyVector3{ 0, 0, 0 };
	m_orientation = m_sprite.getRotation();
	m_speed = 0.0f;
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
	m_sprite.setScale(0.5f, 0.5f);
}

void Player::handleEvents(sf::Event e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::W == e.key.code)
		{
			m_isStopping = false;
		}

		if (sf::Keyboard::A == e.key.code)
		{
			m_rotation = -5.5f;
		}

		else if (sf::Keyboard::D == e.key.code)
		{
			m_rotation = 5.5f;
		}
	}

	else if (e.type == sf::Event::KeyReleased)
	{
		if (sf::Keyboard::A == e.key.code)
		{
			m_rotation = 0.0f;
		}

		else if (sf::Keyboard::D == e.key.code)
		{
			m_rotation = 0.0f;
		}

		if (sf::Keyboard::W == e.key.code)
		{
			m_isStopping = true;
		}
	}
}

void Player::update(sf::Time dt)
{
	if (!m_isStopping)
	{
		applyThrust();
	}
	else
	{
		slowDown();
	}

	std::cout << "Length: " << m_velocity.length() << "\n";
	m_orientation = m_orientation + m_rotation;
	m_sprite.setRotation(m_orientation);

	m_acceleration.x = (cosf(m_orientation / 180.0 * PI));
	m_acceleration.y = (sinf(m_orientation / 180.0 * PI));
	m_acceleration.normalise();
	m_acceleration = m_acceleration * m_speed;

	m_velocity += m_acceleration;

	m_position = m_position + m_velocity;

	m_sprite.setPosition(m_position);

	wrapAround(m_position, m_sprite);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::applyThrust()
{
	m_speed = 0.2f;

	if (m_velocity.length() > 5.0f)
	{
		m_velocity.normalise();
		m_velocity = m_velocity * 5.0f;
	}
}

void Player::slowDown()
{
	if (m_velocity.length() <= 0.1f)
	{
		m_velocity.normalise();
		m_velocity = m_velocity * 0.0f;
		m_speed = 0.0f;
	}
	else
	{
		m_speed = -0.01f;
	}
}

float Player::getOrientation(float currentOrientation, MyVector3& velocity)
{
	if (velocity.length() > 0.0f)
	{
		float radians = atan2f(-m_position.x, m_position.y);
		return radians * (180.0f / PI);
	}

	return currentOrientation;
}

void Player::rotate()
{
	float rotationInRads = m_rotation * (180.0f / PI);

	m_directionNormalized.x = m_directionNormalized.x * cosf(rotationInRads) - m_directionNormalized.y * sinf(rotationInRads);
	m_directionNormalized.y = m_directionNormalized.x * sinf(rotationInRads) + m_directionNormalized.y * cosf(rotationInRads);
	m_directionNormalized = normalized(m_directionNormalized);

	m_sprite.setRotation(m_rotation);
}

MyVector3 Player::normalized(MyVector3 vec)
{
	float vecLen = (vec.x * vec.x) + (vec.y * vec.y);
	vecLen = sqrtf(vecLen);

	if (vecLen != 0.0f)
	{
		return vec / vecLen;
	}

	return MyVector3{ 0, 0, 0 };
}
