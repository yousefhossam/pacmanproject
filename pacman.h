#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;
using namespace sf;
class pacman
{
private:
	Texture texture;
	RectangleShape rect;
	char D;
	int row;
	int column;

public:
	pacman();
	pacman(int initialRow, int initialColumn);
	virtual void move(char direction, int arr[][19]);
	virtual void drawOnWindow(RenderWindow& window);
	void setD(char d);
	char getD();
	int getRow();
	int getColumn();

};