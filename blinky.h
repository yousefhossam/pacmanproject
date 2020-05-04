#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "pacman.h"
#include "ghosts.h"
class blinky: public ghosts
{
private:

public:
	blinky();
	blinky(int initialRow, int initialColumn);
	void drawOnWindow(RenderWindow& window);
	void move(char direction, int arr[][19], pacman);

};

