#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

#pragma once
class TextDisplayHandler
{
private:

	sf::RenderWindow* rw_;
	std::vector<sf::Text> textElements;
	sf::Font font;

public:
	TextDisplayHandler();
	TextDisplayHandler(sf::RenderWindow*);
	~TextDisplayHandler();

	void addText(int, sf::Vector2f, std::string);
	void drawText();
	void editText(int, std::string);

};

