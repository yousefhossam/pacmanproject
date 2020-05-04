#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <fstream>
#include "pacman.h"
#include "ghosts.h"
#include "maze.h"
#include "menu.h"
#include "blinky.h"
#include "pellets.h"
using namespace std;
using namespace sf;
const int rows = 22, cols = 19;

enum tilestate { empty, rock, pallet };
struct tile {
	RectangleShape r;
	//bool walkable;	//1 means can stand on it
	//bool cp;		//1 means has a pallet
	tilestate s;
};
int main()
{
	
	menu mainmenu;
		RenderWindow startwindow{ sf::VideoMode(1400,800), "Main Menu" };
		Texture maintexture;
		maintexture.loadFromFile("menu.png");
		Sprite s(maintexture);
		Event windowEvent;
		while (startwindow.isOpen())
		{
			while (startwindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == Event::Closed)
					startwindow.close();

				if (windowEvent.type == Event::KeyPressed)
				{
					if (windowEvent.key.code == Keyboard::X)
					{
						startwindow.close();
					}
				}
			}
			startwindow.draw(s);
			startwindow.display();
		}

	if (windowEvent.key.code == Keyboard::X)
	{
		RenderWindow window;
		window.create(VideoMode(800, 800), "Pacman");

		Font pointsfont;
		pointsfont.loadFromFile("font.ttf");
		Text pointstext;
		pointstext.setFont(pointsfont);
		int points = 0;
		pointstext.setString(to_string(points));
		pointstext.setFillColor(Color::Black);
		pointstext.setOutlineColor(Color::White);
		pointstext.setOutlineThickness(2);
		pointstext.setPosition(130, 0);

		Text scoretext;
		scoretext.setFont(pointsfont);
		scoretext.setString("Score: ");
		scoretext.setFillColor(Color::Black);
		scoretext.setOutlineColor(Color::White);
		scoretext.setOutlineThickness(2);

		int arr[rows][cols];
		ifstream inputFile;
		inputFile.open("Board.txt");
		if (inputFile.is_open())
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (!inputFile.eof())
						inputFile >> arr[i][j];
		}
		inputFile.close();
		Texture bricksTexture, pelletsTexture, background;
		bricksTexture.loadFromFile("Blue.png");
		pelletsTexture.loadFromFile("pellet.png");
		background.loadFromFile("grass.jpg");
		RectangleShape board[rows][cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				board[i][j].setPosition(50 + 35 * j, 50 + 35 * i);
				board[i][j].setSize(Vector2f(35, 35));
				if (arr[i][j] == -1)
				{
					board[i][j].setTexture(&bricksTexture);
					board[i][j].setFillColor(Color::Cyan);
				}
				else
				{
					board[i][j].setTexture(&pelletsTexture);
				}
			}
		Event e;
		pacman x(1, 1);
		blinky blink(8,9);
		pellets food;
		
		sf::Clock timer;
		timer.restart();
		RectangleShape r1, r2;
		if (r1.getGlobalBounds().intersects(r2.getGlobalBounds()))
		{
			r1.setPosition(0, 0);

		}
		while (window.isOpen())
		{
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed)
					window.close();
				else if (e.type == Event::KeyPressed)
				{
					switch (e.key.code)
					{
					case Keyboard::Up:
						x.setD('U');
						break;
					case Keyboard::Down:
						x.setD('D');
						break;
					case Keyboard::Right:
						x.setD('R');
						break;
					case Keyboard::Left:
						x.setD('L');
						break;
					}
				}
			}
			if (timer.getElapsedTime().asMilliseconds() >= 350)
			{
				x.move(x.getD(), arr);
				blink.move(x.getD(), arr, x);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
					{
						if ((x.getRow() == i) && (x.getColumn() == j))
						{
							if (board[i][j].getFillColor() != Color::Black)
							{
								points += 50;
								pointstext.setString(to_string(points));
							}
							board[i][j].setTexture(&background);
							board[i][j].setFillColor(Color::Black);
						}
					}
				timer.restart();
			}
			window.clear();
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					window.draw(board[i][j]);
			x.drawOnWindow(window);
			blink.drawOnWindow(window);
			food.drawOnWindow(window);
			window.draw(pointstext);
			window.draw(scoretext);
			window.display();
		}
	}
}