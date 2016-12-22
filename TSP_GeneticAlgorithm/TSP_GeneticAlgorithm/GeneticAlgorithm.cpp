#include "GeneticAlgorithm.h"



GeneticAlgorithm::GeneticAlgorithm()
{
	gen = 0;
}


GeneticAlgorithm::~GeneticAlgorithm()
{
}


void GeneticAlgorithm::setMatrix(Matrix m)
{
	matrix = m;
}


void GeneticAlgorithm::generateTours()
{
	computeFitness();
	crossover();
	mutation();
	computeFitness();
	checkForBetterTour();
}




void GeneticAlgorithm::crossover()
{
	// Numb Tours
	int nTours = tours_->size();

	// New Population 
	std::vector<Tour> newTourPop;

	// Current Population
	std::vector<Tour> currentTourPop = *tours_;

	// Sort Tours by Fitness
	currentTourPop = sortTours(currentTourPop);

	// Tour Sum
	int tourSum = 0;
	

	// If Elitism 
	if (rand() % ELITISM_RATE == 0)
	{
		// Add Best Tour to New Population
		newTourPop.push_back(currentTourPop[0]);
		currentTourPop.erase(currentTourPop.begin());
	}

	int randResult = rand() % 100 + 1;

	std::reverse(currentTourPop.begin(), currentTourPop.end());

	
	while (newTourPop.size() < nTours)
	{
		newTourPop.push_back(getChild(getParents(currentTourPop)));
	}
	

	*tours_ = newTourPop;
	

}

// Return 2 Parents
std::vector<Tour> GeneticAlgorithm::getParents(std::vector<Tour> population)
{
	std::vector<Tour> parents;
	float tourSum = 0;
	int random;
	int adjustedRank;

	for (int i = population.size(); i != 0; i--)
	{
		tourSum += i;
	}

	while (parents.size() < 2)
	{
		for (int i = 0; i < population.size(); i++)
		{
			random = rand() % 100 + 1;
			adjustedRank = ((i + 1) / tourSum) * 100;
			if (random < adjustedRank)
			{
				tourSum -= population.size();
				parents.push_back(population.at(i));
				population.erase(population.begin() + i);
				
				break;
			}
		}
	}
		
	return parents;


}
// Return New Offspring
Tour GeneticAlgorithm::getChild(std::vector<Tour> parents)
{
	std::vector<int> parentA = parents[0].getTour();
	std::vector<int> parentB = parents[1].getTour();

	int max = parentA.size() - 1;

	std::vector<int> child(max, -1);

	int rand1 = rand() % max;
	int rand2 = rand() % max;

	// rand1 will be larger
	if (rand2 > rand1)
	{
		std::swap(rand1, rand2);
	}

	for (int i = rand2; i <= rand1; i++)
	{
		child[i] = parentA[i];
	}

	for (int i = 0; i < max; i++)
	{
		if (child[i] == -1)
		{
			for (int t = 0; t < max; t++)
			{
				if (!vectorContains(child, parentB[t]))
				{
					child[i] = parentB[t];
					break;
				}
			}
		}
	}

	child.push_back(child.at(0));
	
	Tour childTour;
	childTour.setColor(sf::Color::White);
	childTour.setTour(child);
	childTour.fillLineVerts();

	return childTour;
}


bool GeneticAlgorithm::vectorContains(std::vector<int> v, int i)
{
	std::vector<int>::iterator it = v.begin();

	for (it; it != v.end(); it++)
	{
		if (*it == i)
		{
			return true;
		}
	}
	return false;
}

std::vector<Tour> GeneticAlgorithm::sortTours(std::vector<Tour> t)
{
	std::sort(t.begin(), t.end());
	return t;
}



// Assign two iterators to traverse the tours and compute fitness
void GeneticAlgorithm::computeFitness()
{
	std::vector<Tour>::iterator Tourit;
	std::vector<int>::iterator Intit;
	std::vector<int> tour;

	int tempFit = 0;

	for (Tourit = tours_->begin(); Tourit != tours_->end(); Tourit++)
	{
		tour = Tourit->getTour();

		for (Intit = tour.begin(); Intit != (tour.end() - 1); Intit++)
		{
			tempFit += matrix.getElement(*Intit, *(Intit + 1));
		}

		Tourit->setFitness(tempFit);
		tempFit = 0;
		
	}
	
}

void GeneticAlgorithm::checkForBetterTour()
{
	std::vector<Tour>::iterator it;

	for (it = tours_->begin(); it != tours_->end(); it++)
	{
		//it->fillLineVerts();
		if (it->getFitness() < bestTour_->getFitness())
		{
			std::cout << "Better Tour Found\n";
			*bestTour_ = *it;
			bestTour_->setColor(sf::Color::Red);
		}
	}
}

void GeneticAlgorithm::mutation()
{
	std::vector<Tour>::iterator it;

	int pos1;
	int pos2;
	int temp;

	for (it = tours_->begin(); it != tours_->end(); it++)
	{
		// If Mutation Occurs For This Tour
		if ((rand() % MUTATION_RATE) == 0)
		{
			//std::cout << "Mutation\n";
			// Get Random Positions to Swap
			pos1 = rand() % (it->getTour().size() - 1);
			pos2 = rand() % (it->getTour().size() - 1);

			// Swap Mutation
			// Temp Vector of Locations (int)
			std::vector<int> t1 = it->getTour();
			temp = t1.at(pos1);
			t1.at(pos1) = t1.at(pos2);
			t1.at(pos2) = temp;
			t1.at(t1.size() - 1) = t1.at(0);

			// Set New Tour
			it->setTour(t1);
			
			it->fillLineVerts();
		}	
	}
}



void GeneticAlgorithm::setRenderReference(sf::RenderWindow* r)
{
	rw_ = r;
}

void GeneticAlgorithm::setTourReference(std::vector<Tour>* t)
{
	tours_ = t;
	computeFitness();
}


void GeneticAlgorithm::setBestTourReference(Tour* t)
{
	bestTour_ = t;
}