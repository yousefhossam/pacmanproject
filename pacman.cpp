#include "pacman.h"
pacman::pacman()
{
	row = 0;
	column = 0;
	D = 'a';
}
pacman::pacman(int initialRow, int initialColumn)
{
	texture.loadFromFile("pacman.png");
	row = initialRow;
	column = initialColumn;
	rect.setSize(Vector2f(35, 35));
	rect.setPosition(50 + 35 * initialColumn, 50 + 35 * initialRow);
	Sprite sprite(texture, sf::IntRect(0, 0, 35, 35));
	rect.setTexture(&texture);
}
void pacman::move(char direction, int arr[][19])
{
	if (direction == 'U' || direction == 'u')
	{
		if (arr[row - 1][column] != -1)
		{
			row--;
			rect.move(0, -35);
		}
	}
	else if (direction == 'D' || direction == 'd')
	{
		if (arr[row + 1][column] != -1)
		{
			row++;
			rect.move(0, 35);
		}
	}
	else if (direction == 'R' || direction == 'r')
	{
		if (arr[row][column + 1] != -1)
		{
			column++;
			rect.move(35, 0);
		}
	}
	else if (direction == 'L' || direction == 'l')
	{
		if (arr[row][column - 1] != -1)
		{
			column--;
			rect.move(-35, 0);
		}
	}
}
void pacman::drawOnWindow(RenderWindow& window)
{
	window.draw(rect);
}

char pacman::getD()
{
	return D;
}
int pacman::getRow()
{
	return row;
}
int pacman::getColumn()
{
	return column;
}
void pacman::setD(char d)
{
	D = d;
}