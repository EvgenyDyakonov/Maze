#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


char **field (int length, char sumbol)
{
	int counter = 0;
	char particle = sumbol;
	char **arr = new char *[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = new char[length];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			counter = rand() % 3;
			if (counter != 0)
			{
				particle = ' ';
			}
			else
			{
				particle = sumbol;
			}
			arr[i][j] = particle;
		}
	}
	return arr;
}

bool traveler(char **arr, int length)
{
	int x = 0;
	int y = 0;
	int z = 0;
	while (y != length-1)
	{
		while (y == 0)
		{
			if (arr[x][y] == ' ')
			{
				if (x == length-1)
				{
					return false;
				}
				else
				{
					arr[x][y] = '0';
					y++;
					if (arr[x][y] == ' ')
					{
						arr[x][y] = '0';
					}
					else
					{
						arr[x][y - 1] = 'X';
						y--;
					}
				}
			}
			else
			{
				if (arr[0][x] == '0')
					arr[0][x] = 'X';
				x++;
				z = x;
			}
		}
		while (y != length - 1 && y != 0)
		{
			if (arr[x][y + 1] == ' ')
			{
				y++;
				arr[x][y] = '0';
			}
			else if (x > 0 && arr[x - 1][y] == ' ')
			{
				x--;
				arr[x][y] = '0';
			}
			else if (x < length-1 && arr[x + 1][y] == ' ')
			{
				x++;
				arr[x][y] = '0';
			}
			else if (y < length-1 && arr[x][y - 1] == '0')
			{
				arr[x][y] = 'X';
				y--;
			}
			else if (x > 0 && arr[x - 1][y] == '0')
			{
				arr[x][y] = 'X';
				x--;
			}
			else if (x < length-1 && arr[x + 1][y] == '0')
			{
				arr[x][y] = 'X';
				x++;
			}
			else if (y < length-1 && arr[x][y + 1] == '0')
			{
				arr[x][y] = 'X';
				y++;
			}
			else
			{
				for (int i = 0; i < length; i++)
				{
					if (arr[0][i] == 'X')
						arr[0][i] = ' ';
				}
				x = 0; y = 0;
				arr[z][0] = 'X';
			}
		}
		
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (arr[i][j] == 'X')
					arr[i][j] = ' ';
			}
		}
	}
	return true;
}

void print(char** arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << '|';
		for (int j = 0; j < length; j++)
		{
			cout << arr[j][i];
		}
		cout <<'|'<< endl;
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int length = 50;
	char **arr = field(length, '*');

	print(arr, length);
	
	cout << endl << "Zero show exit" << endl;

	if(traveler(arr, length))
	{
		print(arr, length);
	}
	else
	{
		cout << "Не удалось найти выход!" << endl;
	}
		
	for (int i = 0; i < length; i++)
	{
		delete [] arr[i];
	}
	delete[] arr;

	system("pause");

	return 0;
}