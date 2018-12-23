#include <stdio.h>
#include <math.h>
#include <ctime>
//#include "Graph.h"

int N;
int eps = 0.000001;
double *a, *f, *c;
double a1;

void Read();
void Calculation();
void Write();
int main()
{
	Read();
	Calculation();
	Write();
}

void Read()
{
	char pust[100];

	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&N);
	fscanf(fp,"%s",pust);
	
	a = new double [N*N];
	for (int i = 1; i <= N*N; i++)
		fscanf(fp, "%lf", &a[i]);
	
	
	fscanf(fp,"%s",pust);
	f = new double [N];
	for (int i = 1; i <= N; i++)
		fscanf(fp, "%lf", &f[i]);

	fclose(fp);
}

void Calculation()
{
	//x = new double [N];
		//double a1 = f[k];
		//f[k] = f[index];
		//f[index] = a1;
		//for (int j = k-1; j < N; j++)
		//{
			//int a1 = a[j*N+k];
			//if (a[j*N+k] < eps) continue;
				////a1 = 1;
			////else
				////a1 = a[j*N+k];
				
			//for (int i = 1; i <= N; i++)
			//{
				//a[j*N+i] = a[j*N+i]/a1;
				////printf("%10lf", a[j*N+i]);
			//}
			
			//f[j+1] = f[j+1]/a1;
			
			//if (j == k) continue;
			//for (int i = 1; i <= N; i++)
			//{
				//a[j*N+i] = a[j*N+i] - a[k*N+i];
			//}
			//f[j+1] = f[j+1] - f[k];
		//}
	//k++;
	//}
	
	//for (int k = N - 1; k >=0; k--)
	//{
		//x[k] = f[k];
		//for (int i = 0; i < k; i++)
			//f[i] = f[i] - a[i*N+k] * x[k];
	//}
	
	
	//for (int i = 1; i <= N; i++)
	//printf("%10lf", x[i]);
	
	
	c = new double [N];

	
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				a1 = a[i*N+i];
				c[j] = -a[j*N+i]/a1; 
				a[j*N+k] = a[(j-1)*N+k] + c[j]*a[i*N+k];
				//printf("%15lf", c[j]);
			}
		}
	}

	//for (int i = 1; i < N; i++);
	//{
		//for (int j = 0; j < N; j++);
		//{
			//for (int k = 1; k <= N; k++);
			//{
				//apl = N*k;//(j+1)*N+k+1;
				//c[i] = (-a[j*N+i])/a[i*N+i];
				//a[(j+1)*N+k+1] = a[j*N+k] + c[j] * a[i*N+k];
			//}
		//}
	//}
}

void Write()
{
	//for (int i = 0; i <= 8; i++);
	//printf("%5lf", c[i]);
}
