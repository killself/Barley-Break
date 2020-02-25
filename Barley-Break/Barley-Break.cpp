#include <iostream>
#include <iomanip>
#include <Windows.h>

const int FIELD_SIZE = 4;

void drawingPlayingField(int arr[FIELD_SIZE][FIELD_SIZE])
{

	std::cout << "\n ---------------------\n";
	for (int i = 0; i < FIELD_SIZE; ++i)
	{
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			std::cout << " | ";
			if (arr[i][j] == 0)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << std::setw(2) << arr[i][j];
			}
		}
		std::cout << " |\n ---------------------\n";
	}


}

bool winCheck(int arr[FIELD_SIZE][FIELD_SIZE])
{	

	for (int i = 0; i < FIELD_SIZE; ++i)
	{
		int currentElement = arr[i][0];

		for (int j = 1; j < FIELD_SIZE - 1; ++j)
		{
			if (arr[i][j] == 0)
			{
				continue;
			}
			else if (currentElement + 1 != arr[i][j])
			{
				return false;
			}
			currentElement = arr[i][j];
		}
	}

	return true;

}

void swap(int& firstValue, int& secondValue)
{
	int temp = firstValue;
	firstValue = secondValue;
	secondValue = temp;
}

void move(int arr[FIELD_SIZE][FIELD_SIZE])
{

	int i = 0;
	int j = 0;

	while (true)
	{
		std::cout << "\nEnter row and column (separeted by space): ";
		std::cin >> i >> j;
		--i;
		--j;

		if ((i > 0) && (arr[i - 1][j] == 0))
		{
			swap(arr[i][j], arr[i - 1][j]);
			break;
		}
		else if ((i < (FIELD_SIZE - 1)) && (arr[i + 1][j] == 0))
		{
			swap(arr[i][j], arr[i + 1][j]);
			break;
		}
		else if ((j < (FIELD_SIZE - 1)) && (arr[i][j + 1] == 0))
		{
			swap(arr[i][j], arr[i][j + 1]);
			break;
		}
		else if ((j > 0) && (arr[i][j - 1] == 0))
		{
			swap(arr[i][j], arr[i][j - 1]);
			break;
		}
		else
		{
			std::cout << "\nThis tile cannot be moved \n";
		}
	}

}


int main()
{

	int menu = 0;
	int playingField[FIELD_SIZE][FIELD_SIZE] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 12, 0},
		{ 13, 14, 11, 15}
	};



	std::cout << "*********************************************************************************\n";
	std::cout << "\t\t\tThe Barley-Break Game v0.01\n";
	std::cout << "*********************************************************************************\n\n";



	while (true)
	{
		std::cout << "\nMENU:\n\n";
		std::cout << "1. Play the game\n";		
		std::cout << "2. Exit\n";
		std::cin >> menu;

		if (menu > 0 && menu < 3)
		{
			break;
		}
		system("cls");
	}

	if (menu == 2)
	{
		std::cout << "\nGoodbye!\n\n";
		Sleep(900);
		return 0;		
	}

	while (true)
	{
		system("cls");
		drawingPlayingField(playingField);
		move(playingField);
		if (winCheck(playingField))
		{
			system("cls");
			drawingPlayingField(playingField);
			std::cout << "\nYou win!\n\n";
			Sleep(1000);
			return 0;
		}
		Sleep(300);
		
	}
	
}