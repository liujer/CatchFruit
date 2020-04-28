#include "Key.h"

/*
	Key()
	Precondition: render window must be at least 800x800
	Postconditions:
	- Apple is now worth 10 points
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size
	- Apple will curve randomly to the left or right after 0.5 seconds
	- An internal clock is set for move()
*/
Key::Key()
{
	int randPos = rand() % 450 + 150;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 10;
	clock.restart();
}

/*
	Key::setSprite()

	Postconditions:
	- FruitTexture is set to "Apple.png" from local folder
	- FruitSprite texture is set to FruitTexture

*/
void Key::setSprite()
{
	fruitTexture.loadFromFile("Key.png");
	fruitSprite.setTexture(fruitTexture);

}

/*
	Key::move()

	Postconditions:
	- Using internal clock, sprite will move downwards 10 units if less
	than 0.5 seconds have passed, otherwise will move in either right
	or left direction 3 units depending on boolean variable curveRight
*/
void Key::move()
{


	fruitSprite.move(sf::Vector2f(0.f, 25.f));

}

