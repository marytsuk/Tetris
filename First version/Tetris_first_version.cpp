// Tetris_first_version.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include "Game.h"
#include <time.h>
using namespace std;
using us = unsigned short;
int main()
{
	srand(time(0));
	Game ob;
	
	while(!ob.endGame)
	{ 
		us act;
		cout << "Action : " << endl;
		cin >> act;
		ob.Play(act);
		ob.Print_Field();
		cout << "Score : " << ob.Get_Score() << endl;
		ob.Play(3);
		ob.Print_Field();
		cout << "Score : " << ob.Get_Score() << endl;
	}
	
}


