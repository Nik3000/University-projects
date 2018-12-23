#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

int Time1, Time2, Time3;
const int m = 32;
long double i=1;
const int n = 32000000;
long double array[m];
long double s = 0;

int main()
{
	clock_t TimeEnd, TimeBegin;
	FILE *fp;
	fp = fopen("outPuz.txt", "w");
	for (int v = 1; v <= m; v++)
	{
		for (int z = 0; z < v; z++)
			array[z] = 0;
		TimeBegin = clock();
		long double s = 0;
		for (i = 1; i <= n - v; i += v)
		{
			for (int l = 0; l < v; l++)
			{
				array[l] += ((i + l) * (i + l)) / (1 + (i + l));
				//printf("%10lf", array[l]);
			}

		}
		for (int j = 0; j < v; j++)
			s = s + array[j];
		fprintf(fp,"\n%lf\n", s);
		TimeEnd = clock();
		Time2 = TimeEnd - TimeBegin;
		fprintf(fp,"\n%d\n", Time2);
	}
	fclose(fp);
	//printf("\n%d\n", Time3);
	//getchar();
	return 0;
}

