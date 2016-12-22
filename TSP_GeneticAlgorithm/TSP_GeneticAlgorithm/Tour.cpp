#include "Tour.h"

int Tour::maxSize_ = NULL;
std::vector<City>* Tour::cityReference_ = NULL;

Tour::Tour()
{
	srand(time(NULL));
	color_ = sf::Color::White;
}

Tour::Tour(std::vector<int> v)
{
	orderStorage_ = v;

	setColor(sf::Color::White);
	fillLineVerts();
	

	srand(time(NULL));
	
}


Tour::~Tour()
{

}

void Tour::setCityReference(std::vector<City>* c)
{

	cityReference_ = c;
}

void Tour::setMaxSize(int size)
{
	maxSize_ = size;
	orderStorage_.reserve(maxSize_);

	vertices_ = sf::VertexArray(sf::LinesStrip, 0);
}

void Tour::completeTour()
{
	orderStorage_.at(maxSize_) = orderStorage_.at(0);
}

void Tour::printOrder()
{
	for (int i = 0; i < orderStorage_.size(); i++)
	{
		std::cout << orderStorage_.at(i) << std::endl;
	}
}

void Tour::generateRandomTour()
{
	for (int i = 0; i < maxSize_; i++)
	{
		orderStorage_.at(i) = rand() % (maxSize_ - 1) + 1;
	}
}

void Tour::setTour(std::vector<int> newTour)
{
	orderStorage_ = newTour;
	maxSize_ = orderStorage_.size();
}

// Return Vector of City #'s to Visit
std::vector<int> Tour::getTour()
{
	return orderStorage_;
}

void Tour::pushVisit(int v, std::vector<City>* c)
{
	float offset = (rand() % 5 + 1);

	orderStorage_.push_back(v);

	int x = c->at(v).getPosition().x;
	int y = c->at(v).getPosition().y;

	sf::Vertex vertex;
	vertex.position.x = x + offset;
	vertex.position.y = y + offset;

	vertices_.append(vertex);
}


sf::VertexArray Tour::getVertices()
{
	return vertices_;
}

int Tour::getMaxSize()
{
	return maxSize_;
}

void Tour::setColor(sf::Color color)
{	
	color_ = color;

	for (int i = 0; i < vertices_.getVertexCount(); i++)
	{
		vertices_[i].color = color_;
	}
}

void Tour::fillLineVerts()
{
	vertices_.clear();
	vertices_.setPrimitiveType(sf::LinesStrip);
	float offset;

	sf::Vertex vertex;
	sf::Vector2f pos;

	int x, y;

	for (int i = 0; i < orderStorage_.size(); i++)
	{
		offset = rand() % 5 + 1;
		pos = cityReference_->at(orderStorage_.at(i)).getPosition();

		pos.x += offset;
		pos.y += offset;

		vertex.position = pos;
		vertex.color = color_;
		
		vertices_.append(vertex);
	}
}

void Tour::setFitness(int n)
{
	fitness = n;
}

int Tour::getFitness()
{
	return fitness;
}

bool operator<(Tour &s1, Tour &s2){
	if (s1.getFitness() < s2.getFitness())
	{
		return true;
	}
	else
	{
		return false;
	}
		
}