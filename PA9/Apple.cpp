#include "Apple.h"

Apple::Apple(sf::Vector2f position)
{
	fruitSprite.setPosition(position);
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
}

void Apple::setSprite()
{
	fruitTexture.loadFromFile("Apple.png");
	fruitSprite.setTexture(fruitTexture);

}

void Apple::move()
{
	fruitSprite.move(sf::Vector2f(0.f, 7.f));
}