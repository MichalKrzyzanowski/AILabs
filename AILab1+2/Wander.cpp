#include "Wander.h"

Wander::Wander(Npc* npc) :
	m_npc{ npc }
{
}

void Wander::update(sf::Time dt)
{
	// get the initial direction
	if (!m_initialTargetSet)
	{
		MyVector3 temp = m_npc->velocity();
		temp.normalise();
		MyVector3 ahead = m_npc->target()->position() + temp;
		double radians = DegToRadConvert(static_cast<double>(rand() % 180));
		m_target = (MyVector3{ cosf(radians), sinf(radians), 0.0 } *m_OFFSET) + ahead;
		m_initialTargetSet = true;
	}

	m_delay -= dt.asSeconds();

	MyVector3 temp = m_npc->velocity();
	temp.normalise();

	if (m_delay <= 0.0)
	{
		MyVector3 ahead = m_npc->position() + temp;
		double radians = DegToRadConvert(static_cast<double>(rand() % 180));
		m_target = (MyVector3{ cosf(radians), sinf(radians), 0.0 } *m_OFFSET) + ahead;
		m_delay = m_INITIAL_DELAY;
	}

	m_target.normalise();

	m_target = m_target * m_npc->minSpeed();

	if (m_npc->velocity().length() > m_npc->maxSpeed())
	{
		m_npc->velocity().normalise();
		m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
	}

	m_npc->velocity() += m_target * m_npc->speed() * dt.asSeconds();
}
