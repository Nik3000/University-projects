#include <stdio.h> 
#include <math.h>
#include <ctime>
#define N1 6  //CONST
#define N2 5  //CONST
#define N3 N1 + N2  //CONST

int array1[N1];
int array2[N2];
int array3[N3];
int i;
int j;
int k;
int a1; //FIRST EL
int da1; //STEP
int a2; //FIRST EL
int da2; //STEP
int Time;//Timers
void Generation(); //GENERATTION ARRAY
void Res();  //Calculation
void Vvod(); //READ FIRST ELEMENT  

int main()
{
	Vvod();
	Generation();
	Res();
}

void Vvod()				//INPUT FIRST ELEMENT
{
	char pust[100];
  
 	FILE *fp;
	fp=fopen("in.txt","r");  //FILE OPEN
	fscanf(fp,"%s",pust);  //PASS LINE
	fscanf(fp,"%d",&a1);  //READ VARIABLE
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&da1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&a2);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&da2);  
	fclose(fp);  //FILE CLOSE
}	

void Generation() //GENERATION ARRAY
{
	array1[0] = a1;
	array2[0] = a2;
	for(int i=1; i<N1; i++)
	{
		array1[i] = da1 + array1[i-1];
	}
	
	for(int i=1; i<N2; i++)
	{
		array2[i] = da2 + array2[i-1];
	}
}

void Res()  //CALCULATIONS
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();  //TIMERS ON
	
	j = 0;
	k = 0;
	i = 0;

	for(i = 0; i < N3; i++)
	{
		if (k < N1 && j < N2)
		{
			if (array1[k] > array2[j])
			{
				array3[i] = array2[j];
				j++;
			}
			else  //IF (array1[k] < array2[j] 
			{
				array3[i] = array1[k];
				k++;
			}
		}
		else if (k == N1)
		{
			array3[i] = array2[j]; j++;
		} 
		else  //IF (j == N2)
		{
			array3[i] = array1[k]; k++;
		}
	}

	TimeEnd = clock();  //TIMERS OFF
	Time = TimeEnd - TimeBegin;  //TIME RESULTS
	
	FILE *fp;  //WRITE RESULTS
	fp=fopen("out.txt","w");
	fprintf (fp, "%5d\n\n", Time);
	for (int i=N3-20; i<N3; i++)
	{
		fprintf(fp,"%5d\n\n", array3[i]);
	}
	fclose(fp);
}

//for (i = 0; i < n; i++)
//{
	//array3[i] = array1[i]; 
//}

//for (i = n; i < m+n; i++)
//{
	//array3[i] = array2[i-n];
//}

//for (i = 0; i < n+m-1; i++)
//{
	//for (j = 0; j < n+m-i-1; j++)
	//{
		//if (array3[j] > array3[j+1]) 
		//{
			//k = array3[j];
			//array3[j] = array3[j+1];
			//array3[j+1] = k;
		//}
	//}
//}
