#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "ReadImage.h"
#include <math.h>

using namespace std;

int		h,w;
char		*R,*G,*B;


int x,y;
//---------------------------------------------------------------------------------------
int main()
{
	GetSize("input2.bmp", &h, &w);				// читаем размеры файла в пикселях
											// (w -- ширина, h -- высота)
	R = new char[h*w];
	G = new char[h*w];
	B = new char[h*w];
	ReadImageFromFile("input2.bmp",B,G,R);			// считываем значения цветовых составляющих изображения:
											// R -- красной, G -- зеленой, B -- синей
	
	
	for (int y=h/2;y<h;y++)
	for (int x=0;x<w;x++)
		{
			int r=R[y*w+x];
			if (r<0)r+=256;
			R[y*w+x]=0;
			
			//int g=G[y*w+x];
			//if (g<0) g+=256;
			//G[y*w+x]=g/2;
		}
		
		WriteImage("output.bmp",B,G,R);				// создаем bmp-файл и записываем в него полученное "изображение"
}
