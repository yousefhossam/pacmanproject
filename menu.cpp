#include "menu.h"

menu::menu()
{
	key = 0;
}

bool menu::Start(char key)
{
	if (key == 83)
		return true;
}

void menu::setKey(char k)
{
	key = k;
}

