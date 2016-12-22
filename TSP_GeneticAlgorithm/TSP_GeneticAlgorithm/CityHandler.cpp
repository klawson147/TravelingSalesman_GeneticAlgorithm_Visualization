#include "CityHandler.h"


sf::RenderWindow* CityHandler::app_ = NULL;

CityHandler::CityHandler()
{
	srand((unsigned int)(time(NULL)));
}

CityHandler::CityHandler(sf::RenderWindow* app, int n, int minDist, int minDistEdge)
{
	srand((unsigned int)(time(NULL)));
	nCities_ = n;
	minimumDistanceEdge_ = minDistEdge;
	minimumDistance_ = minDist;
	app_ = app;
}

CityHandler::~CityHandler()
{

}

void CityHandler::generateCities() 
{

	cities_.clear();
	City::ResetID();

	
	

	std::vector<sf::Vector2f> positions = getValidPositions();
	
	for (int i = 0; i < nCities_; i++)
	{
		City newCity(positions.at(i));
		cities_.push_back(newCity);
	}
}

// return the absolute value of the distance between 2 cities
float CityHandler::computeDistance(sf::Vector2f a, sf::Vector2f b)
{
	float x1 = a.x;
	float x2 = b.x;

	float y1 = a.y;
	float y2 = b.y;

	float d = std::fabsf(std::sqrtf(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)));
	return d;
}


bool CityHandler::isMinDistanceAwayFromPosition(sf::Vector2f a, sf::Vector2f b)
{
	if (computeDistance(a, b) > minimumDistance_)
	{
		return true;
	}
	return false;
} 

bool CityHandler::isMinDistanceAwayEdge(sf::Vector2f a)
{
	float x1 = a.x;
	float y1 = a.y;

	int x2 = app_->getSize().x;
	int y2 = app_->getSize().y;

	if (x1 - minimumDistanceEdge_ <= 0)
		return false;
	if (x1 + 300 >= x2)
		return false;
	if (y1 - minimumDistanceEdge_ <= 0)
		return false;
	if (y1 + minimumDistanceEdge_ >= y2)
		return false;

	return true;
}

bool CityHandler::isMinDistanceAway(sf::Vector2f a, sf::Vector2f b)
{
	if (!isMinDistanceAwayFromPosition(a, b))
		return false;
	if (!isMinDistanceAwayEdge(a))
		return false;

	return true;
}

std::vector<sf::Vector2f> CityHandler::getValidPositions()
{
	std::vector<sf::Vector2f> positions;

	sf::Vector2f pos = generateRandomPosition();

	// Ensure first position is min dist away from edge
	while (!isMinDistanceAwayEdge(pos))
	{
		pos = generateRandomPosition();
	}
	
	for (int i = 0; i < nCities_; i++)
	{
		// Ensure position is valid
		for (int j = 0; j < (int)positions.size(); j++)
		{
			while (!isMinDistanceAway(pos, positions.at(j)))
			{
				pos = generateRandomPosition();
				j = 0;
			}
		}

		// add new valid position to vector
		positions.push_back(pos);

		// Generate a random position
		pos = generateRandomPosition();
	}

	return positions;
}

sf::Vector2f CityHandler::generateRandomPosition()
{

	sf::Vector2f p;

	p.x = (float)(rand() % app_->getSize().x + 1);
	p.y = (float)(rand() % app_->getSize().y + 1);

	return p;
}

void CityHandler::drawCities()
{
	for (int i = 0; i < nCities_; i++)
	{
		cities_.at(i).Draw(app_);
	}
}


Matrix CityHandler::getCitieDistancesMatrix()
{
	Matrix matrix(nCities_);

	for (int i = 0; i < nCities_; i++)
	{
		for (int j = 0; j < nCities_; j++)
		{
			if (i == j)
			{
				matrix.setElement(i, j, NULL);
			}
			else
			{
				matrix.setElement(i, j, (short)computeDistance(cities_.at(i).getPosition(), cities_.at(j).getPosition()));
			}
		}
	}

	cityMatrix = matrix;

	return matrix;
}

std::vector<City>* CityHandler::getRefCities()
{
	return &cities_;
}

void CityHandler::freeCities()
{

}