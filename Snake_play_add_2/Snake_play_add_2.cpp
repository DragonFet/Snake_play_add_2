#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <fstream>

using namespace std;
int const weight = 30;
int const hight = 28;
int x, y, apple_x, apple_y;
int score;
int g;
int tale_x[100], tale_y[100];
int tails_apple = 0;
int control_score_for_print = 0;
int number = 0;
int var = 1;
enum movement { STOP = 0, RIGHT, LEFT, UP, DOWN };
movement trafic;
bool game_status_end;
struct date
{
	int score_2;
	string namesurname;;


};
void begin()
{
	game_status_end = false;
	trafic = STOP;
	x = weight / 2;
	y = hight / 2;
	apple_x = rand() % (weight - 1);
	apple_y = rand() % (hight - 1);
	while (apple_x > weight || apple_y > hight)
	{
		if (apple_x > weight || apple_y > hight)
		{
			apple_x = rand() % (weight - 1);
			apple_y = rand() % (hight - 1);
		}
	}

	score = 0;
}
void Draw()
{
	g = rand() % 10;
	system("cls");
	int a = 120;
	if (a == 10)
	{
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;

		}
		else cout << "SCORE " << score << endl;
	}
	else {
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;
			a = a - 10;
		}
		else cout << "SCORE " << score << endl;
	}


	for (int i = 0; i < weight + 1; i++)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
		while (g == 0)
		{
			g = rand() % 10;
		}
		cout << "#";
	}

	cout << endl;
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < weight + 1; j++)
		{
			if (j == 0 || j == weight)
			{


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
				while (g == 0)
				{
					g = rand() % 10;
				}
				cout << "#";
			}

			if (i == y && j == x)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
				while (g == 0)
				{
					g = rand() % 10;
				}
				cout << "*";
			}
			else
				if (i == apple_y && j == apple_x)
				{
					cout << "0";
				}

				else {
					bool print = false;
					for (int k = 0; k < tails_apple; k++)
					{

						if (tale_x[k] == j && tale_y[k] == i)
						{
							print = true;
							cout << "*";
						}
					}
					if (print == false)
					{
						cout << " ";
					}

				}
		}
		cout << endl;
	}

	for (int i = 0; i < weight + 1; i++)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
		while (g == 0)
		{
			g = rand() % 10;
		}
		cout << "#";
	}

	cout << endl;
	Sleep(15);

}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			trafic = LEFT;
			break;
		case 'w':
			trafic = UP;
			break;
		case'd':
			trafic = RIGHT;
			break;
		case 's':
			trafic = DOWN;
			break;
		case 'f':
			game_status_end = true;
			break;
		}
	}
}
void core()
{
	int pref_x = tale_x[0];
	int pref_y = tale_y[0];
	int pref_2x, pref_2y;
	tale_x[0] = x;
	tale_y[0] = y;
	for (int i = 1; i < tails_apple; i++)
	{
		pref_2x = tale_x[i];
		pref_2y = tale_y[i];
		tale_x[i] = pref_x;
		tale_y[i] = pref_y;
		pref_x = pref_2x;
		pref_y = pref_2y;
	}
	switch (trafic)
	{
	case LEFT:
		x--;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;


	}
	if (x >= weight || x < 0 || y >= hight || y < 0)
	{
		game_status_end = true;
	}
	for (int i = 0; i < tails_apple; i++)
	{
		if (tale_x[i] == x && tale_y[i] == y)
		{
			game_status_end = true;
		}
	}
	if (x == apple_x && y == apple_y)
	{
		score++;
		control_score_for_print = 1;
		apple_x = rand() % weight;
		apple_y = rand() % hight;
		tails_apple++;
	}
	while (apple_x >= weight || apple_y >= hight)
	{
		apple_x = rand() % (weight - 2);
		apple_y = rand() % (hight - 3);
	}
}
void output() {
	ifstream core_file_date;
	core_file_date.open("core.txt", ifstream::app);

	while (!core_file_date.eof())
	{
		string copy_a = "";
		getline(core_file_date, copy_a);
		if (copy_a != "")
		{
			cout << "|" << endl;
			cout << '\t' << var << " " << copy_a << endl;
			cout << "_._._._._._._._._._._._._._._" << endl;
			var++;
		}
	}
	core_file_date.close();
}
int main()
{
	ofstream core_file;
	ofstream core_file_number;
	ifstream core_file_number_vallue;

	core_file_number.open("core_number.txt", ofstream::app);
	core_file.open("core.txt", ofstream::app);

	core_file_number_vallue.open("core_number.txt");
	date* base = new date[10000];
	int solution = 6;
	string  g;
	int schetchik = 0;
	int number = 0;


	string* nedmas = new string[schetchik];
	for (int i = 0; i < schetchik; i++)
	{
		nedmas[i] = "0";
	}
	while (!core_file_number_vallue.eof())
	{
		core_file_number_vallue >> g;
		schetchik++;
	}
	if (schetchik == 0)
	{
		number = 1;
	}
	else
	{
		number = schetchik;
	}
	int number_2[4];
	int inspect = 0;
	int number_pred = number;


	while ((solution != 0) || (solution != 0))
	{
		if ((solution != 0))
		{
			cout << '\n';
			cout << "PIN_11_PRODUCTION INK PRESENT by MrGoblin" << endl;
			cout << "SNAKE v2.0 'No back home '" << endl;
			cout << "__---__---__" << endl;
			cout << "==_+_==_+_==" << endl;
			cout << "  \\ |  | /" << endl;
			cout << "   \\____/" << endl;
			cout << "Main Menu" << endl;
			cout << "Input '0' if you scared for run out in game " << endl;
			cout << "Please input '1' for start gamesssss....." << endl;
			cout << "Input '2' for watch Lider Bord" << endl;

			cin >> solution;

			switch (solution)
			{
			case 0:
			{
				solution = 0;
				game_status_end = true;
				break;
			}
			case 1:
			{
				inspect++;
				game_status_end = false;
				system("cls");
				begin();
				while (!game_status_end)
				{
					Draw();
					input();
					core();
				}
				cout << "Please input your Name and Surname" << " ";
				string name, surname;
				cin >> name >> surname;
				base[number].namesurname = name + "_" + surname;
				base[number].score_2 = score;
				score = 0;
				name = " ";
				surname = " ";
				core_file << base[number].namesurname << "_" << base[number].score_2 << endl;
				core_file_number << number << endl;
				number++;
				system("cls");
				x = weight / 2 - 1;
				y = hight / 2 - 1;
				solution = 5;
				tails_apple = 0;
				break;
			}
			case 2:
			{
				inspect++;
				system("cls");
				if (number != 1)
				{

					cout << ">>>>>>>>>>>>>>>>>>>>Player_and_scores<<<<<<<<<<<<<<" << endl;
					if (!(schetchik == 0))
					{
						output();


					}
					else {
						number++;
						for (int i = 1; i < number; i++)
						{
							cout << "NOW" << endl;
							cout << "|" << endl;
							cout << i << "_" << base[i].namesurname << "_" << base[i].score_2 << endl;
							cout << "_._._._._._._._._._._._._._._" << endl;
						}
					}
					cout << "______________________________________________________" << endl;
					var = 0;
					system("pause");
					system("cls");
				}
				else {
					cout << "Not founded :(" << endl;
					system("pause");
					cout << endl;
					system("cls");
				}

				break;
			}



			}
			srand(time(0));
		}
		else break;

	}
	core_file.close();
	core_file_number.close();
	core_file_number_vallue.close();

}