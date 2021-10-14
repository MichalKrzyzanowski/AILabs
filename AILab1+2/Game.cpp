/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGTH, 32U }, "SFML Game" },
	m_ship{ sf::Vector2f{300, 100} },
	m_seekShip{ sf::Vector2f{300, 300}, "seekShip", "Seek", &m_ship },
	m_wanderShip{ sf::Vector2f{400, 400}, "wanderShip", "Wander", &m_ship },
	m_fastArriveShip{ sf::Vector2f{400, 400}, "fastArriveShip", "ArriveFast", &m_ship },
	m_exitGame{ false } //when true game will exit
{
	m_font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf");
	m_seekShip.setFont(m_font);
	m_wanderShip.setFont(m_font);
	m_fastArriveShip.setFont(m_font);
	m_seekShip.setBehaviour(AIStates::SEEK);
	m_wanderShip.setBehaviour(AIStates::WANDER);
	m_fastArriveShip.setBehaviour(AIStates::ARRIVE);
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		processKeys(newEvent);
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	m_ship.handleEvents(t_event);
	m_seekShip.handleEvents(t_event);
	m_wanderShip.handleEvents(t_event);
	m_fastArriveShip.handleEvents(t_event);
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	m_ship.update(t_deltaTime);
	m_seekShip.update(t_deltaTime);
	m_wanderShip.update(t_deltaTime);
	m_fastArriveShip.update(t_deltaTime);
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_ship.render(m_window);
	m_seekShip.render(m_window);
	m_wanderShip.render(m_window);
	m_fastArriveShip.render(m_window);
	m_window.display();
}