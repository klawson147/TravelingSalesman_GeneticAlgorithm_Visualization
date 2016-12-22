#include "City.h"

int City::numb = 1;



City::City()
{
}

City::City(sf::Vector2f p)
{
	// Set Origin to Center
	cityshape.setOrigin(2.5f, 2.5f);

	// Assign Position
	position = p;

	// Set Position
	cityshape.setPosition(position);

	// Set Radius
	cityshape.setRadius(5);

	// Set Color
	cityshape.setFillColor(sf::Color(255, 255, 255));

	// Define Font
	if (!font.loadFromFile("font/Anke.ttf"))
	{

	}
	text.setString(std::to_string(numb));
	text.setColor(sf::Color::Red);
	text.setPosition(position.x + 12, position.y - 7);
	text.setCharacterSize(18);

	// Increment Numb
	numb++;
}



City::~City()
{
	
}

sf::CircleShape City::getShape()
{
	return cityshape;
}

sf::Text * City::getText()
{
	return &text;
}

void City::setPosition(sf::Vector2f p)
{
	position = p;
}

void City::Draw(sf::RenderWindow* app)
{
	text.setFont(font);
	app->draw(cityshape);
	app->draw(text);
}


std::string City::getID()
{
	return this->text.getString();
}

sf::Vector2f City::getPosition()
{
	return position;
}

void City::ResetID()
{
	City::numb = 1;
}

