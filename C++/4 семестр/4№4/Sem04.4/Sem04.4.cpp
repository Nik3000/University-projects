#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

template <typename T>
int mean_word_lenght (T& z)
{
	char w = {'п'};
	//fprintf(pf, "Mean Word Length \n\n");
	char array[] = { 'ц', 'к', 'н', 'г', 'ш', 'щ', 'з', 'х', 'в', 'п', 'р', 'л', 'д', 'ж', 'ч', 'с', 'б', 'т', 'м'};
	//k++;
	k = 1;
	for (int i = 0; i < 19; i++)
	{
		if (z == array[i])
		{
			k = 0;
			break;
		}
	}
	if (k == 1)
	{
		w = z;
		printf("%c", w);
	}
	//getchar();
	/*if ((z == 32) || (z == 10) || (z == -1))
		{
			s = s + k - 1;
			k = 0;
			c++;
		}
		*/
	return w;
}



int c = 0;
int w = 1;
char z;
int k = 0;
int s = 0;
int r;

int main()
{
	setlocale(LC_ALL, "rus");
	FILE *fp;
	fp = fopen("in.txt", "r");

	FILE *pf;
	pf = fopen("out.txt", "w");

	while (w != 0)
	{
		fscanf(fp, "%c", &z);
		//z = fgetc(fp);
		if (mean_word_lenght(z) == 'п');

			//mean_word_lenght(z);
		else fprintf(pf, "%c", z);//mean_word_lenght(z));
		if (z == '!')
			w = 0;
	}

	fclose(pf);

	fclose(fp);
	/*
	FILE *pf;
	pf = fopen("out.txt", "w");
	fprintf(pf, "Mean Word Length \n\n");
	fprintf(pf,"%8d\n\n", s/c);
	fclose(pf);
	*/
	getchar();
    return 0;
}

