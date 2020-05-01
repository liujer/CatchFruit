#include "Galaxian.h"

/*
	Galaxian::Galaxian()

	Preconditions:
	- Window must be 800x800 or smaller for fruit to be hidden

	Postconditions:	
	- Points given is 15
	- Galaxian sprite is set using fruitTexture and position is set to the left or right of the window, rotation is set accordingly
	- Sprite is scaled by a factor of three
	- Sprite origin is set to center of sprite instead of top left corner
	- Clock is restarted
*/
Galaxian::Galaxian()
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

/*
	Galaxian::setSprite()

	Precondition:
	- "Galaxian.png" must exist in local folder

	Postconditions:
	- fruitTexture is loaded from "Galaxian.png"
	- fruitSprite texture is set using fruitTexture
*/
void Galaxian::setSprite()
{
	fruitTexture.loadFromFile("Galaxian.png");
	fruitSprite.setTexture(fruitTexture);
}

/*
	Galaxian::move()

	Postconditions:
	- If Galaxian is starting from left of screen, it will move 10 units to the right for
	rotationTime seconds, then rotating -5 degrees, completing a rotation of -270 degrees before moving down 10 units

	- If Galaxian is starting from right of screen, it will move 10 units to the left for
	rotationTime seconds, then rotating 5 degrees, completing a rotation of 270 degrees before moving down 10 units
*/
void Galaxian::move()
{
	if (startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < rotationTime)
		{
			fruitSprite.move(sf::Vector2f(10.f, 0));
		}
		else
		{
			if (rotationAngle <= -270) // After Galaxian completes rotation, will then move down
			{
				fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 10.f));
			}
			else {

				fruitSprite.setRotation(fruitSprite.getRotation() - 5);
				fruitSprite.move(sf::Vector2f(rotationRadius * std::cos(angleToRadians(rotationAngle)), 
					rotationRadius * std::sin(angleToRadians(rotationAngle))));
				rotationAngle -= 5;
			}

		}
	}
	else if (!startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < rotationTime)
		{
			fruitSprite.move(sf::Vector2f(-10.f, 0));
		}
		else
		{
			if (rotationAngle >= 450)
			{
				fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 10.f));
			}
			else {
				fruitSprite.setRotation(fruitSprite.getRotation() + 5);
				fruitSprite.move(sf::Vector2f(rotationRadius * std::cos(angleToRadians(rotationAngle)), 
					rotationRadius * std::sin(angleToRadians(rotationAngle))));

				rotationAngle += 5;
			}

		}
	}
}
