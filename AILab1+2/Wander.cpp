#include "Wander.h"

Wander::Wander(Npc* npc) :
	m_npc{ npc }
{
}

void Wander::update(sf::Time dt)
{
	m_delay -= dt.asSeconds();

	if (m_delay <= 0.0)
	{
		//MyVector3 tempVel = MyVector3{ m_npc->velocity() };
		//tempVel.normalise();
		
		// find new target
		//MyVector3 offset = m_npc->position() + (tempVel * 50.0);
		double radians = DegToRadConvert(static_cast<double>(rand() % 360));
		m_target = MyVector3{ cosf(radians), sinf(radians), 0.0 };
		m_delay = m_INITIAL_DELAY;
	}

	m_target = MyVector3{ m_target - m_npc->position() };
	m_target.normalise();

	if (m_npc->velocity().length() > m_npc->maxSpeed())
	{
		m_npc->velocity().normalise();
		m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
	}

	m_npc->velocity() += m_target * dt.asSeconds() * m_npc->speed();
}
