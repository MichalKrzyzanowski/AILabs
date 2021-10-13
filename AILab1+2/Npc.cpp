#include "Npc.h"

Npc::Npc(const sf::Vector2f& pos, const std::string& filename, const std::string& name, Player* target)
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\" + filename + ".png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading " << filename << std::endl;
	}

	m_target = target;

	m_position = pos;
	m_velocity = MyVector3{};
	m_orientation = 0.0;
	m_speed = 10.0;
	m_rotation = DegToRadConvert(m_angleInDegrees);
	//rotateRight(0.0); // get the ship moving

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
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num1)
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
			//Seek::seek();
		}

		m_position = m_position + m_velocity * dt.asSeconds();

		m_sprite.setPosition(m_position);

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
