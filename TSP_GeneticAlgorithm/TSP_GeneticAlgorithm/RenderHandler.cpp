#include "RenderHandler.h"


RenderHandler::RenderHandler()
{
}


RenderHandler::~RenderHandler()
{
}

void RenderHandler::Draw()
{
	rw_->clear();
	tour_->drawTours();
	text_->drawText();
	city_->drawCities();
	
	rw_->display();
}

void RenderHandler::setElement(sf::RenderWindow* r)
{
	rw_ = r;
}

void RenderHandler::setElement(CityHandler* c)
{
	city_ = c;
}

void RenderHandler::setElement(TourHandler* t)
{
	tour_ = t;
}

void RenderHandler::setElement(TextDisplayHandler* t)
{
	text_ = t;
}