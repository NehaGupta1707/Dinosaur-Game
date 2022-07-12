
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
int gameover=0;
int score=0;
using namespace std;
void hline(int l)
{
	cout.fill(196);
	cout.width(l);
	cout << (char)196;
}
void point(int px, int py)
{
	COORD coord;
	coord.X = px;
	coord.Y = py;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void structure(int z,int x,int y)
{
	point(x, y++);
		cout << "         млпллллм" << endl;
		point(x, y++);
		cout << "         лллллллл" << endl;
		point(x, y++);
		cout << "         лллллппп" << endl;
		point(x, y++);
		cout << " л      мллллппп " << endl;
		point(x, y++);
		cout << " ллм  мллллллммм " << endl;
		point(x, y++);
		cout << " пллллллллллл  п " << endl;
		point(x, y++);
		cout << "   плллллллп     " << endl;
		if (z == 1)
		{
			point(x, y++);
			cout << "    пллп  ппп    " << endl;
			point(x, y++);
			cout << "      лм         ";
		}
		else if (z == 2)
		{
			point(x, y++);
			cout << "     плм пл      " << endl;
			point(x, y++);
			cout << "          лм    ";
		}
		else {
			point(x, y++);
			cout << "   пллп пл      " << endl;
			point(x, y++);
			cout << "    лм   лм    ";

		}
		Sleep(100);
}
void erase(int ex,int ey,int countt)
{
	ey++;
	for (int m = 0; m < countt-1; m++,ey++)
	{
		point(ex, ey);
		cout << "                 ";
	}
	point(ex+6, ey);
	cout << "  ";
	point(ex+10, ey);
	cout << "  ";
}
void erase_o(int x, int y)
{
	point(x, y);
	cout << " ";
	point(x, ++y);
	cout << " ";
}
void obstacle(int x,int y)
{
	point(x, y);
	cout << (char)219;
	point(x, ++y);
	cout << (char)219;
}
void move_o(int xo[],int q,int &p,int x,int y)
{
	for (int i = p; i < q; i++)
	{


		if (xo[i] > 0 && xo[i] < 112)
		{

			erase_o(xo[i], 27);
			xo[i] -= 2;
			obstacle(xo[i], 27);
		}
		if (xo[i] < 1)
		{
			erase_o(2, 27);
			erase_o(3, 27);
			p++;
			score++;
		}
		if (y == 20 || y == 19)
		{
			if (xo[i] == 19 || xo[i] == 20 || xo[i] == 23 || xo[i] == 24|| xo[i] == 18|| xo[i] == 17)
				gameover = 1;
		}
	}
}
void Score()
{
	point(10, 35);
	cout << score;
}
int main()
{
	int xo[100],oo=0,q=0,p=0;
	int z = 1;
	int x = 10, y = 20;
	int time=0;
	point(0, 29);
	hline(112);
	point(0, 30);
	point(3, 33);
	cout << "Press Space to Jump." << endl;
	point(3, 35);
	cout << "Score: ";
	while (gameover==0)
	{
		Score();
	if(rand()%12==4)
	{	obstacle(111, 27);
		xo[oo] = 111;
		oo++;
		q ++;
	}
	move_o(xo,q,p,x,y);
		if(time==0)
			 x = 10, y = 20;
		structure(z,x,y);
		if (_kbhit())
		{
			char v = _getch();
			if (v == 32)
			{
				if(y>3)
				{
					erase(x, y,8);
					if (time > 0)
						y -= 2;
					else
						y -= 7;
				}
			}
			time = 7;
		}
		if (time > 0)
		{
			time--;
			if (time == 0)
			{
				erase(x, --y,9);
			}
		}
		if (time < 1)
		{
			if (z == 1)
				z = 2;
			else if (z == 2)
				z = 1;
		}
	}
	point(3, 37);

	cout << "GameOver";
	char o=_getch();
}
