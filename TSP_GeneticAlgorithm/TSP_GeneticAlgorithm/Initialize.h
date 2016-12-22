#include <vector>
#include "City.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SCREENDISTANCEMINIMUM 300
#define CITYDISTANCEMINIMUM 100

#pragma once
class Initialize
{
public:
	Initialize();
	~Initialize();

	void generateCities(std::vector<City>*, sf::RenderWindow*, int);
	bool distanceGreaterThan(int, int, int, int, int);
	float computeDistance(int, int, int, int);
	sf::Vector2f generateRandomPosition(sf::RenderWindow*);
	bool isValidDistanceFromB(int d, sf::Vector2f a, std::vector<City>* b);
	bool isAwayFromEdge(int d, sf::Vector2f a, sf::RenderWindow* app);
};

