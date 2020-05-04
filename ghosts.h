#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "pacman.h"
using namespace std;
using namespace sf;
class ghosts
{
protected:
	int row;
	int column;
	Clock clock;
	Texture texture;
	RectangleShape shape;
	float xEnemy;
	float yEnemy;
	char direction;

public:
	ghosts();
	void setDirection(char d);
	char getDirection();
};