#include "Apple.h"

Apple::Apple(sf::Vector2f position)
{
	fruitSprite.setPosition(position);
	setSprite();
	fruitSprite.setScale(sf::Vector2f(3.f, 3.f));
	points = 10;
	clock.restart();
	int right = rand() % 2;
	if (right == 1)
	{
		curveRight = true;
	}
	else
	{
		curveRight = false;
	}
}

void Apple::setSprite()
{
	fruitTexture.loadFromFile("Apple.png");
	fruitSprite.setTexture(fruitTexture);

}

void Apple::move()
{
	if (clock.getElapsedTime().asSeconds() < 0.5)
	{
		fruitSprite.move(sf::Vector2f(0.f, 10.f));
	}
	else
	{
		if (curveRight)
		{
			fruitSprite.move(sf::Vector2f(3, 10.f));
		}
		else // curveLeft
		{
			fruitSprite.move(sf::Vector2f(-3, 10.f));
		}
	}
}

void Apple::restart()
{
	clock.restart();
	int right = rand() % 2;
	if (right == 1)
	{
		curveRight = true;
	}
	else
	{
		curveRight = false;
	}
}
