#include "Arrive.h"

Arrive::Arrive(Npc* npc) :
	m_npc{ npc }
{
}

void Arrive::update(sf::Time dt)
{
	MyVector3 target{ m_npc->target()->position() - m_npc->position() };
	double distance = target.length();
	target.normalise();

	if (distance < m_slowRadius)
	{
		m_npc->setSpeed(-m_npc->minSpeed());
	}
	else if (distance > m_arriveRadius)
	{
		m_npc->setSpeed(m_npc->minSpeed());
	}
	else
	{
		m_npc->setSpeed(m_npc->minSpeed() * (distance / m_slowRadius));
	}


	if (m_npc->velocity().length() > m_npc->maxSpeed())
	{
		m_npc->velocity().normalise();
		m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
	}

	m_npc->velocity() += target * dt.asSeconds() * m_npc->speed();
}
