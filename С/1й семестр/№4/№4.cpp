#include <cstdlib>
#include <stdio.h> 
#include <math.h>
#include <ctime>

int d = 0;
int n = 1000;
int x[1000];
int y[1000];
int z[1000];
int k, k2, xi, yi, zi;
int Time, Time2;
//void Vivod();
void Res1();
void Res2();
void Generation(int n);
//(x*x)+y+2*z=100000
//x+y+20*z<1000

int main()
{
    Generation(n);
	Res1();
	Res2();
	//Vivod();
}

void Generation(int n)
{
	int xi = 1;
	int yi = 1;
	int zi = 1;
    	for (int i=0;i<n;i++)
    	{
        	x[i]=xi+x[i-1];
        	y[i]=yi+y[i-1];
        	z[i]=zi+z[i-1];
        }
}

void Res1()
{}
void Res2()
{
	int k2 = 0;
	for(int i = 0; i < n; i++)
		{
			for(int q = 0; q < n - i; q++)
				{
					for(int u = 0; u < ((n - i-q)/20); u++)
						{
							if (i*i + q + 2*u==100000)
								{
									k2 += 1;
								}
						}
				}
		}
		FILE *fp;
	fp=fopen("out.txt","w");
	fprintf(fp,"  Kolichestvo \n\n");
	fprintf(fp,"%25d", k2);
	fclose(fp);
}
