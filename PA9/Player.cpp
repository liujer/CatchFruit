#include "Player.h"

Player::Player(sf::RenderWindow &window)
{
	playerTexture.loadFromFile("BasketTexture.jpg");

	bottom.setSize(sf::Vector2f(200.f, 15.f));
	bottom.setTexture(&playerTexture);

	leftSide.setSize(sf::Vector2f(15.f, 40.f));
	leftSide.setTexture(&playerTexture);

	rightSide.setSize(sf::Vector2f(15.f, 40.f));
	rightSide.setTexture(&playerTexture);


	bottom.setPosition((window.getSize().x - bottom.getSize().x) / 2,
		window.getSize().y - bottom.getSize().y - 50); // Places rectangle bottom center of screen

	leftSide.setPosition(sf::Vector2f(bottom.getPosition().x, bottom.getPosition().y - 40));
	rightSide.setPosition(sf::Vector2f(bottom.getPosition().x + bottom.getGlobalBounds().width - 15, bottom.getPosition().y - 40));


}


void Player::move(sf::Vector2f speed)
{
	bottom.move(speed);
	leftSide.move(speed);
	rightSide.move(speed);

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(bottom);
	window.draw(leftSide);
	window.draw(rightSide);
}


int Player::getLeftWindowBound()
{
	return bottom.getPosition().x;
}

int Player::getRightWindowBound()
{
	return bottom.getPosition().x + bottom.getSize().x;
}

sf::FloatRect Player::getBottomRectBound()
{
	return bottom.getGlobalBounds();
}

sf::FloatRect Player::getLeftRectBound()
{
	return leftSide.getGlobalBounds();
}

sf::FloatRect Player::getRightRectBound()
{
	return rightSide.getGlobalBounds();
}
