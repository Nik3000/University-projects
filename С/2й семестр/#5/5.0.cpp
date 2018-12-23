#include <stdio.h>
#include <math.h>
#include <ctime>
//#include "Graph.h"
#include "ReadImage.h"

using namespace std;

int n;
int		h,w; //size screen
char	*R,*G,*B; //colors
int *red, *green, *blue;

void Draw();

int main()
{
	GetSize("input3.bmp", &h, &w);
	R = new char[h*w];
	G = new char[h*w];
	B = new char[h*w];
	red = new int[n];
	green = new int[n];
	blue = new int[n];
	ReadImageFromFile("input3.bmp",B,G,R);
	Draw();
	WriteImage("output.bmp",B,G,R);
}

void Draw()
{
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
			i++;
		}
}
