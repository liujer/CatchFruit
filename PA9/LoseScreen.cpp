#include "LoseScreen.h"

/*
	LoseScreen::LoseScreen()

	Preconditions:
	- Render window must be 800x800

	Postconditions: 
	- Sets the text, font, size, color, and position of three sf::Text objects
*/
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

/*
	LoseScreen::setTexture()

	Preconditions:
	- window size of the window in the function parameter must match 
	the window used to draw the screen

	Postconditions:
	- Takes a "creenshot" of the window and uses it as the 
	texture for the screen sprite
*/
void LoseScreen::setTexture(sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	screen.setTexture(texture);

}

/*
	LoseScreen::playAgain()

	Postconditions:
	- Highlights the  playAgain text if mouse is hovered over the text
	- Returns true if text is clicked, false if not  
*/
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


/*
	LoseScreen::exit()

	Postconditions:
	- Highlights the exit text if mouse is hovered over the text
	- Returns true if text is clicked, false if not
*/
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


/*
	LoseScreen::draw()

	Preconditions:
	- window size of the window in the function parameter must match
	the window used to set texture of screen
*/
void LoseScreen::draw(sf::RenderWindow& window)
{
	window.draw(screen);
	window.draw(youLost);
	window.draw(playAgainText);
	window.draw(exitText);

	
}
