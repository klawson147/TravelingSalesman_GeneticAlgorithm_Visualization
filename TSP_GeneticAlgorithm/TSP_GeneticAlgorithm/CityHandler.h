#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "City.h"
#include "Matrix.h"

#pragma once
class CityHandler
{
private:
	static sf::RenderWindow* app_;

	std::vector<City> cities_;

	int nCities_;
	int minimumDistance_;
	int minimumDistanceEdge_;

	float computeDistance(sf::Vector2f a, sf::Vector2f b);

	Matrix cityMatrix;

	bool isMinDistanceAway(sf::Vector2f a, sf::Vector2f b);
	bool isMinDistanceAwayFromPosition(sf::Vector2f a, sf::Vector2f b);
	bool isMinDistanceAwayEdge(sf::Vector2f a);

	sf::Vector2f generateRandomPosition();

	std::vector<sf::Vector2f> getValidPositions();

public:
	CityHandler();
	CityHandler(sf::RenderWindow* app, int n, int minDist, int minDistEdge);

	~CityHandler();

	void generateCities();
	void drawCities();

	Matrix getCitieDistancesMatrix();

	std::vector<City>* getRefCities();

	void freeCities();
	

};

