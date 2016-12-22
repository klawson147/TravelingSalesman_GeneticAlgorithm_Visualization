#include "EventHandler.h"


EventHandler::EventHandler()
{
}

EventHandler::EventHandler(sf::RenderWindow* rw)
{
	app_ = rw;
}

EventHandler::~EventHandler()
{
}

/* 
Process Events using RenderWindow::pollEvent
-2: No Events
-1: RenderWindow reference not set
 0: Closed window event
 1: (Key Released) Reset Simulation
 2: (Key Released) Pause Simulation
 3: (Key Released) Hide/Show Tours
 4: (Key Released) Hide/Show Best Tour
 5: Resized window event
 */
int EventHandler::ProcessEvents()
{
	if (app_ == NULL)
	{
		return -1;
	}
	else
	{
		while (app_->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				app_->close();
				return 0;
				break;

			case sf::Event::KeyReleased:
				switch(event.key.code)
				{
				case sf::Keyboard::R:
					return 1;
					break;
				case sf::Keyboard::Space:
					return 2;
					break;
				case sf::Keyboard::W:
					return 3;
					break;
				case sf::Keyboard::E:
					return 4;
					break;
				}
			
			case sf::Event::Resized:
				return 5;
				break;
			}
			
		}
	}

	return -2;
}