#ifndef FRUIT_H
#define FRUIT_H
#include <SFML/Graphics.hpp>
#include "Player.h"
class Fruit
{
protected:
	sf::Texture fruitTexture;
	sf::Sprite fruitSprite;
	int points;

public:
	Fruit();
	int getPoints();
	virtual void setSprite() = 0;
	virtual void move() = 0;
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);
	bool checkHitGround(sf::RenderWindow& window);
	bool checkHitPlayer(Player &player);
};

#endif