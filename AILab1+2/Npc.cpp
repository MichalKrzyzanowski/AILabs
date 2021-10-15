#include "Npc.h"

Npc::Npc(const sf::Vector2f& pos,
	const std::string& filename,
	const std::string& name,
	Player* target,
	double maxSpeed,
	double minSpeed) :
	m_maxSpeed{ maxSpeed },
	m_minSpeed{ minSpeed },
	m_seek{ this },
	m_wander{ this },
	m_arrive{ this }
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\" + filename + ".png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading " << filename << std::endl;
	}

	m_target = target;
	m_initialMaxSpeed = maxSpeed;
	m_position = pos;
	m_rotation = DegToRadConvert(m_angleInDegrees);

	m_orientation = m_target->orientation();
	m_velocity = m_target->velocity();

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);

	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0, m_sprite.getGlobalBounds().height / 2.0);
	m_sprite.setScale(0.5, 0.5);

	m_nameText.setCharacterSize(24u);
	m_nameText.setString(name);
	m_nameText.setFillColor(sf::Color::Black);
	m_nameText.setPosition(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width * 0.5,
		m_sprite.getPosition().y + m_sprite.getGlobalBounds().height * 0.5);
}

void Npc::handleEvents(sf::Event e)
{
	// seek
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num1 && m_nameText.getString() == "Seek")
	{
		toggleDisplay();
	}

	// wander
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num2 && m_nameText.getString() == "Wander")
	{
		toggleDisplay();
	}

	// slow arrive
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num3 && m_nameText.getString() == "ArriveSlow")
	{
		toggleDisplay();
	}

	// fast arrive
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num4 && m_nameText.getString() == "ArriveFast")
	{
		toggleDisplay();
	}
}

void Npc::update(sf::Time dt)
{
	if (m_isDisplayed)
	{
		if (m_currentState == AIStates::SEEK)
		{
			m_seek.update(dt);
		}

		else if (m_currentState == AIStates::WANDER)
		{
			m_wander.update(dt);
		}

		else if(m_currentState == AIStates::ARRIVE)
		{
			m_arrive.update(dt);
		}


		m_position = m_position + m_velocity * dt.asSeconds();

		m_sprite.setPosition(m_position);

		m_sprite.setRotation(RadToDegConvert(atan2f(m_velocity.y, m_velocity.x)));

		m_nameText.setPosition(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width * 0.5,
			m_sprite.getPosition().y + m_sprite.getGlobalBounds().height * 0.5);
		wrapAround(m_position, m_sprite);
	}
}

void Npc::render(sf::RenderWindow& window)
{
	if (m_isDisplayed)
	{
		window.draw(m_sprite);
		window.draw(m_nameText);
	}
}

void Npc::toggleDisplay()
{
	m_isDisplayed = !m_isDisplayed;
}

void Npc::setFont(const sf::Font& font)
{
	if (!m_fontSet)
	{
		m_nameText.setFont(font);
		m_fontSet = true;
	}
}
