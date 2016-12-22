#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "City.h"

#pragma once
class Tour
{
private:
	static int maxSize_;
	static std::vector<City>* cityReference_;

	int fitness = 999999;

	sf::VertexArray vertices_;
	sf::Color color_;
	std::vector<int> orderStorage_;
	
	void completeTour();
	void generateRandomTour();
	
public:
	Tour();
	Tour(std::vector<int>);
	~Tour();

	// Set Static City Reference
	void static setCityReference(std::vector<City>*);

	// Max Size is Number of Indexes, thus number of cities is n - 1
	void setMaxSize(int);

	// Print the tour
	void printOrder();

	// Generate Vertices based on orderStorage_
	void fillLineVerts();

	// Replace tour with std::vector<int>, ensure size consistency
	void setTour(std::vector<int> newTour);

	// Push a CityID into vector
	void pushVisit(int, std::vector<City>*);

	// Return tour
	std::vector<int> getTour();

	// Return Line Vertices
	sf::VertexArray getVertices();

	// Return Max Size
	int getMaxSize();

	// Change Color Representation
	void setColor(sf::Color);

	// Set/Get Fitness
	void setFitness(int);
	int getFitness();

};

bool operator<( Tour &s1,  Tour &s2);