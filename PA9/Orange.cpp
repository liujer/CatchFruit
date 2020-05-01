#include "Orange.h"

/*
	Orange::Orange()

	Precondition: render window must be at least 800x800

	Postconditions:
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size

*/
Orange::Orange()
{
	int randPos = rand() % 450 + 150;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 5;
}

/*
	Orange::setSprite()

	Precondition:
	- "Orange.png" must exist in local folder

	Postconditions:
	- FruitTexture is set to "Orange.png" from local folder
	- FruitSprite texture is set to FruitTexture

*/
void Orange::setSprite()
{
	fruitTexture.loadFromFile("Orange.png");
	fruitSprite.setTexture(fruitTexture);

}

/*
	Orange::move()

	Postconditions:
	- fruitSprite will be translated 15 units down
*/
void Orange::move()
{


	fruitSprite.move(sf::Vector2f(0.f, 15.f));

}

