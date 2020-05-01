#include "Bell.h"

/*
	Bell::Bell()

	Preconditions:
	- Window must be 800x800 or smaller for fruit to be hidden

	Postconditions:
	- Points given is 15
	- Bell sprite is set using fruitTexture and position is set to the left or right of the window, rotation is set accordingly
	- Sprite is scaled by a factor of three
	- Sprite origin is set to center of sprite instead of top left corner
	- Clock is restarted
*/
Bell::Bell()
{
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	int randNo = rand() % 2;
	int height = height = rand() % 200 + 100;
	points = 15;
	if (randNo == 1)
	{
		startFromLeft = true;
		fruitSprite.setPosition(sf::Vector2f(-150.f, height));
		rotationAngle = 270;
	}
	else
	{
		startFromLeft = false;
		fruitSprite.setPosition(sf::Vector2f(900.f, height));
		rotationAngle = 270;


	}
	rotationTime = randDouble(0, 1) + 1;
	rotationRadius = 10;
	fruitSprite.setOrigin(sf::Vector2f(fruitSprite.getLocalBounds().width / 2, fruitSprite.getLocalBounds().height / 2));
	clock.restart();
}


/*
	Bell::setSprite()

	Precondition:
	- "Bell.png" must exist in local folder


	Postconditions:
	- fruitTexture is loaded from "Bell.png"
	- fruitSprite texture is set using fruitTexture
*/
void Bell::setSprite()
{
	fruitTexture.loadFromFile("Bell.png");
	fruitSprite.setTexture(fruitTexture);
}

/*
	Bell::move()

	Postconditions:
	- If Bell is starting from left of screen, it will move right for a division of rotation times
	 seconds, then move up till rotationtime, then arc till it goes down

	- If Bell is starting from right of screen, it will move left for a division of rotation times
	 seconds, then move up till rotationtime, then arc till it goes down
*/
void Bell::move()
{

	if (startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < (rotationTime / 1.2))
		{
			fruitSprite.move(sf::Vector2f(10.f, 0));
		}
		else
		{
			if (rotationAngle <= 270 && clock.getElapsedTime().asSeconds() < rotationTime) // After Bell goes out Bell will move up starting the Arc
			{
				//fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, -10.f));

			}
			else if (rotationAngle >= 450) // After Bell completes arc, it goes down
			{
				//fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 10.f));
			}
			else {

				//fruitSprite.setRotation(fruitSprite.getRotation() + 5);
				fruitSprite.move(sf::Vector2f(rotationRadius * std::cos(angleToRadians(rotationAngle)),
					rotationRadius * std::sin(angleToRadians(rotationAngle))));
				rotationAngle += 5;
			}

		}
	}
	else if (!startFromLeft)
	{
		if (clock.getElapsedTime().asSeconds() < (rotationTime / 1.2))
		{
			fruitSprite.move(sf::Vector2f(-10.f, 0));
		}
		else
		{
			if (rotationAngle >= 270 && clock.getElapsedTime().asSeconds() < rotationTime)
			{
				//fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, -10.f));
			}
			else if (rotationAngle <= 90) // After Bell completes arc, it goes down
			{
				//fruitSprite.setPosition(floor(fruitSprite.getPosition().x), floor(fruitSprite.getPosition().y));
				fruitSprite.move(sf::Vector2f(0, 10.f));
			}
			else {
				//fruitSprite.setRotation(fruitSprite.getRotation() - 5);
				fruitSprite.move(sf::Vector2f(rotationRadius * std::cos(angleToRadians(rotationAngle)),
					rotationRadius * std::sin(angleToRadians(rotationAngle))));

				rotationAngle -= 5;
			}

		}
	}
}