#include "Strawberry.h"

/*
	Strawberry::Strawberry()

	Precondition: render window must be at least 800x800

	Postconditions:
	- FruitSprite is set to a random position on the top of window
	- FruitSprite texture is set using FruitTexture
	- FruitSprite is scaled to be 3x original size
*/
Strawberry::Strawberry()
{
	int randPos = rand() % 450 + 150;
	fruitSprite.setPosition(sf::Vector2f(randPos, 0));
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 5;
}

/*
	Strawberry::setSprite()

	Precondition:
	- "Strawberry.png" must exist in local folder

	Postconditions:
	- FruitTexture is set to "Stawberry.png" from local folder
	- FruitSprite texture is set to FruitTexture

*/
void Strawberry::setSprite()
{
	fruitTexture.loadFromFile("Strawberry.png");
	fruitSprite.setTexture(fruitTexture);

}

/*
	Strawberry::move()

	Postconditions:
	- Sprite will be translated downwards by 10 units
*/
void Strawberry::move()
{

	
	fruitSprite.move(sf::Vector2f(0.f, 10.f));
	
}

