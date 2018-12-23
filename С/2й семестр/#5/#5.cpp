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
//void Draw();
void AntiDraw();

int main()
{
	Vvod();
	GetSize("input2.bmp", &h, &w);
	R = new char[h*w];
	G = new char[h*w];
	B = new char[h*w];
	red = new int[n];
	green = new int[n];
	blue = new int[n];
	ReadImageFromFile("input2.bmp",B,G,R);
	AntiDraw();
	//Draw();
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

void AntiDraw()
{
	
	//for (int y=h/2;y<h;y++)
	//for (int x=0;x<w;x++)
		//{
			//if ((R[y*w+x] > 0) || (G[y*w+x] > 0) || (B[y*w+x] > 0))
				//{
					//R[y*w+x] = G[y*w+x] = B[y*w+x] = 255;
				//}
			//else if ((R[y*w+x] = 0) && (G[y*w+x] = 0) && (B[y*w+x] = 0))
				//{
					//R[y*w+x] = G[y*w+x] = B[y*w+x] = 0;
				//}
		//}
	int i = 0;
	for (int y = 0; y < h; y++)
	for (int x = 0; x < w; x++)
		{
			if ((R[i] > 0) || (G[i] > 0) || (B[i] > 0))
				{
					R[i] = 255;
					G[i] = 255;
					B[i] = 255;
				}
			//else if ((R[i] = 0) && (G[i] = 0) && (B[i] = 0))
				//{
					//R[y*w+x] = G[y*w+x] = B[y*w+x] = 0;
				//}
			i++;
		}
	
}

