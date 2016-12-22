#include "Tour.h"
#include <vector>
#include <algorithm>
#include "City.h"
#pragma once
class TourHandler
{
private:
	static sf::RenderWindow* app_;
	static std::vector<City> * cityVectRef_;

	int numbTours_;

	Tour bestTour;
	std::vector<Tour> tourStorage;
	
	// 0 - Standard Tour
	// 1 - Best Tour;
	std::vector<bool> drawFlags;

	

public:
	TourHandler();
	TourHandler(sf::RenderWindow*, int, int, std::vector<City>*);
	~TourHandler();

	// Sets number of tours to be made
	void setNumbTours(int);
	// Get tours at index n
	std::vector<int> getTour_(int);
	// Create tours 
	void createTours(int, int);
	// Set Reference to Window for Drawing
	void setRenderWindowReference(sf::RenderWindow*);
	// Draw Tours
	void drawTours();
	//Set City Ref
	void SetCityRef(std::vector<City>*);
	// Change Color
	void setColor(int, sf::Color);
	// Fill Tour Color
	void fillColor(sf::Color);
	// Get Tour Reference
	std::vector<Tour>* getTourReference();
	// Reset Fitness of Best Tour
	void resetBestTour();
	// Get Best Tour Reference
	Tour* getBestTourReference();
	// Switch Draw Flag (index)
	void switchDrawFlag(int);
	// Assign std::vector<Tour> 
	void setTours(std::vector<Tour>);
};

