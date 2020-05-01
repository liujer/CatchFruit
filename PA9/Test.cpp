#include "Test.h"

/*
	Strawberry::Strawberry()

	Precondition: render window must be at least 800x800

	Postconditions:
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size
*/
TestBerry::TestBerry()
{
	int randPos = rand() % 25 + 350;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 1;
}

/*
	TestBerry::setSprite()

	Precondition:
	- "Strawberry.png" must exist in local folder

	Postconditions:
	- FruitTexture is set to "Stawberry.png" from local folder
	- FruitSprite texture is set to FruitTexture

*/
void TestBerry::setSprite()
{
	fruitTexture.loadFromFile("Strawberry.png");
	fruitSprite.setTexture(fruitTexture);

}

/*
	TestBerry::move()

	Postconditions:
	- Sprite will be translated downwards by 10 units
*/
void TestBerry::move()
{


	fruitSprite.move(sf::Vector2f(0.f, 10.f));

}

//tests the movement of the player in a basic game window
void test_game()
{
	srand(time(NULL)); // Generate a random seed 

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
				{
					playAgain = false;
					window.close();
				}

			}
			// Continue game


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

				window.clear();

				// Draw everything

				int i = 0; // Allows for second variable in for loop, used for accessing vector members
				for (auto it = existingFruits.begin(); it != existingFruits.end(); i++)
				{
					existingFruits[i]->move();
					if (existingFruits[i]->checkHitPlayer(player))
					{
						player.addPoints(existingFruits[i]->getPoints());
						delete existingFruits[i];
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						delete existingFruits[i];

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
					loseScreen.setTexture(window); // takes a screenshot of current screen
				}
				window.display();
		}
	}
	return;
}


//tests if two berries colliding with the player simultaneously both detect for points
void test_double_collision()
{
	srand(time(NULL)); // Generate a random seed 

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
				{
					playAgain = false;
					window.close();
				}

			}
			if (player.getLives() <= 0) // Lose screen is displayed
			{
				window.clear();
				if (loseScreen.playAgain(window))
				{
					break;
				}
				else if (loseScreen.exit(window))
				{
					playAgain = false;
					window.close();
				}
				else {
					loseScreen.draw(window);
					window.display();
				}

			}
			else { // Continue game


				// Generating fruits

				if (generateANewFruit) // Will add a fruit to the "queue"
				{
					if (systemClock.getElapsedTime().asSeconds() < 10) // First difficulty based on time elapsed in game
					{
						interval = randDouble(2500, 3000);

					}

					generateANewFruit = false; // Prevents fruit from being generated every frame
				}
				else if (generatingInterval.getElapsedTime().asMilliseconds() >= interval - 100 &&
					generatingInterval.getElapsedTime().asMilliseconds() < interval + 100) // account for inaccuracy
				{
					TestBerry* new_tb = new TestBerry;
					existingFruits.push_back(new_tb);
						
					TestBerry* new_rb = new TestBerry;
					existingFruits.push_back(new_rb);
					
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
						delete existingFruits[i];
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						delete existingFruits[i];

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
					loseScreen.setTexture(window); // takes a screenshot of current screen
				}
				window.display();

			}
		}
	}
	return;
}

void test_double_miss()
{
	srand(time(NULL)); // Generate a random seed 

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
				{
					playAgain = false;
					window.close();
				}

			}
			if (player.getLives() <= 0) // Lose screen is displayed
			{
				window.clear();
				if (loseScreen.playAgain(window))
				{
					break;
				}
				else if (loseScreen.exit(window))
				{
					playAgain = false;
					window.close();
				}
				else {
					loseScreen.draw(window);
					window.display();
				}

			}
			else { // Continue game

				//move player out of the way of fruits
				player.move(sf::Vector2f(10.f, 0.f));

				// Generating fruits

				if (generateANewFruit) // Will add a fruit to the "queue"
				{
					if (systemClock.getElapsedTime().asSeconds() < 10) // First difficulty based on time elapsed in game
					{
						interval = randDouble(2500, 3000);

					}

					generateANewFruit = false; // Prevents fruit from being generated every frame
				}
				else if (generatingInterval.getElapsedTime().asMilliseconds() >= interval - 100 &&
					generatingInterval.getElapsedTime().asMilliseconds() < interval + 100) // account for inaccuracy
				{
					TestBerry* new_tb = new TestBerry;
					existingFruits.push_back(new_tb);

					TestBerry* new_rb = new TestBerry;
					existingFruits.push_back(new_rb);

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
						delete existingFruits[i];
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						delete existingFruits[i];

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
					loseScreen.setTexture(window); // takes a screenshot of current screen
				}
				window.display();

			}
		}
	}
	return;
}

void test_game_over()
{
	srand(time(NULL)); // Generate a random seed 

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
				{
					playAgain = false;
					window.close();
				}

			}
			if (player.getLives() <= 0) // Lose screen is displayed
			{
				window.clear();
				if (loseScreen.playAgain(window))
				{
					break;
				}
				else if (loseScreen.exit(window))
				{
					playAgain = false;
					window.close();
				}
				else {
					loseScreen.draw(window);
					window.display();
				}

			}
			else { // Continue game

				//sets player to 0 lives on start up
				player.subtractLives(3);

				// Generating fruits

				if (generateANewFruit) // Will add a fruit to the "queue"
				{
					if (systemClock.getElapsedTime().asSeconds() < 10) // First difficulty based on time elapsed in game
					{
						interval = randDouble(2500, 3000);

					}

					generateANewFruit = false; // Prevents fruit from being generated every frame
				}
				else if (generatingInterval.getElapsedTime().asMilliseconds() >= interval - 100 &&
					generatingInterval.getElapsedTime().asMilliseconds() < interval + 100) // account for inaccuracy
				{
					TestBerry* new_tb = new TestBerry;
					existingFruits.push_back(new_tb);

					TestBerry* new_rb = new TestBerry;
					existingFruits.push_back(new_rb);

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
						delete existingFruits[i];
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						delete existingFruits[i];

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
					loseScreen.setTexture(window); // takes a screenshot of current screen
				}
				window.display();

			}
		}
	}
	return;
}

void test_difficulty()
{
	srand(time(NULL)); // Generate a random seed 

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
				{
					playAgain = false;
					window.close();
				}

			}
			 // Continue game


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
					case 7: // Add a Bell
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
						delete existingFruits[i];
						it = existingFruits.erase(it); // removes fruit from being used again
						i--;
					}
					else if (existingFruits[i]->checkHitGround(window))
					{
						player.subtractLives(1);
						delete existingFruits[i];

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
				window.display();
		}
	}
	return;
}