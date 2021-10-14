#ifndef ARRIVE_H
#define ARRIVE_H

#include "Utility.h"
#include "MyVector3.h"

class Npc;

class Arrive
{
private:
	Npc* m_npc;
	double m_slowRadius{ 100.0 };
	double m_arriveRadius{ 20.0 };

public:
	Arrive(Npc* npc);
	void update(sf::Time dt);
};

#include "Npc.h"
#endif // !ARRIVE_H

