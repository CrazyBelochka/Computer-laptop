#include "game.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	CleverGamer h1;
	RandomGamer h2;
	Game play;
	play.place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	h1.name = "���� ";
	h2.name = "������ ";
	string var2;
	play.ModuleTest(var2 = "ldsfhgkjlsdh");
	play.ModuleTest(var2 = "9876994");
	play.ModuleTest(var2 = "123");
	play.ModuleTest(var2 = "1q");
	play.ModuleTest(var2 = "1 ");
	cout << "��������� ����������... ";
	Sleep(1000);
	system("cls");
	cout << "�������� ��������� ������ ���������." << endl;
	cout << "�������� �������� ����: " << endl;
	cout << "1. ������ ������" << endl;
	cout << "2. ������ �������������(�� �������)" << endl;
	cin >> var2;
	var2 = play.Test(var2);
	play.PressStart(var2, play, h1, h2);
}
