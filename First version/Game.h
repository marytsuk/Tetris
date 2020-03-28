#pragma once
#include <vector>
using namespace std;

const int M = 20;                   //размеры поля
const int N = 10;
using us = unsigned short;

struct Point
{
	us x, y;
};
class Game
{
		us figures[7][4] =
		{
			1,3,5,7, // I
			2,4,5,7, // S
			3,5,4,6, // Z
			3,5,4,7, // T
			2,3,5,7, // L
			3,5,7,6, // J
			2,3,4,5, // O
		};
		Point a[4] = { 0 }, b[4] = { 0 };
		bool beginGame = true;
		us score = 0;
		us n;
	public:
		us field[M * N] = { 0 };
		bool endGame = false;
		vector <vector<us>> History;  //журнал для записи состояния поля после каждого действия
		/*us* Get_Field();*/
		bool Fix_Position(us n);      //закрепить позицию в поле, если вниз спускаться больше некуда
		int Get_Score();
		void Set_Movement(us act);    //задать действие
		void Print_Field();
		bool check();                 //можно ли сделать шаг в ту сторону, в которую хотим ?
		void Play(us action);         
		void Record();                //запись в журнал
};
