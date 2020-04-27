#ifndef FRUIT_H
#define FRUIT_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <ctime>
class Fruit
{
protected:
	sf::Texture fruitTexture;
	sf::Sprite fruitSprite;
	int points;

public:
	int getPoints();
	virtual void setSprite();
	virtual void move();
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);
	bool checkHitGround(sf::RenderWindow& window);
	bool checkHitPlayer(Player &player);
};

#endif