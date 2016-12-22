#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "CityHandler.h"
#include "TourHandler.h"
#include "RenderHandler.h"
#include "GeneticAlgorithm.h"
#include "TextDisplayHandler.h"
#include "EventHandler.h"
#include "Tour.h"
#include <vector>
#include <thread>

#define WIDTH 1920
#define HEIGHT 1080
#define NUMBCITIES 30
#define NUMBTOURS 100

int main()
{	
	bool paused = false;

	int generations = 0;

	// Anti-Alias
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	// Create Window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Traveling Salesman Problem");
	window.setFramerateLimit(30);

	// Create & Initialize Cities
	CityHandler cityHandler(&window, NUMBCITIES, 75, 30);
	cityHandler.generateCities();

	// Create & Initialize Tours
	TourHandler tourHandler(&window, NUMBTOURS, NUMBCITIES, cityHandler.getRefCities());

	// Event Handler Object
	EventHandler eventHandler(&window);

	// Handler for Displaying Relevent User Information
	TextDisplayHandler textDisplayHandler(&window);
	
	// Handler for Drawing
	RenderHandler renderHandler;

	// Set Element References
	renderHandler.setElement(&window);
	renderHandler.setElement(&cityHandler);
	renderHandler.setElement(&tourHandler);
	renderHandler.setElement(&textDisplayHandler);
	
	
	textDisplayHandler.addText(0, sf::Vector2f(1680, 35), "Running");
	textDisplayHandler.addText(1, sf::Vector2f(1680, 70), "Cities: " + std::to_string(NUMBCITIES));
	textDisplayHandler.addText(2, sf::Vector2f(1680, 105), "Tours: " + std::to_string(NUMBTOURS));
	textDisplayHandler.addText(3, sf::Vector2f(1680, 140), "Generations: " + std::to_string(generations));
	textDisplayHandler.addText(4, sf::Vector2f(1680, 175), "Controls:\n'Space' - Pause\n'W' - Hide General Pop\n'E' - Hide Best Tour\n'R' - Reset\n");
	

	GeneticAlgorithm geneticAlgorithm;
	geneticAlgorithm.setMatrix(cityHandler.getCitieDistancesMatrix());
	geneticAlgorithm.setBestTourReference(tourHandler.getBestTourReference());
	geneticAlgorithm.setTourReference(tourHandler.getTourReference());
	geneticAlgorithm.generateTours();
	geneticAlgorithm.setRenderReference(&window);
	
	
	// Main Program Loop
	while (window.isOpen())
	{
		
		// Process Events
		switch (eventHandler.ProcessEvents())
		{
			// Reset Cities
			case 1:
				if (!paused)
				{
					system("CLS");
					cityHandler.generateCities();
					tourHandler.SetCityRef(cityHandler.getRefCities());
					tourHandler.createTours(NUMBTOURS, NUMBCITIES);
					tourHandler.resetBestTour();

					geneticAlgorithm.setMatrix(cityHandler.getCitieDistancesMatrix());
					geneticAlgorithm.setTourReference(tourHandler.getTourReference());

					generations = 0;
					textDisplayHandler.editText(3, "Generations: " + std::to_string(generations));
					geneticAlgorithm.generateTours();

				}
				break;

			// (Un)Pause Simulation
			case 2: 
				if (paused == true)
				{
					paused = false;
					textDisplayHandler.editText(0, "Running");
				}
				else
				{
					paused = true;
					textDisplayHandler.editText(0, "Paused");
				}
				renderHandler.Draw();
				break;

			case 3:
				tourHandler.switchDrawFlag(0);
				break;

			case 4:
				tourHandler.switchDrawFlag(1);
				break;

			// Redraw window on resize
			case 5:
				renderHandler.Draw();
				
				break;
		}
			
		if (!paused)
		{
			generations++;
			textDisplayHandler.editText(3, "Generations: " + std::to_string(generations));
			geneticAlgorithm.setTourReference(tourHandler.getTourReference());
			geneticAlgorithm.generateTours();
		}
		
			
			renderHandler.Draw();
			
	}
	return 0;
}