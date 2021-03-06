#include "stdafx.h"
#include <ctime>
#include <cmath>

const int N = 10;
int array[N];
int step;
int a;
int b;
int c;
int ai;
int k;
int l;
int r;

double Time1;
void Read();
void Generation();
void Calc();
void Print();

int main()
{
	Read();
	Generation();
	Calc();
	Print();
	return 0;
}

void Read()
{
	char pust[100];

	FILE *fp;
	fp = fopen("in.txt", "r");
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &a);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &step);
	fclose(fp);
}

void Generation()
{
	array[0] = a;
	for (int i = 1; i < N; i++)
		array[i] = array[i - 1] + step;
}


void Calc()
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	for (int i = 1; i < N; i++)
	{
		ai = array[i];
		for (int j = 0; j < i; j++)
		{
			if (ai < array[j])
			{
				k = j;
				for (int j = i; j > k; j--)
				{
					array[j] = array[j - 1];
				}
				array[k] = ai;
				break;
			}
		}
	}
	TimeEnd = clock();
	Time1 = TimeEnd - TimeBegin;
}


void Print()
{
	for (int i = 0; i < 10; i++)
		printf("%15d", array[i]);
	printf("%15lf", Time1);
	getchar();
	FILE *fp;
	fp = fopen("out.txt", "w");
	for (int i = 0; i < 100; i++)
		fprintf(fp, " %8d\n\n", array[i]);
	fclose(fp);
}