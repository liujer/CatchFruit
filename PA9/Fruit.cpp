#include "Fruit.h"

Fruit::Fruit()
{
	points = 0;
}

int Fruit::getPoints()
{
	return points;
}

void Fruit::draw(sf::RenderWindow& window)
{
	window.draw(fruitSprite);
}

void Fruit::setPosition(sf::Vector2f position)
{
	fruitSprite.setPosition(position);
}

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
