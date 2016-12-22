#include <vector>
#include <time.h>
#include "Matrix.h"
#include "Tour.h"
#include <iostream>

// % = 1/RATE
#define MUTATION_RATE 5
#define ELITISM_RATE 1

#pragma once
class GeneticAlgorithm
{

	int gen;

	// Window Reference
	sf::RenderWindow* rw_;

	// Tour Reference
	std::vector<Tour>* tours_;

	// Best Tour Reference 
	Tour* bestTour_;

	// Matrix of Distances Between Cities
	Matrix matrix; 

	void computeFitness();
	void crossover();
	void mutation();
	void fillLineVerts();
	std::vector<Tour> sortTours(std::vector<Tour>);
	void checkForBetterTour();

	bool vectorContains(std::vector<int>, int);

	std::vector<Tour> getParents(std::vector<Tour>);
	Tour getChild(std::vector<Tour>);

public:
	GeneticAlgorithm();
	~GeneticAlgorithm();
	
	void setRenderReference(sf::RenderWindow*);
	void setTourReference(std::vector<Tour>*);
	void setBestTourReference(Tour*);

	void drawBestTour();
	void setMatrix(Matrix);
	void generateTours();
	std::vector<std::vector<int>> getTours();
	
};

