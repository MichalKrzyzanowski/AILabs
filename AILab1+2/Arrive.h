#ifndef ARRIVE_H
#define ARRIVE_H

#include "Utility.h"
#include "MyVector3.h"

class Npc;

class Arrive
{
private:
	Npc* m_npc;
	double m_slowRadius{ 200.0 };
	double m_arriveRadius{ 100.0 };
	double m_slowDownSpeed{ 10.0 };

public:
	Arrive(Npc* npc);
	void update(sf::Time dt);
};

#include "Npc.h"
#endif // !ARRIVE_H

