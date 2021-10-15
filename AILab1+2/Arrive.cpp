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

	printf("%f\n", m_npc->velocity().length());
	/*printf("%f\n", m_npc->velocity().length());

	if (distance < m_slowRadius)
	{
		target = target * m_slowDownSpeed * (distance / m_slowRadius);
		printf("HIT\n");
	}
	else
	{
		target = target * m_slowDownSpeed;
	}*/

	if (distance < m_arriveRadius)
	{
		m_npc->setMaxSpeed(0.01);
	}
	else if (distance > m_slowRadius)
	{
		m_npc->setMaxSpeed(m_npc->initialMaxSpeed());
	}
	else
	{
		printf("HIT\n");
		m_npc->setMaxSpeed(m_npc->minSpeed());
		//m_npc->setMaxSpeed(m_npc->initialMaxSpeed() * distance / m_slowRadius);
	}

	MyVector3 unit = target / distance * m_npc->minSpeed();



	if (distance < m_arriveRadius)
	{
		if (m_npc->velocity().length() > m_npc->maxSpeed())
		{
			m_npc->velocity().normalise();
			m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
		}

		m_npc->velocity() += (unit / 100.0) * m_npc->maxSpeed() * dt.asSeconds();
	}
	else
	{
		if (m_npc->velocity().length() > m_npc->maxSpeed())
		{
			m_npc->velocity().normalise();
			m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
		}

		m_npc->velocity() += unit * m_npc->maxSpeed() * dt.asSeconds();
	}
}
