#include "stdafx.h"
#include <ctime>
#include <cmath>

const int N = 100000;
int array[N];
int step1;
int step2;
int a1;
int a2;
int b;
int c;
int ai;
int k;
int l;
int r;

double Time1;
double Time2;
void Read();
void Generation();
void Calc1();
void Calc2();
void Print1();
void Print2();

int main()
{
	Read();
	Generation();
	
	Calc1();
	Print1();
	
	Generation();
	Calc2();
	Print2();
	return 0;
}

void Read()
{
	char pust[100];

	FILE *fp;
	fp = fopen("in.txt", "r");
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &a1);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &step1);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &a2);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &step2);
	fclose(fp);
}


void Generation()
{
	array[0] = a1;
	for (int i = 1; i < N; i++)
	{	
		array[i] = array[i - 1] + step1;
	}
}

void Calc1()
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (array[j] < array[j + 1])
			{
				int k = array[j + 1];
				array[j + 1] = array[j];
				array[j] = k;
			}
			//printf("%5d", array[i]);
			//getchar();
		}

	TimeEnd = clock();
	Time1 = TimeEnd - TimeBegin;
}

void Print1()
{
	printf("Time Puzir \n\n");
	printf("%15lf\n\n", Time1);
	FILE *fp;
	fp = fopen("outPuz.txt", "w");
	for (int i = 0; i < 100; i++)
		fprintf(fp, " %8d\n\n", array[i]);
	fclose(fp);
}

void Calc2()
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	int min;
	int numM;
	int n = N;
	for (int i = 1; i <= n; i++)
	{
		min = array[0];
		numM = 0;
		for (int j = 1; j <= n-i; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				numM = j;
			}
			//printf("%5d", array[j]);
			//getchar();
		}
		k = array[n-i];
		array[n-i] = array[numM];
		array[numM] = k;

	}
	TimeEnd = clock();
	Time2 = TimeEnd - TimeBegin;
}

void Print2()
{
	printf("Time Viborka \n\n");
	printf("%15lf\n\n", Time2);
	getchar();
	//for (int i = 0; i < N; i++) {
		//printf("%5d\n\n", array[i]);}
	
	FILE *fp;
	fp = fopen("outVs.txt", "w");
	for (int i = 0; i < 100; i++)
		fprintf(fp, " %8d\n\n", array[i]);
	fclose(fp);
}