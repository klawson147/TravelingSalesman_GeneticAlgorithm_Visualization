#include <SFML/Graphics.hpp>
#pragma once
class EventHandler
{
private:
	sf::RenderWindow* app_;
	sf::Event event;

public:
	EventHandler();
	EventHandler(sf::RenderWindow*);
	~EventHandler();
	int ProcessEvents();
};

