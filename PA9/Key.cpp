#include "Key.h"

/*
	Key::Key()
	Precondition: render window must be at least 800x800
	Postconditions:
	- Key is now worth 20 points
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size

*/
Key::Key()
{
	int randPos = rand() % 450 + 150;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 20;
	clock.restart();
}

/*
	Key::setSprite()

	Precondition:
	- "Key.png" must exist in local folder

	Postconditions:
	- FruitTexture is set to "Key.png" from local folder
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
	- Key Sprite will be translated downwards 25 units
*/
void Key::move()
{


	fruitSprite.move(sf::Vector2f(0.f, 25.f));

}

