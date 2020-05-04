#include "pellets.h"
#include <SFML\Graphics\RenderWindow.hpp>

pellets::pellets()
{

}

pellets::pellets(int initialColumn, int initialRow)
{
	texture.loadFromFile("pellet.png");
	circle.setSize(Vector2f(35, 35));
	circle.setPosition(50 + 35 * initialColumn, 50 + 35 * initialRow);
	Sprite sprite(texture, sf::IntRect(0, 0, 35, 35));
	circle.setTexture(&texture);

}

void pellets::drawOnWindow(RenderWindow& window)
{
	window.draw(circle);
}
