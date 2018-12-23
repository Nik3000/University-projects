#include <stdio.h> 
#include <math.h>
#include <ctime>
using namespace std;

int n = 16000000;                                   		// размерность массива
int a[16000000];
double eps;
int b[16000000];
int ai;
int bi;
int sum;
int proiz;
double Sumcos;
int timeSum,timeSumP,timeSumcos, timeO;



void Res();
void Generation(int n);

int main()
{
     	Generation(n);
    	Res();
}



void Generation(int n)
{
	int ai = 1;
	int bi = 2;

    	for (int i=0;i<n;i++)
    	{
        	a[i]=ai;
        	b[i]=bi;
            	}
    	
}

void Res()
{
	clock_t	timeBegin,timeEnd;
timeBegin = clock();	
    	FILE *fp;
    	fp=fopen("out.txt","w");	// открыть файл для записи
		
		fprintf(fp,"      Sum A + B     Time\n\n");	 
	      timeBegin = clock();
			    for (int i=0; i<n; i++)  
			   sum+=a[i] + b[i];
	      timeEnd = clock();
		  timeSum=timeEnd-timeBegin;
				fprintf(fp,"%15d",sum);
				fprintf (fp, "%10d", timeSum);
	
	      fprintf(fp,"\n\n      Sum A * B\n\n");
		timeBegin = clock();
				for (int i=0; i<n; i++) 
				proiz+=a[i] * b[i];
		timeEnd = clock();
		timeSumP=timeEnd-timeBegin;		
				fprintf(fp,"%15d",proiz); 
				fprintf (fp, "%10d", timeSumP);  
			    
		fprintf(fp,"\n\nSum cos (A * b)\n\n");
		
		timeBegin = clock();
				for (int i=0; i<n; i++)  
				Sumcos+=cos(a[i] * b[i]);
		timeEnd = clock();
		timeSumcos=timeEnd-timeBegin;		
				fprintf(fp,"%15lf",Sumcos); 
				fprintf (fp, "%10d", timeSumcos);
		fclose(fp);
timeEnd=clock();
timeO = timeEnd - timeBegin;
		printf ("%10d%10d%10d%10d", timeSum, timeSumP, timeSumcos, timeO);		  
}
