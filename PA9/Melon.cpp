#include "Melon.h"

/*
	Melon::Melon()

	Precondition: render window must be at least 800x800

	Postconditions:
	- Points given set to 10
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size
*/
Melon::Melon()
{
	int randPos = rand() % 450 + 150;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 10;
}

/*
	Melon::setSprite()

	Precondition:
	- "Melon.png" must exist in local folder

	Postconditions:
	- FruitTexture is set to "Melon.png" from local folder
	- FruitSprite texture is set to FruitTexture

*/
void Melon::setSprite()
{
	fruitTexture.loadFromFile("Melon.png");
	fruitSprite.setTexture(fruitTexture);

}

/*
	Melon::move()

	Postconditions:
	- Melon will be translated 3 units downwards
*/
void Melon::move()
{
	fruitSprite.move(sf::Vector2f(0.f, 3.f));
}

