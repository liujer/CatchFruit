#include "Bananna.h"

/*
	Bananna()

	Preconditions:
	- Window must be 800x800 or smaller for fruit to be hidden
	Postconditions:
	- Galaxian sprite is set using fruitTexture and position is set to the left or right of the window, rotation is set accordingly
	- Sprite is scaled by a factor of three
	- Sprite origin is set to center of sprite instead of top left corner
	- Clock is restarted
*/
Bananna::Bananna()
{
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	int randNo = rand() % 2;
	int height = height = rand() % 200 + 200;
	points = 15;
	if (randNo == 1)
	{
		startFromLeft = true;
		fruitSprite.setPosition(sf::Vector2f(-150.f, height));
		fruitSprite.setRotation(90);
		rotationAngle = 0;
	}
	else
	{
		startFromLeft = false;
		fruitSprite.setPosition(sf::Vector2f(900.f, height));
		fruitSprite.setRotation(-90);
		rotationAngle = 180;


	}
	rotationTime = randDouble(0, 1) + 1;
	rotationRadius = 10;
	fruitSprite.setOrigin(sf::Vector2f(fruitSprite.getLocalBounds().width / 2, fruitSprite.getLocalBounds().height / 2));
	clock.restart();
}

void Bananna::setSprite()
{
	fruitTexture.loadFromFile("Bananna.png");
	fruitSprite.setTexture(fruitTexture);
}

/*
	Bananna::move()

	Postconditions:
	- If Bananna is starting from left of screen, it will move right rotationTime seconds, then move down

	- If Bananna is starting from right of screen, it will move left rotationTime seconds, then move down
*/
void Bananna::move()
{
	if (startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < rotationTime)
		{
			fruitSprite.move(sf::Vector2f(15.f, 0));
		}
		else
		{
			if (rotationAngle <= 0) // Bannana moves down
			{
				fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 15.f));
			}

		}
	}
	else if (!startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < rotationTime)
		{
			fruitSprite.move(sf::Vector2f(-15.f, 0));
		}
		else
		{
			if (rotationAngle >= 180)
			{
				fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 15.f));
			}

		}
	}
}