#include <stdio.h>
#include <math.h>
#include <ctime>

const int N = 10000000;

int array[N];
int sum1, sum2, sum3;
int max, max1, max2, max3;
int min;
int NumMax;
int Time;
int na1; //# NEW EL
int za1; //VALUE NEW EL
int na2; //# NEW EL
int za2; //VALUE NEW EL
int a; //FIRST EL
int da; //STEP
int Time1, Time2, Time3;	//Timers
void Generation(int *array, int N);
void Res1(int array[], int N);
void Res2(int array[], int N);
void Res3(int array[], int N);
void Vvod(); //READ FIRST ELEMENT
void Vivod();

int main()
{
	Vvod();
	Generation(array, N);
	Res1(array, N);
	Res2(array, N);
	Res3(array, N);
	Vivod();
}

void Vvod()				//INPUT FIRST ELEMENT
{
	char pust[100];

	FILE *fp;
	fp=fopen("in.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&a);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&da);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&za1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na2);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&za2);
	fclose(fp);
}

void Generation(int *array, int N) //GENERATION ARRAY
{
	array[0] = a;
	for(int i=1; i<N; i++)
	{
		array[i] = da + array[i-1];
	}

	array[na1] = za1; //NEW ELEMENTS
	array[na2] = za2; //NEW ELEMENTS
}

void Res1(int array[], int N)     //ONE CYKLE  +
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();

	max1 = array[0];
	max2 = array[1];
	max3 = array[2];
	for(int i=0; i<N; i++)
	{
		if (array[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = array[i];
			}
		else if (array[i] < max1 && max2 < array[i])
			max1 = array[i];
		else if (array[i] < max1 && max3 < array[i] && array[i] < max2)
			max1 = array[i];
	}
	sum1 = max1 + max2 + max3;
	TimeEnd = clock();
	Time1 = TimeEnd - TimeBegin;
}

void Res2(int array[], int N)     //THRE CYKLE  +
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();

	int k = 0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<N-1; j++)
				{
					if (array[j] > array[j+1])
						{
							k = array[j];
							array[j] = array[j+1];
							array[j+1] = k;
						}
				}
	}
	max1 = array[9999997]; //10000000
	max2 = array[9999999]; //9999999
	max3 = array[9999998]; //9999998
	sum2 = max1 + max2 + max3;
	TimeEnd = clock();
	Time2 = TimeEnd - TimeBegin;
}

void Res3(int array[], int N)     //FOUR CYKLE  +
{

	clock_t TimeBegin, TimeEnd;
	TimeBegin = clock();
	sum3 = 0;
	int min = array[0];
	for(int i = 1; i<N; i++)
		{
			if (min > array[i])
				min = array[i];
		}

	int k;
	for (int i = 0; i < 3; i++)
	{
		max = min;
		for (int j = 0; j < N; j ++)
			if (max < array[j])
			{
				max = array[j];
				k = j;
			}
		array[k] = min;
		sum3 += max;
	}

	TimeEnd = clock();
	Time3 = TimeEnd - TimeBegin;
}

void Vivod()
{
	FILE *fp;
	fp=fopen("out.txt","w");
	fprintf(fp,"  Summa 1    Times 1\n\n");
	fprintf(fp,"%10d", sum1);
	fprintf(fp,"%10d", Time1);
	fprintf(fp,"\n\n  Summa 2    Times 2\n\n");
	fprintf(fp,"%10d", sum2);
	fprintf(fp,"%10d", Time2);
	fprintf(fp,"\n\n  Summa 3    Times 3\n\n");
	fprintf(fp,"%10d", sum3);
	fprintf(fp,"%10d", Time3);
	fclose(fp);
}