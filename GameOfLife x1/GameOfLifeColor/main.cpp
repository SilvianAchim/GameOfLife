// Game Of Life made by Silvian Achim

#include <SFML/Graphics.hpp>

#define HEIGHT 1080
#define WIDTH 1920
#define CELLS 1800000

using namespace sf;

int board1[1081][1921], board2[1081][1920];
int cI = 0, first = 0, board = 1, size = 1;

void cellI()
{
	for (int i = 1; i <= CELLS; i++)
	{
		int x = rand() % WIDTH + 1;
		int y = rand() % HEIGHT + 1;
		board1[y][x] = 1;
	}
}

void gen1(int i, int j)
{
	int neighbors = 0;
	if (board1[i - 1][j - 1] == 1)
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
	// rules
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

void gen2(int i, int j)
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
	//rules
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
	RenderWindow window(VideoMode(1920, 1080), "Game of life by Silvian Achim", Style::Fullscreen);
	window.setFramerateLimit(60);
	Texture t1;
	t1.loadFromFile("Blackv3.png");
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
			cellI();
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
						gen1(i, j);
					}
					else if (board == 2)
					{
						gen2(i, j);
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
						B.setPosition(j * size, i * size);
						window.draw(B);
					}
				}
			}
		}
		else if (board == 2)
		{
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					if (board2[i][j] == 1)
					{
						B.setPosition(j * size, i * size);
						window.draw(B);
					}
				}
			}
		}
		window.display();
	}
}