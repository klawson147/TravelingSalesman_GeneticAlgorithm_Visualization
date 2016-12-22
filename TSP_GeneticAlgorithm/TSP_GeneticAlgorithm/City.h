#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#endif // !SFML_GRAPHICS

#pragma once
class City
{
private:

	static int numb;
	
	sf::CircleShape cityshape;
	sf::Vector2f position;

	sf::Font font;
	sf::Text text;

public:
	static void ResetID();

	City();
	City(sf::Vector2f);
	~City();

	// Return CircleShape Representation of City
	sf::CircleShape getShape();
	sf::FloatRect getBounds();
	sf::Text * getText();
	sf::Vector2f getPosition();

	std::string getID();

	void setPosition(sf::Vector2f);
	void Draw(sf::RenderWindow*);





};

