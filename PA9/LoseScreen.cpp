#include "LoseScreen.h"

LoseScreen::LoseScreen()
{
	textFont.loadFromFile("DS-DIGI.ttf");
	
	youLost.setFont(textFont);
	youLost.setCharacterSize(100);
	youLost.setString("YOU LOST");
	youLost.setPosition(220, 300);
	youLost.setFillColor(sf::Color::White);
}

void LoseScreen::setTexture(sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	screen.setTexture(texture);

}

void LoseScreen::draw(sf::RenderWindow& window)
{
	window.draw(screen);
	window.draw(youLost);

	
}
