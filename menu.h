#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;
class menu
{
private:
	Texture start;
	char key;

public:
	menu();
	bool Start(char key);
	void setKey(char);

};