#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game", sf::Style::Default);
	window.setSize(sf::Vector2u(800, 800));
	window.setFramerateLimit(30);
	Player player(window);

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
			if (player.getRightBound() < window.getSize().x) // checks out of bound to right
			{

				player.move(sf::Vector2f(10.f, 0.f));
			}

			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (player.getLeftBound() > 0) // checks out of bound to left
			{
				player.move(sf::Vector2f(-10.f, 0.f));
			}
		}
		window.clear();
		player.draw(window);
		window.display();
	}

	return 0;
}
