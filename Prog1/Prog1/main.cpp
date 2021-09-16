#include "game.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	CleverGamer h1;
	RandomGamer h2;
	Game play;
	play.place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	h1.name = "Рома ";
	h2.name = "Никита ";
	string var2;
	play.ModuleTest(var2 = "ldsfhgkjlsdh");
	play.ModuleTest(var2 = "9876994");
	play.ModuleTest(var2 = "123");
	play.ModuleTest(var2 = "1q");
	play.ModuleTest(var2 = "1 ");
	cout << "Подождите немножечко... ";
	Sleep(1000);
	system("cls");
	cout << "Проверка модульных тестов завершена." << endl;
	cout << "Выберите варианты игры: " << endl;
	cout << "1. Играть самому" << endl;
	cout << "2. Играть автоматически(по заданию)" << endl;
	cin >> var2;
	var2 = play.Test(var2);
	play.PressStart(var2, play, h1, h2);
}
