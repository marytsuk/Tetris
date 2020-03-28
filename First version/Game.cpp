#include "pch.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#define LEFT 1
#define RIGHT 2
#define DOWN 3
using namespace std;
using us = unsigned short;

void Game::Record()
{
	vector<us> tmp(M * N);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			tmp.push_back(field[i * N + j]);
	History.push_back(tmp);
}

bool Game::Fix_Position(us n)
{
	if (n == 0)
	{
		if (a[3].y >= M - 1)
		{
			beginGame = true;
			return 1;
		}
		else
			if (field[(a[3].y + 1) * N + a[3].x])
			{
				beginGame = true;
				return 1;
			}
	}
	else if (n == 4)
	{
		if (a[3].y >= M - 1)
		{
			beginGame = true;
			return 1;
		}
		else
			if (field[(a[3].y + 1) * N + a[3].x] || field[(a[0].y + 1) * N + a[0].x])
			{
				beginGame = true;
				return 1;
			}
	}
	else if (n == 2 || n == 1)
	{
		if (a[3].y >= M - 1)
		{
			beginGame = true;
			return 1;
		}
		else
			if (field[(a[3].y + 1) * N + a[3].x] || field[(a[1].y + 1) * N + a[1].x])
			{
				beginGame = true;
				return 1;
			}
	}
	else if (n == 6 || n == 5 || n == 3)
	{
		if (a[2].y >= M - 1 || a[3].y >= M - 1)
		{
			beginGame = true;
			return 1;
		}
		else
			if ((field[(a[2].y + 1) * N + a[2].x] || field[(a[3].y + 1) * N + a[3].x]))
			{
				beginGame = true;
				return 1;
			}
	}
	
	return 0;
}

//us* Game::Get_Field()
//{
//	//vector<double> res;
//	us* res = new us[M * N];
//	for (size_t i = 0; i < M; i++)
//		for (size_t j = 0; j < N; j++)
//		{
//			res[i] = field[i][j];
//		}
//	return res;
//}

void Game::Set_Movement(us act)
{
	us dx = 0;
	us dy = 0;
	if (act == RIGHT)
	{
		dx++;
	}
	if (act == LEFT)
	{
		dx--;
	}
	if (act == DOWN)
	{
		dy++;
		
	}
	for (size_t i = 0; i < 4; i++)
		field[a[i].y * N + a[i].x] = 0;
	for (size_t i = 0; i < 4; i++)
	{
		b[i] = a[i];
		a[i].x += dx;
		a[i].y += dy;
	}
	
	if (!check())
	{
		for (size_t i = 0; i < 4; i++)
			a[i] = b[i];
		for (size_t i = 0; i < 4; i++)
			field[b[i].y * N + b[i].x] = 1;
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
			field[a[i].y * N + a[i].x] = 1;
	}
	
}

void Game::Print_Field()
{

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
			cout << setw(2) << field[i * N + j];
		cout << endl;
	}

}

bool Game::check()
{
	for (size_t i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) 
			return 0;
		else 
			if (field[a[i].y * N + a[i].x]) 
				return 0;

	return 1;
}

void Game::Play(us action)
{
	if (beginGame)
	{
		beginGame = false;
		n = rand() % 6;
		int r = rand() % (N - 2);
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2 + r;
			a[i].y = figures[n][i] / 2;
		}
		if (n == 6 || n == 5)
		{
			if (field[(a[2].y + 1) * N + a[2].x] || field[(a[3].y + 1) * N + a[3].x])
			{
				endGame = true;
				return;
			}
		}
		else if (n == 3 || n == 4 || n == 1 || n == 2 || n == 0)
		{
			if (field[(a[3].y + 1) * N + a[3].x])
			{
				endGame = true;
				return;
			}
		}
	}
	
	Set_Movement(action);
	
	if (Fix_Position(n))
	{
		us k = M - 1;
		for (size_t i = M - 1; i > 0; i--)
		{
			int count = 0;
			for (size_t j = 0; j < N; j++)
			{
				if (field[i * N + j])
					count++;
				field[k * N + j] = field[i * N + j];
			}
			if (count < N)
				k--;
			else
			{
				score++;
			}
		}
	}
	
}

int Game::Get_Score()
{
	return score;
}