#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

class Player
{
private: 
	sf::Texture playerTexture;
	sf::RectangleShape bottom;
	sf::RectangleShape leftSide;
	sf::RectangleShape rightSide;

public:
	Player(sf::RenderWindow &window);
	void move(sf::Vector2f);
	void draw(sf::RenderWindow &window);
	int getLeftWindowBound();
	int getRightWindowBound();
	sf::FloatRect getBottomRectBound();
	sf::FloatRect getLeftRectBound();
	sf::FloatRect getRightRectBound();
	
};

#endif 


