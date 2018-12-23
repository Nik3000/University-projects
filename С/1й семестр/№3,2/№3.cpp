//				Учебная программа 
//				
//				Пример работы с массивом
//				(запись в файл в обратном порядке)
//				27 сентября 2015 г.				
//---------------------------------------------------------------------------------------

//#include "stdafx.h"
//#include <stdio.h>
//#include <math.h>
//#include <conio.h>
//#include <ctime>

#include <cstdlib>
#include <iostream>
//#include <ctime>
//#include <math.h>

using namespace std;

int n=11;                                   		// размерность массива
int a[10];
int minimum;
int maximum;
int b;
void Vvod();
void Res();


int main()
{
    	Vvod();
    	Res();
}
void Vvod()
{
    	char  pust[100];
    	int scan;
    	FILE *fp;								// указатель на файл
    	fp=fopen("in.txt","r");				    	// открыть файл для чтения
                                            		// чтение из файла
    	for (int i=1; i<n; i++)
	    {
			fscanf(fp,"%d",&scan); 
			a[i]=scan;
		}

    	fclose(fp);							// закрыть файл для чтения
}
void Res()
{
	int minimum = a[1]; int nmin = 1;
	int maximum = a[1]; int nmax = 1;
    	FILE *fp;
    	fp=fopen("out.txt","w");		 			
fprintf(fp,"  Смена мест максимального и минимального элементов массива\n\n");
    	for (int i=1; i<n; i++) 
	{
    	if (minimum > a[i])
    	{
    	minimum = a[i];
    	nmin = i;
		}
		
		if (maximum < a[i])
		{
			maximum = a[i];
			nmax = i;
		}
}
       	//b = a[nmin];
		//a[nmax] = a[nmin]; 
		//a[nmax] = b;
		
     	b = a[nmax];
		a[nmax] = a[nmin]; 
		a[nmin] = b;
		
    	for (int i=1; i<n; i++) 
    	{
           fprintf(fp, "%d", a[i]);
       }
	//	fprintf(fp, "%d", minimum);
	//	fprintf(fp, "%3d\n\n", nmin);
	//	fprintf(fp, "%d", maximum);
	//	fprintf(fp, "%3d", nmax);
    	fclose(fp);	
}
