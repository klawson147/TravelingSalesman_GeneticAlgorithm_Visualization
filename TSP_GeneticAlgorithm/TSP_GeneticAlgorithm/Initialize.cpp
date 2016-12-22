#include "Initialize.h"


Initialize::Initialize()
{
	srand(time(0));
}


Initialize::~Initialize()
{

}

// generate N cities
// cities are guaranteed to be D distance apart
void Initialize::generateCities(std::vector<City>* cityVector, sf::RenderWindow* app, int n)
{
	sf::Vector2f* position = new sf::Vector2f();
	sf::Vector2f currentCity;

	// New City Object that will be pushed to vector
	City* newCity = NULL;

	// Loop Through and Generate N Cities
	for (int i = 0; i < n; i++)
	{
		// Generate a Random Position
		*position = generateRandomPosition(app);

		// If position is valid
		// Create a new city with valid position
		// Push city into vector
		if (isValidDistanceFromB(CITYDISTANCEMINIMUM, *position, cityVector) && isAwayFromEdge(SCREENDISTANCEMINIMUM, *position, app))
		{
			newCity = new City(*position);
			cityVector->push_back(*newCity);
		}
		else
		{
			i--;
		}
	}
}

// If A is invalid against an element in Vector B, return false
bool Initialize::isValidDistanceFromB(int d, sf::Vector2f a, std::vector<City>* b)
{
	for (int i = 0; i < b->size(); i++)
	{
		if (!distanceGreaterThan(d, a.x, a.y, b->at(i).getPosition().x, b->at(i).getPosition().y))
		{
			return false;
		}
	}

	return true;
}

// Return True if at a minimum D distance away from edge of screen
bool Initialize::isAwayFromEdge(int d, sf::Vector2f a, sf::RenderWindow* app)
{
	int width = app->getSize().x;
	int height = app->getSize().y;

	if (a.y - d <= 0)
	{
		return false;
	}
	if (a.x - d <= 0)
	{
		return false;
	}
	if (a.y + d >= height)
	{
		return false;
	}
	if (a.x + d >= width)
	{
		return false;
	}

	return true;
}


// Return True if Distance Greater Than D
bool Initialize::distanceGreaterThan(int d, int a_x, int a_y, int b_x, int b_y)
{
	if (computeDistance(a_x, a_y, b_x, b_y) <= d)
	{
		return false;
	}
	return true;
}

// Distance Formula for Computing Distance on a 2D plane
float Initialize::computeDistance(int a_x, int a_y, int b_x, int b_y)
{
	int distance = std::sqrt(std::pow(b_x - a_x, 2) + std::pow(b_y - a_y, 2));
	if (distance < 0)
	{
		distance *= -1;
	}
	
	return distance;
}

// Generate a Random Position up to Screen Width and Height
sf::Vector2f Initialize::generateRandomPosition(sf::RenderWindow*app)
{
	sf::Vector2f p;
	p.x = rand() % app->getSize().x + 1;
	p.y = rand() % app->getSize().y + 1;

	return p;
}