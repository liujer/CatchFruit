#ifndef TOPBAR_H
#define TOPBAR_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>
#include <iostream>
class TopBar
{
private:
	sf::Texture heartTexture;
	sf::Sprite heartSprite;
	sf::Font pointsFont;
	sf::Text points;
	sf::Text elaspedTime;
	sf::Clock clock;
	int minutes;
public:
	TopBar();
	bool minutePassed();
	int getSeconds();
	void draw(Player &player, sf::RenderWindow & window);

};

#endif 
