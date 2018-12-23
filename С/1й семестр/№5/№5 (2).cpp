#include <cstdlib>
#include <stdio.h> 
#include <math.h>
#include <ctime>

float eps;
int x[10];
float kvX;
float mainX=kvX;
int factorial=2;
float countFactorial =2;
float lastValue=0;
float mainValue=1;

void Vvod();
void Res();


int main()
{
	Vvod();
	Res();

}

void Vvod()
{
	char pust[100];
	FILE *fp;
    fp=fopen("in.txt","r");
    fscanf(fp,"%s",pust);
    fscanf(fp,"%f",&eps);
    fscanf(fp,"%s",pust);
    for (int i = 1; i <= 10; i++)
    {
		fscanf(fp,"%d",&x[i]);
	}
	fclose(fp);
	printf ("%5dd", x);
}

void Res()
{
	FILE *fp;
	fp=fopen("out2.txt","w");
	fprintf(fp,"libMath         myCulculation     разность\n");
	for (int i = 1; i<=10; i++)
	{
	
		kvX=x[i]*x[i];
		mainX=kvX;
		factorial=2;
		countFactorial =2;
		lastValue=0;
		mainValue=1; 
		
		while (fabs(lastValue-mainValue) > eps)
		{
		  lastValue=mainValue;
		  //----------Считает ch(x)
		  mainValue += mainX/factorial;
		  
		  
		  //----------Считаем степени Х x^2 x^4  x^6...
		  mainX*=kvX;
		  
		  //----------Подсчитывает факториал 2! 4! 6! ...
		  countFactorial++;
		  factorial*=countFactorial;
		  
		  //countFactorial++;
		  //factorial*=countFactorial;
		  
		};
		
	
	
		fprintf(fp,"%f  ", cosh(x[i]));
		
		fprintf(fp,"%f  ",  mainValue);
		
		fprintf(fp,"%f  \n",  fabs(mainValue-cosh(x[i])));
		
	
	
	
    };	
	fclose(fp);
}


