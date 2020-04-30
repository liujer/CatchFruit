#include <SFML/Graphics.hpp>
#include <iostream>
#include "utilityFunction.h"
#include "LoseScreen.h"
#include "Player.h"
#include "TopBar.h"
#include "Fruit.h"
#include "Apple.h"
#include "Galaxian.h"
#include "Strawberry.h"
#include "Melon.h"
#include "Key.h"
#include "Orange.h"
#include "Bananna.h"
#include "Bell.h"
#include <vector>
int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 800), "Catch Fruit", sf::Style::Default);
	window.setFramerateLimit(30);
	bool playAgain = true;

	while (playAgain)
	{
		Player player(window);
		std::vector <Fruit*> existingFruits;

		sf::Clock systemClock;
		TopBar bar;
		sf::Clock generatingInterval;
		int interval = -1;
		bool generateANewFruit = true;
		int numberOfFruits = 8;
		sf::Event event;
		LoseScreen loseScreen;


		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

			}
			if (player.getLives() <= 0)
			{
				window.clear();
				if (loseScreen.playAgain(window))
				{
					break;
				}
				else if(loseScreen.exit(window))
				{
					playAgain = false;
					window.close();
				}
				else {
					loseScreen.draw(window);
					window.display();
				}
				
			}
			else {


				// Movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (player.getRightWindowBound() < window.getSize().x) // checks out of bound to right
					{

						player.move(sf::Vector2f(10.f, 0.f));
					}


				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					if (player.getLeftWindowBound() > 0) // checks out of bound to left
					{
						player.move(sf::Vector2f(-10.f, 0.f));
					}
				}

				// Generating fruits

				if (generateANewFruit) // Will add a fruit to the "queue"
				{
					if (systemClock.getElapsedTime().asSeconds() < 10) // First difficulty based on time elapsed in game
					{
						interval = randDouble(2500, 3000);

					}
					else if (systemClock.getElapsedTime().asSeconds() > 30 && systemClock.getElapsedTime().asSeconds() < 60) // Second difficulty
					{
						interval = randDouble(2000, 2500);

					}
					else if (systemClock.getElapsedTime().asSeconds() > 60 && systemClock.getElapsedTime().asSeconds() < 90) // Third difficulty
					{
						interval = randDouble(1500, 2000);

					}
					else if (systemClock.getElapsedTime().asSeconds() > 90 && systemClock.getElapsedTime().asSeconds() < 120) // Fourth difficulty
					{
						interval = randDouble(1000, 1500);

					}
					else if (systemClock.getElapsedTime().asSeconds() > 120) // Last difficulty
					{
						interval = randDouble(100, 1000);

					}


					generateANewFruit = false; // Prevents fruit from being generated every frame
				}
				else if (generatingInterval.getElapsedTime().asMilliseconds() >= interval - 100 &&
					generatingInterval.getElapsedTime().asMilliseconds() < interval + 100) // account for inaccuracy
				{
					
					// Add a random fruit to the fruits on the screen
					int randNo = rand() % numberOfFruits;
					switch (randNo)
					{
					case 0: // Add an apple
					{
						Apple* new_apple = new Apple;
						existingFruits.push_back(new_apple);
						break;
					}
					case 1: // Add a Galaxian
					{
						Galaxian* new_galaxian = new Galaxian;
						existingFruits.push_back(new_galaxian);
						break;
					}
					case 2: // Add a Strawberry
					{
						Strawberry* new_sb = new Strawberry;
						existingFruits.push_back(new_sb);
						break;
					}
					case 3: // Add a Melon
					{
						Melon* new_melon = new Melon;
						existingFruits.push_back(new_melon);
						break;
					}
					case 4: // Add a Key
					{
						Key* new_key = new Key;
						existingFruits.push_back(new_key);
						break;
					}
					case 5: // Add an Orange
					{
						Orange* new_orange = new Orange;
						existingFruits.push_back(new_orange);
						break;
					}
					case 6: // Add a Bananna
					{
						Bananna* new_nana = new Bananna;
						existingFruits.push_back(new_nana);
						break;
					}
					case 7: // Add an Bell
					{
						Bell* new_bell = new Bell;
						existingFruits.push_back(new_bell);
						break;
					}

					}
					generatingInterval.restart();
					generateANewFruit = true;
				}
				window.clear();

				// Draw everything

				int i = 0; // Allows for second variable in for loop, used for accessing vector members
				for (auto it = existingFruits.begin(); it != existingFruits.end(); i++)
				{
					existingFruits[i]->move();
					if (existingFruits[i]->checkHitPlayer(player))
					{
						player.addPoints(existingFruits[i]->getPoints());
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else // Draw fruit to screen and add to iterator
					{
						existingFruits[i]->draw(window);
						++it;
					}
				}

				player.draw(window);
				bar.draw(player, window);
				if (player.getLives() <= 0)
				{
					loseScreen.setTexture(window);
				}
				window.display();

			}
		}
	}
	return 0;
}
