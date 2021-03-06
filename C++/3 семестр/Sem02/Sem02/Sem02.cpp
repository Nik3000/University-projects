#include "stdafx.h".
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

const int N = 100000000;
double Time1;
int array[N];
int step;
int a;
int r;

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
	{
		array[i] = array[i - 1] + step;
	}
}

void quicksort(int *mas, int first, int last)
{
	int mid, count;
	
	int f = first, l = last;
	
	//Поиск медианы среди 0, (N-1)/2 и N-1 элементов.
	if ((array[f] >= array[(l + f) / 2] && array[f] <= array[(l)]) || (array[f] >= array[(l + f) / 2] && array[f] <= array[l]))
		mid = array[f];
	else if ((array[(l + f) / 2] >= array[l] && array[(l + f) / 2] <= array[f]) || (array[(l + f) / 2] >= array[f] && array[(l + f) / 2] <= array[l]))
		mid = array[(l + f) / 2];
	else if ((array[l] >= array[(l + f) / 2] && array[l] <= array[f]) || (array[l] >= array[f] && array[l] <= array[(l + f) / 2]))
		mid = array[l];
	//mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f]>mid)
			f++;
		while (mas[l]<mid)
			l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l)
		quicksort(mas, first, l);
	if (f<last)
		quicksort(mas, f, last);
}

void Print()
{
	printf("Time\n\n");
	printf("%15lf\n\n", Time1);
	FILE *fp;
	fp = fopen("out.txt", "w");
	for (int i = 0; i < 100; i++)
		fprintf(fp, " %8d\n\n", array[i]);
	fclose(fp);
}

int main()
{
	Read();
	Generation();

	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	quicksort(array, 0, N-1);
	TimeEnd = clock();
	Time1 = TimeEnd - TimeBegin;

	for (int i = 0; i < 100; i++)
		printf("%d ", array[i]);
	printf("\n");
	Print();
	getchar();
	return 0;
}
