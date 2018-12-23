#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "ReadImage.h"

class RWImage
{
public:
	BITMAPFILEHEADER bmpfh;
	BITMAPINFOHEADER bmpih;
	char *B, *G, *R;
	int h, w;

	void WriteImage(char* name)
	{
	FILE *file = fopen(name, "wb");

	fwrite(&bmpfh, sizeof(BITMAPFILEHEADER), 1, file);
	fwrite(&bmpih, sizeof(BITMAPINFOHEADER), 1, file);

	for (int i = 0; i<bmpih.biHeight; i++)
	{
		for (int j = 0; j<bmpih.biWidth; j++)
		{
			fwrite(B + i*bmpih.biWidth + j, 1, 1, file);
			fwrite(G + i*bmpih.biWidth + j, 1, 1, file);
			fwrite(R + i*bmpih.biWidth + j, 1, 1, file);
		}
		for (int k = 3 * bmpih.biWidth % 4; k != 0; k = (k + 1) % 4)
		{
			char ctemp = 0;
			fwrite(&ctemp, 1, 1, file);
		}
	}
	if (ftell(file)<bmpfh.bfSize)
	{
		printf("%d\n", bmpfh.bfSize - ftell(file));
		char ctemp = 0;
		for (int counter = bmpfh.bfSize - ftell(file); counter>0; counter--) fwrite(&ctemp, 1, 1, file);
	}

	fclose(file);
}
	RWImage(char* name)
	{
		ReadImageFromFile(name);
	}
	~RWImage()
	{
		delete[]B; delete[]G; delete[]R;
	}
private:
	void GetSize(char* name, int* h, int* w)
	{
		FILE *file = fopen(name, "rb");
		fread(&bmpfh, sizeof(BITMAPFILEHEADER), 1, file);
		fread(&bmpih, sizeof(BITMAPINFOHEADER), 1, file);
		*h = bmpih.biHeight;
		*w = bmpih.biWidth;
		fclose(file);
	}
	void ReadImageFromFile(char* name)
	{
		int h, w;
		GetSize("test.bmp", &h, &w);
		B = new char[h*w];
		G = new char[h*w];
		R = new char[h*w];
		FILE *file = fopen(name, "rb");

		fread(&bmpfh, sizeof(BITMAPFILEHEADER), 1, file);
		
		fread(&bmpih, sizeof(BITMAPINFOHEADER), 1, file);
	
		fseek(file, bmpfh.bfOffBits, SEEK_SET);

		for (int i = 0; i<bmpih.biHeight; i++)
		{
			for (int j = 0; j<bmpih.biWidth; j++)
			{
				fread(B + i*bmpih.biWidth + j, 1, 1, file);
				fread(G + i*bmpih.biWidth + j, 1, 1, file);
				fread(R + i*bmpih.biWidth + j, 1, 1, file);
			}
			for (int k = 3 * bmpih.biWidth % 4; k != 0; k = (k + 1) % 4)
			{
				char ctemp = 0;
				fread(&ctemp, 1, 1, file);
			}
		}
		fclose(file);
	}
};

void main()
{
	int h, w;
	RWImage rwi("test.bmp");
	rwi.WriteImage("out.bmp");
}
