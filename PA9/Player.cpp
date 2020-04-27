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
	bottom.move(speed.x, speed.y);
	leftSide.move(speed.x, speed.y);
	rightSide.move(speed.x, speed.y);

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(bottom);
	window.draw(leftSide);
	window.draw(rightSide);
}

int Player::getLeftBound()
{
	return bottom.getPosition().x;
}

int Player::getRightBound()
{
	return bottom.getPosition().x + bottom.getGlobalBounds().width;
}
