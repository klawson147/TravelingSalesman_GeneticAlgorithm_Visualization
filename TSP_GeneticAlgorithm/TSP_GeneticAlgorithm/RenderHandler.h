#include <SFML\Graphics.hpp>

#include "CityHandler.h"
#include "TourHandler.h"
#include "TextDisplayHandler.h"

#include <vector>
#pragma once
class RenderHandler
{
private:
	sf::RenderWindow* rw_;
	CityHandler* city_;
	TourHandler* tour_;
	TextDisplayHandler* text_;

public:
	RenderHandler();
	~RenderHandler();

	void setElement(sf::RenderWindow*);
	void setElement(CityHandler*);
	void setElement(TourHandler*);
	void setElement(TextDisplayHandler*);
	void Draw();
};

