#include "TourHandler.h"

sf::RenderWindow* TourHandler::app_ = NULL;
std::vector<City>* TourHandler::cityVectRef_ = NULL;

TourHandler::TourHandler()
{
}

TourHandler::TourHandler(sf::RenderWindow* app, int nTours, int nCities, std::vector<City>* city)
{
	app_ = app;
	numbTours_ = nTours;

	if (cityVectRef_ == NULL)
	{
		cityVectRef_ = city;
	}

	bestTour.setFitness(99999);
	bestTour.setColor(sf::Color::Green);
	createTours(numbTours_, nCities);
	Tour::setCityReference(city);
	
	drawFlags.push_back(true);
	drawFlags.push_back(true);
}

TourHandler::~TourHandler()
{

}

void TourHandler::setNumbTours(int n)
{
	numbTours_ = n;
}

void TourHandler::resetBestTour()
{
	bestTour.setFitness(99999);
}

std::vector<int> TourHandler::getTour_(int index)
{
	std::vector<int> tour;
	tour = tourStorage.at(index).getTour();
	return tour;
}

void TourHandler::createTours(int nTours, int nCities)
{
	tourStorage.clear();

	std::vector<int> cityIDs;

	

	// Fill Vector with all possible city ID's
	for (int i = 0; i < nCities; i++)
	{
		cityIDs.push_back(i);
	}

	// Shuffle Vector containing city ID's
	for (int i = 0; i < nTours; i++)
	{
		Tour temp;
		temp.setMaxSize(nCities + 1);

		std::random_shuffle(cityIDs.begin(), cityIDs.end());

		// Insert City ID's randomly into Tour temp
		for (int i = 0; i < nCities; i++)
		{
			temp.pushVisit(cityIDs.at(i), cityVectRef_);
		}

		// Set last visit to starting CityID
		temp.pushVisit(cityIDs.at(0), cityVectRef_);

		// Push Tour into Tour Storge Vector
		tourStorage.push_back(temp);
	}
}

void TourHandler::setRenderWindowReference(sf::RenderWindow* app)
{
	app_ = app;
}

void TourHandler::drawTours()
{

	if (drawFlags.at(0) == true)
	{
		for (std::vector<Tour>::iterator it = tourStorage.begin(); it != tourStorage.end(); it++)
		{
			app_->draw(it->getVertices());
		}
	}
	
	
	if (drawFlags.at(1) == true)
	{
		app_->draw(bestTour.getVertices());
	}
	
}

void TourHandler::fillColor(sf::Color c)
{
	for (int i = 0; i < tourStorage.size(); i++)
	{
		tourStorage[i].setColor(c);
	}
}

void TourHandler::SetCityRef(std::vector<City>* cityRef)
{
	cityVectRef_ = cityRef;
}

/*
std::vector<std::vector<int>> TourHandler::getTours()
{
	std::vector<std::vector<int>> toursToReturn;
	std::vector<Tour>::iterator it;

	for (it = tourStorage.begin(); it != tourStorage.end(); it++)
	{
		toursToReturn.push_back(it->getTour());
	}

	return toursToReturn;
}
*/

std::vector<Tour>* TourHandler::getTourReference()
{
	return &tourStorage;
}


void TourHandler::setColor(int index, sf::Color color)
{
	tourStorage.at(index).setColor(color);
}

Tour* TourHandler::getBestTourReference()
{
	return &bestTour;
}

void TourHandler::switchDrawFlag(int index)
{
	if (drawFlags.at(index) == true)
	{
		drawFlags.at(index) = false;
	}
	else
	{
		drawFlags.at(index) = true;
	}
}

void TourHandler::setTours(std::vector<Tour> t)
{
	tourStorage = t;
}