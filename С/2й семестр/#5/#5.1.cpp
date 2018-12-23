#include <stdio.h>
#include <math.h>
#include <ctime>
//#include "Graph.h"
#include "ReadImage.h"

using namespace std;

int n;
int		h,w; //size screen
char	*R,*G,*B; //colors
double a, b, c, d; //bourder graphic (down, up, left, right)
int *red, *green, *blue;
double *Bourder_lvl;
double z;

double f(double x, double y);
void Vvod();
void Draw();

int main()
{
	Vvod();
	GetSize("input.bmp", &h, &w);
	R = new char[h*w];
	G = new char[h*w];
	B = new char[h*w];
	red = new int[n];
	green = new int[n];
	blue = new int[n];
	ReadImageFromFile("input.bmp",B,G,R);
	Draw();
	WriteImage("output.bmp",B,G,R);
}

void Vvod()			//INPUT FIRST ELEMENT
{
	char pust[100];

	FILE *fp;
	fp=fopen("in.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&a);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&b);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&c);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&d);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&n);
	fscanf(fp,"%s",pust);
	Bourder_lvl = new double[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(fp,"%lf",&Bourder_lvl[i]);
	}
	fscanf(fp,"%s",pust);
	red = new int[n];
	green = new int[n];
	blue = new int[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(fp,"%d",&red[i]);
		fscanf(fp,"%d",&green[i]);
		fscanf(fp,"%d",&blue[i]);
	}
	fclose(fp);
	

}

void Draw()
{
	int i = 0;
	double hx = (b - a)/w;
	//printf("%15lf", hx);
	double hy = (d - c)/h;
	//printf("%15lf", hy);
	for (double y = c; y < d; y+=hy)
	{
	for (double x = a; x < b; x+=hx)
	{
		for(int j = 0; j < n - 1; j++)
		{
			double z = f(x, y);
			double zx = f(x - hx, y);
			double zy = f(x, y + hy);
			if (((Bourder_lvl[j] <= zx) && (zx <= Bourder_lvl[j+1])) != ((Bourder_lvl[j] <= z) && (z <= Bourder_lvl[j+1])) || ((Bourder_lvl[j] <= zy) && (zy <= Bourder_lvl[j+1])) != ((Bourder_lvl[j] <= z) && (z <= Bourder_lvl[j+1])))
			//if ((Bourder_lvl[j] < z) && (z < Bourder_lvl[j+1]))
			{
				R[i] = B[i] = G[i] = 0;
					//printf("%15d", blue[5]);
			}
		}
		i++;
	}
	}
	//	printf("%15d", blue[5]);
}

double f(double x, double y)
{
	return(x*x + y*y);
}
