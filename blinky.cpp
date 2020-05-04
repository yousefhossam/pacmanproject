#include "blinky.h"

blinky::blinky()
{

}

blinky::blinky(int initialRow, int initialColumn)
{
	texture.loadFromFile("blinky.png");
	row = initialRow;
	column = initialColumn;
	shape.setSize(Vector2f(35, 35));
	shape.setPosition(50 + 35 * initialColumn, 50 + 35 * initialRow);
	Sprite sprite(texture, sf::IntRect(0, 0, 35, 35));
	shape.setTexture(&texture);
}

void blinky::drawOnWindow(RenderWindow& window)
{
	window.draw(shape);
}

void blinky::move(char direction, int arr[][19], pacman x)
{
	if (row > x.getRow())
	{
		if (!(arr[row - 1][column] == -1))
		{
			row--;
			shape.move(0, -35);
		}
		else if ((column > x.getColumn()) && (!(arr[row][column - 1] == -1)))
		{
			column--;
			shape.move(-35, 0);
		}
		else if ((column < x.getColumn()) && (!(arr[row][column + 1] == -1)))
		{
			column++;
			shape.move(35, 0);
		}
		else if (arr[row+1][column] != -1)
		{
			row++;
			shape.move(0, 35);
		}
		
	}

	else if (row < x.getRow())
	{
		if (!(arr[row + 1][column] == -1))
		{
			row++;
			shape.move(0, 35);
		}
		else if ((column > x.getColumn()) && (!(arr[row][column - 1] == -1)))
		{
			column--;
			shape.move(-35, 0);
		}
		else if ((column < x.getColumn()) && (!(arr[row][column + 1] == -1)))
		{
			column++;
			shape.move(35, 0);
		}
		else if (arr[row-1][column] != -1)
		{
			row--;
			shape.move(0, -35);
		}

	}
	
	else if (column > x.getColumn())
	{
		if (!(arr[row][column-1] == -1))
		{
			column--;
			shape.move(-35, 0);
		}
		else if ((row < x.getRow()) && (!(arr[row-1][column] == -1)))
		{
			row--;
			shape.move(0, -35);
		}
		else if ((row < x.getRow()) && (!(arr[row+1][column] == -1)))
		{
			row++;
			shape.move(0, 35);
		}
		else if (arr[row][column + 1] != -1)
		{
			column++;
			shape.move(35, 0);
		}

	}

	else if (column < x.getColumn())
	{
		if (!(arr[row][column + 1] == -1))
		{
			column++;
			//arr[row][column - 1] = -1;
			shape.move(35, 0);
		}
		else if ((row < x.getRow()) && (!(arr[row - 1][column] == -1)))
		{
			row--;
			//arr[row+1][column] = -1;
			shape.move(0, -35);
		}
		else if ((row < x.getRow()) && (!(arr[row + 1][column] == -1)))
		{
			row++;
			//arr[row-1][column] = -1;
			shape.move(0, 35);
		}
		else if (arr[row][column-1]!=-1)
		{
			column--;
			//arr[row][column + 1] = -1;
			shape.move(-35, 0);
		}

	}
	
}

