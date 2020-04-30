#ifndef LOSESCREEN_H
#define LOSESCREEN_H
#include <SFML/Graphics.hpp>

class LoseScreen
{
private:
	sf::Texture texture;
	sf::Sprite screen;
	sf::Font textFont;
	sf::Text youLost;
public:
	LoseScreen();
	void setTexture(sf::RenderWindow &window);
	void draw(sf::RenderWindow& window);
};


#endif