#ifndef WANDER_H
#define WANDER_H

#include "Utility.h"
#include "MyVector3.h"

class Npc;

class Wander
{
private:
	Npc* m_npc;
	const double m_INITIAL_DELAY{ 2.0 };
	const double m_OFFSET{ 50.0 };
	double m_delay{ m_INITIAL_DELAY };
	MyVector3 m_target{};

	bool m_initialTargetSet{ false };

public:
	Wander(Npc* npc);
	void update(sf::Time dt);
};

#include "Npc.h"
#endif // !WANDER_H

