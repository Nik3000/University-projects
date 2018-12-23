#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <ctime>

const int N = 10000000;

double array[N];
double a; //FIRST EL
double da; //STEP
int na1, na2;
double za1, za2;
int Time;//Timers
int i;
int j;
int k;
int na0;

void Generation(double *array, int N); //GENERATTION ARRAY
void Res(double array[], int N);  //Calculation
void Read();
void Write();

int main()
{
  Read();
  Generation(array, N);
  Res(array, N);
  Write();
  for (i = 0; i < 10; i++)
  printf("%10lf", array[i]);
  printf("%10d", na0);
}

void Read()
{
	char pust[100];

	FILE *fp;
	fp=fopen("in.txt","r");  //FILE OPEN
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&a);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&da);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&za1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na2);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&za2);
	fclose(fp);  //FILE CLOSE
}

void Generation(double *array, int N)
{
	//Generation
	array[0] = a;
	for(i=1; i < N; i++)
	{
		array[i] = da + array[i-1];
	}
	array[na1] = za1; //NEW ELEMENTS
	array[na2] = za2; //NEW ELEMENTS
}

void Res(double array[], int N)
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	//Calculation
	int i, j, k;  //i - left  j - right
	for (i = 1, j = N - 1; i < j;)
	{
		for( ; array[i] < array[0]; i++);
		for( ; array[j] >= array[0]; j--);
		if (i > j)
		{
			k = array[0];
			array[0] = array[j];
			array[j] = k;
			break;
			i++;
			j--;
		}
	    else
	    {
			k = array[i];
			array[i] = array[j];
			array[j] = k;
			na0 = j;
		}
	}
	TimeEnd = clock();
	Time = TimeEnd - TimeBegin;
}

void Write()
{
  FILE *fp;
  fp=fopen("out.txt","w");
  fprintf(fp,"  ELEMENTS\n\n");
  if (na0 - 10 < 0)
  i = 20;
  else if (na0 + 10 > N)
  i = N;
  for (int j = i - 20; j < i; j++)
    fprintf(fp,"%10lf\n\n", array[j]);
  fprintf(fp, "  TIME");
  fprintf(fp, "%10d", Time);
  fclose(fp);
}
