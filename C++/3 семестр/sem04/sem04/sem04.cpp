//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

template <typename T>
void Unic(T& k, T *array, T& c)
{
	FILE *fp;
	fp = fopen("out.txt", "w");
	for (int i = 0; i < c; i++)
		fprintf(fp, " %10d", array[i]);
	fprintf(fp, "\n Count Elements \n");
	fprintf(fp, " %10d\n\n", c);
	fprintf(fp, "\n Median Elements \n");
	/*
	for (int i = 0; i < c; i++)
	{
		k = 1;
		for (int j = 0; j < c; j++)
		{
			if (i != j)
				if (array[i] == array[j])
				{
					k = 0;
					break;
				}
		}
		if (k == 1)
		{
			fprintf(fp, "%5d", array[i]);
			
		}
	}
	*/
	for (int i = 0; i < c; i++)
	{
		k = 0;
		for (int j = 0; j < c; j++)
		{
			if (i != j)
			{
				if (array[i] < array[j])
					k++;
			}
		}
		if (k == c / 2)
			fprintf(fp,"%5d", array[i]);
	}
	fclose(fp);
	//return 0;
}

int *array;
int symb;
int a[5];

int c = 0;
int w = 1;
int z = 0;
int k = 0;
int s = 0;

void SumWords();
void Read();

int main()
{
	SumWords();
	array = (int*)malloc(c * sizeof(int));
	Read();
	
	Unic<int>(k, array, c);
	
	getchar();
    return 0;
}

void SumWords()
{
	FILE *fp;
	fp = fopen("in.txt", "r");
	while (w != 0)
	{
		z = fgetc(fp);
		if ((z == 32) || (z == 10) || (z == -1))
		{
			s = s + k - 1;
			k = 0;
			c++;
		}
		if (z == EOF)
			w = 0;
	}
	fclose(fp);
	printf("%d Count elements", c);
}

void Read() 
{
	FILE *fp;
	fp = fopen("in.txt", "r");
	for (int i = 0; i < c; i++)
		fscanf(fp, "%d", &array[i]);
	fclose(fp);
}
