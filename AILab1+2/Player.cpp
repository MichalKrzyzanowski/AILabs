#include "Player.h"

Player::Player(const MyVector3& pos)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\ship.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading earth" << std::endl;
	}

	m_position = pos;
	m_velocity = MyVector3{};
	m_orientation = 0.0;
	m_speed = 10.0;
	m_rotation = DegToRadConvert(m_angleInDegrees);
	rotateRight(0.0); // get the ship moving

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);

	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0, m_sprite.getGlobalBounds().height / 2.0);
	m_sprite.setScale(0.5, 0.5);
}

void Player::handleEvents(sf::Event e)
{
}

void Player::update(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { applyThrust(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { slowDown(); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { rotateLeft(dt.asSeconds()); }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { rotateRight(dt.asSeconds()); }



	std::cout << "Length: " << m_velocity.length() << "\n";

	m_position = m_position + m_velocity * dt.asSeconds();

	m_sprite.setPosition(m_position);

	wrapAround(m_position, m_sprite);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::applyThrust()
{
	m_speed += m_SPEED_INC;

	if (m_speed > m_MAX_SPEED)
	{
		m_speed = m_MAX_SPEED;
	}
	m_velocity.normalise();
	m_velocity = m_velocity * m_speed;
}

void Player::slowDown()
{
	m_speed -= m_SPEED_INC;

	if (m_speed < m_MIN_SPEED)
	{
		m_speed = m_MIN_SPEED;
	}
	m_velocity.normalise();
	m_velocity = m_velocity * m_speed;
}

void Player::rotateRight(double dt)
{
	m_orientation += m_rotation * dt;
	m_velocity = MyVector3{ cosf(m_orientation), sinf(m_orientation), 0.0 } * m_speed;

	m_sprite.setRotation(RadToDegConvert(atan2f(m_velocity.y, m_velocity.x)));
}

void Player::rotateLeft(double dt)
{
	m_orientation -= m_rotation * dt;
	m_velocity = MyVector3{ cosf(m_orientation), sinf(m_orientation), 0.0 } * m_speed;

	m_sprite.setRotation(RadToDegConvert(atan2f(m_velocity.y, m_velocity.x)));
}
