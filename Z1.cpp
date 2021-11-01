#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>


using namespace std;

int max_size = 7, i, j, start, num;
int* DIST = (int*)malloc(max_size * sizeof(int));

void BSFD(int st, int** b, int num_of_elem, int* vis) {
	queue<int> Q;
	int t;
	Q.push(st);
	vis[st] = 0;

	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		printf("%d ", t + 1);
		for (int i = 0; i < num_of_elem; i++)
		{
			if (b[t][i] > 0 && vis[i] == 1000)
			{
				vis[i] = vis[t] + b[t][i];
				Q.push(i);
			}
		}
	}

}


void no_orient_graph()
{
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = i + 1; j < max_size; j++)
		{
			num = rand() % 7;
			if (num <= 3)
			{
				a[i][j] = 0;
				a[j][i] = a[i][j];
			}
			else
			{
				a[i][j] = (rand() % 6) + 1;
				a[j][i] = a[i][j];
			}
		}
	}
	printf("\nÍåîðèåíòèðîâàííûé ãðàô:\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nÏîèñê ðàññòîÿíèé â ÍÅîðèåíòèðîâàííîì ãðàôå \ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nÐàññòîÿíèå èç ïåðâîé:\n");
	for (i = 0; i < max_size; i++) {
		printf("äî %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}

void orient_graph() {
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = 0; j < max_size; j++)
		{
			num = rand() % 7;
			if (num <= 3)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = (rand() % 6) + 1;
			}
		}
	}
	printf("\n Îðèåíòèðîâàííûé ãðàô:\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nÏîèñê ðàññòîÿíèé â Îðèåíòèðîâàííîì ãðàôå \ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nÐàññòîÿíèå èç ïåðâîé:\n");
	for (i = 0; i < max_size; i++) {
		printf("äî %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	if (argc == 2)
	{
		if (strcmp(argv[1], "Neor") == 0)
			no_orient_graph();
		else if (strcmp(argv[1], "Or") == 0)
			orient_graph();
	}
	else if (argc == 3)
	{
		if (strcmp(argv[1], "Neor") == 0 and strcmp(argv[2], "Or") == 0)
		{
			no_orient_graph();
			orient_graph();
		}
		else if (strcmp(argv[1], "Or") == 0 and strcmp(argv[2], "Neor") == 0)
		{
			orient_graph();
			no_orient_graph();
		}
	}
}