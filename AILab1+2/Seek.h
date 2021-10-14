#ifndef SEEK_H
#define SEEK_H

#include "MyVector3.h"

class Npc;

class Seek
{
private:
	Npc* m_npc;

public:
	Seek(Npc* npc);

	void update(sf::Time dt);
};

#include "Npc.h"
#endif // !SEEK_H