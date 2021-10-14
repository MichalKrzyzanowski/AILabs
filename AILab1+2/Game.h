/// <summary>
/// author Pete Lowe May 2019
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include "Player.h"
#include "Npc.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	

	sf::Font m_font;
	sf::RenderWindow m_window; // main SFML window
	
	Player m_ship;
	Npc m_seekShip;
	Npc m_wanderShip;
	//Npc m_slowArriveShip;
	Npc m_fastArriveShip;
	//Npc m_pursueShip;
	

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

