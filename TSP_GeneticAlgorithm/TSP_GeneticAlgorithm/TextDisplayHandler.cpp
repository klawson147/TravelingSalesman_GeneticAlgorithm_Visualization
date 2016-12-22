#include "TextDisplayHandler.h"


TextDisplayHandler::TextDisplayHandler()
{
	

}

TextDisplayHandler::TextDisplayHandler(sf::RenderWindow* r)
{
	if (!font.loadFromFile("font/Anke.ttf"))
	{

	}
	rw_ = r;
	textElements.resize(10);
}

TextDisplayHandler::~TextDisplayHandler()
{
}

void TextDisplayHandler::addText(int key, sf::Vector2f position, std::string newText)
{
	sf::Text text;

	text.setPosition(position);
	text.setString(newText);
	text.setCharacterSize(18);
	text.setColor(sf::Color::White);

	textElements.at(key) = text;
}

void TextDisplayHandler::drawText()
{
	std::vector<sf::Text>::iterator it;

	for (it = textElements.begin(); it != textElements.end(); it++)
	{
		it->setFont(font);
		rw_->draw(*it);
	}
	
}

void TextDisplayHandler::editText(int key, std::string newText)
{
	textElements.at(key).setString(newText);
}