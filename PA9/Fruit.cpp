#include "Fruit.h"


int Fruit::getPoints()
{
	return points;
}


void Fruit::setSprite()
{
	fruitTexture.loadFromFile("missingTexture.jpg");
	fruitSprite.setTexture(fruitTexture);
}

void Fruit::move()
{
	fruitSprite.move(0, 0);
}

void Fruit::draw(sf::RenderWindow& window)
{
	window.draw(fruitSprite);
}

void Fruit::setPosition(sf::Vector2f position)
{
	fruitSprite.setPosition(position);
}


/*
	checkHitGround() returns true if fruitSprite touches bottom of window, otherwise false
*/
bool Fruit::checkHitGround(sf::RenderWindow &window)
{
	for (int i = 0; i < window.getSize().x; i++)
	{
		if (fruitSprite.getGlobalBounds().contains(sf::Vector2f(i, window.getSize().y)))
		{
			return true;
		}
	}
	return false;
}


/*
	checkHitPlayer() returns true if fruitSprite touches any part of player, otherwise false
*/
bool Fruit::checkHitPlayer(Player& player)
{
	if (fruitSprite.getGlobalBounds().intersects(player.getBottomRectBound())) // if fruit hits bottom of basket
	{
		return true;
	}
	else if (fruitSprite.getGlobalBounds().intersects(player.getLeftRectBound())) // if fruit hits left side of basket
	{
		return true;
	}
	else if (fruitSprite.getGlobalBounds().intersects(player.getRightRectBound())) // if fruit hits right side of basket
	{
		return true;
	}
	else
	{
		return false;
	}
}
