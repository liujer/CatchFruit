#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game", sf::Style::Default);
	window.setSize(sf::Vector2u(800, 800));
	window.setFramerateLimit(30);
	sf::Texture texture;
	texture.loadFromFile("BasketTexture.jpg");

	sf::RectangleShape bottom;
	bottom.setSize(sf::Vector2f(200.f, 15.f));
	bottom.setTexture(&texture);

	sf::RectangleShape leftSide;
	leftSide.setSize(sf::Vector2f(15.f, 40.f));
	leftSide.setTexture(&texture);

	sf::RectangleShape rightSide;
	rightSide.setSize(sf::Vector2f(15.f, 40.f));
	rightSide.setTexture(&texture);

	bottom.setPosition((window.getSize().x - bottom.getSize().x) / 2,
		window.getSize().y - bottom.getSize().y - 50); // Places rectangle bottom center of screen

	leftSide.setPosition(sf::Vector2f(bottom.getPosition().x , bottom.getPosition().y - 40));
	rightSide.setPosition(sf::Vector2f(bottom.getPosition().x + bottom.getGlobalBounds().width - 15, bottom.getPosition().y - 40));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();			
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (bottom.getPosition().x + bottom.getGlobalBounds().width < window.getSize().x) // checks out of bound to right
			{
				bottom.move(10.f, 0.f);
				leftSide.move(10.f, 0.f);
				rightSide.move(10.f, 0.f);
			}

			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (bottom.getPosition().x > 0) // checks out of bound to left
			{
				bottom.move(-10.f, 0.f);
				leftSide.move(-10.f, 0.f);
				rightSide.move(-10.f, 0.f);

			}
		}
		window.clear();
		window.draw(bottom);
		window.draw(leftSide);
		window.draw(rightSide);
		window.display();
	}

	return 0;
}
