#include "Seek.h"

Seek::Seek(Npc* npc) :
	m_npc{ npc }
{

}

void Seek::update(sf::Time dt)
{
	if (m_npc->velocity().length() > m_npc->maxSpeed())
	{
		m_npc->velocity().normalise();
		m_npc->velocity() = m_npc->velocity() * m_npc->maxSpeed();
	}

	MyVector3 target{ m_npc->target()->position() - m_npc->position() };
	target.normalise();
	m_npc->velocity() += target * dt.asSeconds() * m_npc->speed();
}
