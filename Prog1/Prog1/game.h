#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <limits>

#undef max 

const unsigned int HEIGHT_PLAYFIELD = 24;
const unsigned int ARRAY_LENGTH = 73;
const unsigned int ARRAY_HEIGHT = 25;
const unsigned int NUMBER_OF_FIELDS = 9;
const unsigned int TEST_INPUT = 160;

using namespace std;

class Game
{
public:
	string name;
	int amount_moves;
	int number;
	int NumberVariations[NUMBER_OF_FIELDS] = { 0 };
	char place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	int x;
	int y;
	void ModuleTest(string var2)
	{
		for (;;)
		{
			if (((var2[0] == '1') || (var2[0] == '2')) && (!var2[1]))
			{
				break;
			}
			else
			{
				cout << "Ошибка ввода, проверьте правильность вашего ввода и попробуйте еще раз: " << endl;
				break;
			}
		}
	}

	string Test(string var2)
	{
		for (;;)
		{
				if (((var2[0] == '1') || (var2[0] == '2')) && (!var2[1]))
				{
					return(var2);
				}
				else
				{
					cout << "Ошибка ввода, проверьте правильность вашего ввода и попробуйте еще раз: " << endl;
					cout << "Выберите варианты игры: " << endl;
					cout << "1. Играть самому" << endl;
					cout << "2. Играть автоматически(по заданию)" << endl;
					cin >> var2;
					var2 = Test(var2);
				}
		}
	}

	void WinCheck()
	{
		if (((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 1))\
			|| (NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 1)\
			|| (NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 1)\
			|| (NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 1))
		{
			cout << "Winner:  Роман" << endl;
			system("pause");
			exit(0);
		}
		if (((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 2))\
			|| (NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 2)\
			|| (NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 2)\
			|| (NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 2))
		{
			cout << "Winner:  Никита" << endl;
			system("pause");
			exit(0);
		}
	}

	void DrawCross(int x, int y)
	{
		place[x - 3][y - 3] = '0';
		place[x + 3][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 1][y - 1] = '0';
		place[x + 1][y - 1] = '0';
		place[x][y] = '0';
		place[x - 1][y + 1] = '0';
		place[x + 1][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 3] = '0';
		place[x + 3][y + 3] = '0';
	}

	void DrawCircle(int x, int y)
	{
		place[x - 1][y - 3] = '0';
		place[x][y - 3] = '0';
		place[x + 1][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 3][y - 2] = '0';
		place[x + 3][y - 2] = '0';
		place[x - 4][y - 1] = '0';
		place[x + 4][y - 1] = '0';
		place[x - 4][y] = '0';
		place[x + 4][y] = '0';
		place[x - 4][y + 1] = '0';
		place[x + 4][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 2] = '0';
		place[x + 3][y + 2] = '0';
		place[x - 1][y + 3] = '0';
		place[x][y + 3] = '0';
		place[x + 1][y + 3] = '0';
	}

	int PossibleRandMoves(int amount_moves)
	{
		int counter = 0;
		int move = 0;
		for (;;)
		{
			srand(time(0));
			move = rand() % 9;
			if (NumberVariations[move] == 0)
			{
				break;
			}
		}
		if (amount_moves % 2 == 0) {

			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 1;
				switch (move + 1)
				{
				case 1:
					DrawCross(12, 4);
					break;
				case 2:
					DrawCross(35, 4);
					break;
				case 3:
					DrawCross(58, 4);
					break;
				case 4:
					DrawCross(12, 12);
					break;
				case 5:
					DrawCross(35, 12);
					break;
				case 6:
					DrawCross(58, 12);
					break;
				case 7:
					DrawCross(12, 20);
					break;
				case 8:
					DrawCross(35, 20);
					break;
				case 9:
					DrawCross(58, 20);
					break;

				default:
					break;
				}
			}
		}
		else
		{
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 2;
				switch (move + 1)
				{
				case 1:
					DrawCircle(12, 4);
					break;
				case 2:
					DrawCircle(35, 4);
					break;
				case 3:
					DrawCircle(58, 4);
					break;
				case 4:
					DrawCircle(12, 12);
					break;
				case 5:
					DrawCircle(35, 12);
					break;
				case 6:
					DrawCircle(58, 12);
					break;
				case 7:
					DrawCircle(12, 20);
					break;
				case 8:
					DrawCircle(35, 20);
					break;
				case 9:
					DrawCircle(58, 20);
					break;

				default:
					break;
				}
			}
		}
		return(amount_moves);

	}

	int NumberChecker(int number)
	{
		bool test = TRUE;
		do {
			cin >> number;
			if (!(test = cin.good()))
			{
				cout << "Неправильный ввод: " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!test);
		{
			if ((1 > number) || (number > 9))
			{
				cout << "Неправильный ввод: " << endl;
				number = NumberChecker(number);
			}
			else
			{
					if (NumberVariations[number-1] == 0)
					{
						return(number);
					}
					else
					{
						cout << "Неправильный ввод: " << endl;
						number = NumberChecker(number);
					}
			}
		}
}

	int PossibleMoves(int amount_moves)
	{
		if (amount_moves == 0)
		{
			cout << "Выберите куда нарисовать крестик:" << endl;
			cout << "1.Левый верхний угол " << endl;
			cout << "2.Центральный верхний квадрат " << endl;
			cout << "3.Правый верхний угол " << endl;
			cout << "4.Левый центральный квадрат " << endl;
			cout << "5.Центральный квадрат " << endl;
			cout << "6.Правый центральный квадрат " << endl;
			cout << "7.Левый нижний угол " << endl;
			cout << "8.Центральный нижний квадрат " << endl;
			cout << "9.Правый нижний угол " << endl;
			number = NumberChecker(number);

			NumberVariations[number - 1] = 1;
			switch (number)
			{
			case 1:
				DrawCross(12, 4);
				break;
			case 2:
				DrawCross(35, 4);
				break;
			case 3:
				DrawCross(58, 4);
				break;
			case 4:
				DrawCross(12, 12);
				break;
			case 5:
				DrawCross(35, 12);
				break;
			case 6:
				DrawCross(58, 12);
				break;
			case 7:
				DrawCross(12, 20);
				break;
			case 8:
				DrawCross(35, 20);
				break;
			case 9:
				DrawCross(58, 20);
				break;

			default:
				break;
			}
		}
		if ((amount_moves != 0) && (amount_moves % 2 == 1))
		{
			cout << "Куда поставить нолик: " << endl;
			if (NumberVariations[0] == 0)
			{
				cout << "1.Левый верхний угол " << endl;
			}
			if (NumberVariations[1] == 0)
			{
				cout << "2.Центральный верхний квадрат " << endl;
			}
			if (NumberVariations[2] == 0)
			{
				cout << "3.Правый верхний угол " << endl;
			}
			if (NumberVariations[3] == 0)
			{
				cout << "4.Левый центральный квадрат " << endl;
			}
			if (NumberVariations[4] == 0)
			{
				cout << "5.Центральный квадрат " << endl;
			}
			if (NumberVariations[5] == 0)
			{
				cout << "6.Правый центральный квадрат " << endl;
			}
			if (NumberVariations[6] == 0)
			{
				cout << "7.Левый нижний угол " << endl;
			}
			if (NumberVariations[7] == 0)
			{
				cout << "8.Центральный нижний квадрат " << endl;
			}
			if (NumberVariations[8] == 0)
			{
				cout << "9.Правый нижний угол " << endl;
			}
			number = NumberChecker(number);
			NumberVariations[number - 1] = 2;
			switch (number)
			{
			case 1:
				DrawCircle(12, 4);
				break;
			case 2:
				DrawCircle(35, 4);
				break;
			case 3:
				DrawCircle(58, 4);
				break;
			case 4:
				DrawCircle(12, 12);
				break;
			case 5:
				DrawCircle(35, 12);
				break;
			case 6:
				DrawCircle(58, 12);
				break;
			case 7:
				DrawCircle(12, 20);
				break;
			case 8:
				DrawCircle(35, 20);
				break;
			case 9:
				DrawCircle(58, 20);
				break;

			default:
				break;
			}
		}
		if ((amount_moves != 0) && (amount_moves % 2 == 0))
		{
			cout << "Куда поставить крест: " << endl;
			if (NumberVariations[0] == 0)
			{
				cout << "1.Левый верхний угол " << endl;
			}
			if (NumberVariations[1] == 0)
			{
				cout << "2.Центральный верхний квадрат " << endl;
			}
			if (NumberVariations[2] == 0)
			{
				cout << "3.Правый верхний угол " << endl;
			}
			if (NumberVariations[3] == 0)
			{
				cout << "4.Левый центральный квадрат " << endl;
			}
			if (NumberVariations[4] == 0)
			{
				cout << "5.Центральный квадрат " << endl;
			}
			if (NumberVariations[5] == 0)
			{
				cout << "6.Правый центральный квадрат " << endl;
			}
			if (NumberVariations[6] == 0)
			{
				cout << "7.Левый нижний угол " << endl;
			}
			if (NumberVariations[7] == 0)
			{
				cout << "8.Центральный нижний квадрат " << endl;
			}
			if (NumberVariations[8] == 0)
			{
				cout << "9.Правый нижний угол " << endl;
			}
			number = NumberChecker(number);
			NumberVariations[number - 1] = 1;
			switch (number)
			{
			case 1:
				DrawCross(12, 4);
				break;
			case 2:
				DrawCross(35, 4);
				break;
			case 3:
				DrawCross(58, 4);
				break;
			case 4:
				DrawCross(12, 12);
				break;
			case 5:
				DrawCross(35, 12);
				break;
			case 6:
				DrawCross(58, 12);
				break;
			case 7:
				DrawCross(12, 20);
				break;
			case 8:
				DrawCross(35, 20);
				break;
			case 9:
				DrawCross(58, 20);
				break;

			default:
				break;
			}
		}
		return(amount_moves++);
	}

	void DrawPlayField(char place[ARRAY_LENGTH][ARRAY_HEIGHT])
	{
		for (size_t y = 0; y < 1; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 1; y < ARRAY_HEIGHT - 16; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 8; y < 9; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 9; y < ARRAY_HEIGHT - 8; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 16; y < 17; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 16; y < ARRAY_HEIGHT; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 24; y < 25; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}



		for (size_t y = 0; y < ARRAY_HEIGHT; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				if (place[x][y] == false)
				{
					cout << " ";
				}
				cout << place[x][y];
			}
			cout << endl;
		}
	}

	void StartGame(string name1, string name2)
	{
		amount_moves = 0;
		cout << "			   Игра началась!" << endl;
		cout << name1 << "								" << name2 << endl;
	}

	int logic(int amount_moves)
	{
		if (amount_moves % 2 == 0)
		{
			if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(35, 4);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(58, 12);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(12, 12);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(35, 20);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(12, 12);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(35, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(35, 4);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(58, 12);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(35, 4);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(58, 12);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(12, 12);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(35, 20);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(12, 12);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(35, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(35, 4);
				return(amount_moves);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(58, 12);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(58, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(12, 4);
				return(amount_moves);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(12, 20);
				return(amount_moves);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(58, 4);
				return(amount_moves);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(35, 12);
				return(amount_moves);
			}
			int move = 0;
			for (;;)
			{
				srand(time(0));
				move = rand() % 9;
				if (NumberVariations[move] == 0)
				{
					break;
				}
			}
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 1;
				switch (move + 1)
				{
				case 1:
					DrawCross(12, 4);
					break;
				case 2:
					DrawCross(35, 4);
					break;
				case 3:
					DrawCross(58, 4);
					break;
				case 4:
					DrawCross(12, 12);
					break;
				case 5:
					DrawCross(35, 12);
					break;
				case 6:
					DrawCross(58, 12);
					break;
				case 7:
					DrawCross(12, 20);
					break;
				case 8:
					DrawCross(35, 20);
					break;
				case 9:
					DrawCross(58, 20);
					break;

				default:
					break;
				}
			}
			return(amount_moves);
		}

		if(amount_moves %2 == 1)
		{
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 2;
				DrawCircle(58, 4);
				return(amount_moves);
			}
				if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(35, 4);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(58, 12);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(12, 12);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(35, 20);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(12, 12);
					return(amount_moves);
				}
				if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(35, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(35, 4);
					return(amount_moves);
				}
				if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(58, 4);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(58, 12);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(58, 4);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(58, 4);
					return(amount_moves);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(35, 4);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(58, 12);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(12, 12);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(35, 20);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(12, 12);
					return(amount_moves);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(35, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(35, 4);
					return(amount_moves);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(58, 4);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(58, 12);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(58, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(12, 4);
					return(amount_moves);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(12, 20);
					return(amount_moves);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(58, 4);
					return(amount_moves);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(35, 12);
					return(amount_moves);
				}	
				int move = 0;
				for (;;)
				{
					srand(time(0));
					move = rand() % 9;
					if (NumberVariations[move] == 0)
					{
						break;
					}
				}
				if (NumberVariations[move] == 0)
				{
					NumberVariations[move] = 2;
					switch (move + 1)
					{
					case 1:
						DrawCircle(12, 4);
						break;
					case 2:
						DrawCircle(35, 4);
						break;
					case 3:
						DrawCircle(58, 4);
						break;
					case 4:
						DrawCircle(12, 12);
						break;
					case 5:
						DrawCircle(35, 12);
						break;
					case 6:
						DrawCircle(58, 12);
						break;
					case 7:
						DrawCircle(12, 20);
						break;
					case 8:
						DrawCircle(35, 20);
						break;
					case 9:
						DrawCircle(58, 20);
						break;

					default:
						break;
					}
				}
		}

		return(amount_moves);
	}

	void PressStart(string var2, Game play, Game h1, Game h2 )
	{
		if (var2[0] == '1')
		{
			play.StartGame(h1.name, h2.name);
			play.DrawPlayField(play.place);
			for (play.amount_moves = 0; play.amount_moves < NUMBER_OF_FIELDS; play.amount_moves++)
			{
				play.amount_moves = play.PossibleMoves(play.amount_moves);
				play.DrawPlayField(play.place);
				play.WinCheck();
			}
			if (play.amount_moves == 9)
			{
				cout << "Draw";
			}
		}
		if (var2[0] == '2')
		{
			cout << endl << "Укажите, кто ходит первым: " << endl;
			cout << "Игрок 1 - его цель - не проиграть" << endl;
			cout << "Игрок 2 - его ходы случайны" << endl;
			int choose = 0;
			int check = 0;
			cin >> choose;
			if (choose == 1)
			{
				play.StartGame(h1.name, h2.name);
				while (play.amount_moves != 9)
				{
					play.amount_moves = play.logic(play.amount_moves);
					play.DrawPlayField(play.place);
					play.WinCheck();
					Sleep(500);
					play.amount_moves++;
					if (play.amount_moves == 9)
					{
						break;
					}
					play.amount_moves = play.PossibleRandMoves(play.amount_moves);
					play.DrawPlayField(play.place);
					play.WinCheck();
					Sleep(500);
					play.amount_moves++;
				}
				cout << "Draw";
			}
			if (choose == 2)
			{
				play.StartGame(h1.name, h2.name);
				while (play.amount_moves != 9)
				{
					play.amount_moves = play.PossibleRandMoves(play.amount_moves);
					play.DrawPlayField(play.place);
					play.WinCheck();
					Sleep(500);
					play.amount_moves++;
					if (play.amount_moves == 9)
					{
						break;
					}
					play.amount_moves = play.logic(play.amount_moves);
					play.DrawPlayField(play.place);
					play.WinCheck();
					Sleep(500);
					play.amount_moves++;
				}
				cout << "Draw";
			}
		}
	}
};

class CleverGamer : public Game
{
public:
	string name;
};

class RandomGamer : public Game
{
public:
	string name;
	int move;
};

