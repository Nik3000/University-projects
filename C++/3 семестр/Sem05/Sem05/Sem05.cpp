#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
char array[294][50];

int w = 1;
int z;
int n;
int s;
int c;

void SumWord();
void Read();
void Lose();

int main()
{
	setlocale(LC_ALL, "rus");
	SumWord();
	//array[50] = (char*)malloc(c * sizeof(char));
	Read();
	Lose();
    return 0;
}

void SumWord()
{
	FILE *fp;
	fp = fopen("journal.txt", "r");
	while (w != 0)
	{
		z = fgetc(fp);
		if ((z == 32) || (z == 10) || (z == -1) || (z == 9))
			c++;
		if (z == EOF)
			w = 0;
		//printf("%5d", z);
	}
	fclose(fp);
	printf("%5d", c);
	getchar();
}

void Read()
{
	FILE *fp;
	fp = fopen("journal.txt", "r");
	for (int i = 0; i < c; i++)
	{
		fscanf(fp, "%c", &array[i][50]);
		printf("%c", array[i][50]);
	}
	fclose(fp);
}

void Lose()
{
	for (int i = 0; i < c; i++)
	{
		if ((array[i][50] == '.окт') || (array[i][50] == '.ноя') || (array[i][50] == '.дек'))
			n++;
		if ((array[i][50] == '+') || (array[i][50] == '-'))
			s++;
	}
	printf("%5d", s);
	getchar();
}