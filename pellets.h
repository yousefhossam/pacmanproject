#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Shader.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

using namespace sf;

class pellets
{
private:
	Texture texture;
	RectangleShape circle;

public:
	pellets();
	pellets(int initialColumn, int initialRow);
	void drawOnWindow(RenderWindow& window);
};

