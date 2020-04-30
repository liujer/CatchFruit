#include "LoseScreen.h"

LoseScreen::LoseScreen()
{
	textFont.loadFromFile("DS-DIGI.ttf");
	
	youLost.setFont(textFont);
	youLost.setCharacterSize(100);
	youLost.setString("YOU LOST");
	youLost.setPosition(230, 150);
	youLost.setFillColor(sf::Color::White);

	playAgainText.setFont(textFont);
	playAgainText.setCharacterSize(50);
	playAgainText.setString("PLAY AGAIN");
	playAgainText.setPosition(290, 300);
	playAgainText.setFillColor(sf::Color::White);
	playAgainText.setOutlineColor(sf::Color::White);

	exitText.setFont(textFont);
	exitText.setCharacterSize(50);
	exitText.setString("EXIT");
	exitText.setPosition(360, 370);
	exitText.setFillColor(sf::Color::White);
	exitText.setOutlineColor(sf::Color::White);

}

void LoseScreen::setTexture(sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	screen.setTexture(texture);

}

bool LoseScreen::playAgain(sf::RenderWindow& window)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);

	if (playAgainText.getGlobalBounds().contains(localPosition.x, localPosition.y) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	else if (playAgainText.getGlobalBounds().contains(localPosition.x, localPosition.y))
	{
		playAgainText.setOutlineThickness(2);
		return false;
	}
	else
	{
		playAgainText.setOutlineThickness(0);
		return false;
	}
}

bool LoseScreen::exit(sf::RenderWindow& window)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	
	if (exitText.getGlobalBounds().contains(localPosition.x, localPosition.y) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	else if(exitText.getGlobalBounds().contains(localPosition.x, localPosition.y))
	{
		exitText.setOutlineThickness(2);
		return false;
	}
	else
	{
		exitText.setOutlineThickness(0);
		return false;
	}
}

void LoseScreen::draw(sf::RenderWindow& window)
{
	window.draw(screen);
	window.draw(youLost);
	window.draw(playAgainText);
	window.draw(exitText);

	
}
