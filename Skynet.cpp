#include <iostream>
#include <string>
using namespace std;

struct GridObject
{
	int x;
	int y;
};

struct Grid
{
	int totalX;
	int totalY;

	void Render(GridObject obj)
	{
		for (int col = 0; col < totalY; col++)
		{
			for (int row = 0; row < totalX; row++)
			{
				if (obj.x == row && obj.y == col)
				{
					std::cout << "H";
				}
				else
				{
					std::cout << "[ ]";
				}
			}

			cout << endl;
		}

	}
};

struct PlayerInput
{
	string yourString;

	char GetInput()
	{
		cout << "Say Something ";
		cin >> yourString;

		cout << endl;
		cout << "you said: " << yourString << endl;
		cout << "first letter: " << yourString[0] << endl;

		cin.clear(); //clear error flags

		cout << endl;

		return yourString[0];
	}
};

int main()
{
	Grid grid; 
	grid.totalX = 8;
	grid.totalY = 8;

	GridObject obj;
	obj.x = 3;
	obj.y = 4;

	PlayerInput playerInput;
	char input = '0';

	while (input != 'q')
	{
		grid.Render(obj);

		input = playerInput.GetInput();

		if (input == 'a')
		{
			obj.x -= 1;
		}
		else if (input == 'd')
		{
			obj.x += 1;
		}
		else if (input == 'w')
		{
			obj.y -= 1;
		}
		else if (input == 's')
		{
			obj.y += 1;
		}
	}

	grid.Render(obj);
}