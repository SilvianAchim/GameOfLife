// Game of life made by Silvian Achim
#include <SFML/Graphics.hpp>
#include <iostream>

#define HEIGHT 60
#define WIDTH 60
#define CELLS 2000

using namespace sf;

int board1[385][217], board2[385][217];
int cI = 0, first = 0, board = 1;

void cellInitialition()
{
	for (int i = 1; i <= CELLS; i++)
	{
		int x = rand() % WIDTH + 1;
		//std::cout << "x=" << x << "\n";
		int y = rand() % HEIGHT + 1;
		//std::cout << "y=" << y << "\n";
		board1[y][x] = 1;
	}
}

void rules1(int i, int j)
{
	int neighbors = 0;
	if (board1[i - 1][j - 1]==1)
	{
		neighbors++;
	}
	if (board1[i - 1][j] == 1)
	{
		neighbors++;
	}
	if (board1[i - 1][j + 1] == 1)
	{
		neighbors++;
	}
	if (board1[i][j - 1] == 1)
	{
		neighbors++;
	}
	if (board1[i][j + 1] == 1)
	{
		neighbors++;
	}
	if (board1[i + 1][j - 1] == 1)
	{
		neighbors++;
	}
	if (board1[i + 1][j] == 1)
	{
		neighbors++;
	}
	if (board1[i + 1][j + 1] == 1)
	{
		neighbors++;
	}
	if (board1[i][j] == 1)
	{
		if (neighbors < 2)
		{
			board2[i][j] = 0;
		}
		if (neighbors > 3)
		{
			board2[i][j] = 0;
		}
		if (neighbors == 2 || neighbors == 3)
		{
			board2[i][j] = 1;
		}
	}
	if (board1[i][j] == 0)
	{
		if (neighbors == 3)
		{
			board2[i][j] = 1;
		}
	}
}

void rules2(int i, int j)
{
	int neighbors = 0;
	if (board2[i - 1][j - 1] == 1)
	{
		neighbors++;
	}
	if (board2[i - 1][j] == 1)
	{
		neighbors++;
	}
	if (board2[i - 1][j + 1] == 1)
	{
		neighbors++;
	}
	if (board2[i][j - 1] == 1)
	{
		neighbors++;
	}
	if (board2[i][j + 1] == 1)
	{
		neighbors++;
	}
	if (board2[i + 1][j - 1] == 1)
	{
		neighbors++;
	}
	if (board2[i + 1][j] == 1)
	{
		neighbors++;
	}
	if (board2[i + 1][j + 1] == 1)
	{
		neighbors++;
	}
	if (board2[i][j] == 1)
	{
		if (neighbors < 2)
		{
			board1[i][j] = 0;
		}
		if (neighbors > 3)
		{
			board1[i][j] = 0;
		}
		if (neighbors == 2 || neighbors == 3)
		{
			board1[i][j] = 1;
		}
	}
	if (board2[i][j] == 0)
	{
		if (neighbors == 3)
		{
			board1[i][j] = 1;
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(600, 600), "Game Of Life by Silvian Achim");
	window.setFramerateLimit(60);
	Texture t1;
	t1.loadFromFile("Black.png");
	Sprite B(t1);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}
		if (cI == 0)
		{
			cellInitialition();
			cI = 1;
		}
		window.clear(Color::White);
		for (int i = 1; i <= HEIGHT; i++)
		{
			for (int j = 1; j <= WIDTH; j++)
			{
				if (first == 1)
				{
					if (board == 1)
					{
						rules1(i, j);
					}
					else if (board == 2)
					{
						rules2(i, j);
					}
				}
				if (first == 0)
				{
					first = 1;
				}
				
			}
		}
		if (board == 1)
		{
			board = 2;
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					board1[i][j] = 0;
				}
			}
		}
		else
		{
			board = 1;
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					board2[i][j] = 0;
				}
			}
		}

		if (board == 1)
		{
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					if (board1[i][j] == 1)
					{
						B.setPosition(j * 10, i * 10);
						window.draw(B);
					}
				}
			}
		}
		if (board == 2)
		{
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					if (board2[i][j] == 1)
					{
						B.setPosition(j * 10, i * 10);
						window.draw(B);
					}
				}
			}
		}

		window.display();
	}



}


