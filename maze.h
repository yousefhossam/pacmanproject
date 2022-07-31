#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;
class maze
{
private:
	int row;
	int column;
	RectangleShape shape;
	Texture texture;
public:
	maze(int rowx, int coloumnx, string imageName);
	void drawOnWindow(RenderWindow& window);
	int getRow();
	int getColumn();
};
