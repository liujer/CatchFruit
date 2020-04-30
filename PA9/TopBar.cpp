#include "TopBar.h"

TopBar::TopBar()
{

	heartTexture.loadFromFile("heart.png");
	heartSprite.setTexture(heartTexture);
	heartSprite.setScale(sf::Vector2f(0.5, 0.5));

	pointsFont.loadFromFile("DS-DIGI.ttf");
	points.setFont(pointsFont);
	points.setFillColor(sf::Color::White);
	points.setCharacterSize(50);

	
	elaspedTime.setFont(pointsFont);
	elaspedTime.setFillColor(sf::Color::White);
	elaspedTime.setCharacterSize(50);
	elaspedTime.setPosition(sf::Vector2f(370, 50));

	clock.restart();
	minutes = 0;
}

/*
	minutePassed()
	Returns true if clock has elapsed 60 seconds or more, false if not
*/
bool TopBar::minutePassed()
{
	if (clock.getElapsedTime().asSeconds() >= 60)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	getSeconds()
	Returns the seconds of clock as an int, flooring int if necessary
*/
int TopBar::getSeconds()
{
	return floor(clock.getElapsedTime().asSeconds());
}

void TopBar::draw(Player& player, sf::RenderWindow& window)
{
	// Draw points
	std::string pointsStr = std::to_string(player.getPoints());
	points.setString(pointsStr);
	points.setOrigin(points.getGlobalBounds().width, 0);
	points.setPosition(window.getSize().x - 50, 50);
	window.draw(points);

	// Draw hearts
	int offset = 50;
	for (int i = 0; i < player.getLives(); i++)
	{
		heartSprite.setPosition(sf::Vector2f(offset, 50));
		window.draw(heartSprite);
		offset += 60;
	}

	// Draw time elapsed;
	std::string time;
	if (minutePassed())
	{
		minutes++;
		clock.restart();
	}
	if(minutes == 0 && getSeconds() < 10)
	{
		time = "0:0" + std::to_string(getSeconds());
	}
	else if(getSeconds() < 10)
	{
		time = std::to_string(minutes) + ":0" + std::to_string(getSeconds());
	}
	else
	{
		time = std::to_string(minutes) + ":" + std::to_string(getSeconds());
	}
	elaspedTime.setString(time);
	window.draw(elaspedTime);
	


	
}
