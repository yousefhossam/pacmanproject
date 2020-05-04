#include "maze.h"
maze::maze(int rowx, int columnx, string imageName)
{
	shape.setSize(Vector2f(35, 35));
	texture.loadFromFile(imageName);
	shape.setTexture(&texture);
}
void maze::drawOnWindow(RenderWindow& window)
{
	window.draw(shape);
}
int maze::getRow()
{
	return row;
}
int maze::getColumn()
{
	return column;
}