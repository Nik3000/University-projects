#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct book
{
	int num;
	char word[50];
};


int main()
{
	setlocale(LC_ALL, "rus");
	book first;
	int z;
	//char pust;
	FILE *fp;
	fp = fopen("in.txt", "r");
	//for (int i = 0; i < 5; i++)
	//{
		//fscanf(fp, "%d", &first.num);
		fscanf(fp, "%c", &first.word[]);
		//printf("%5d", first.num);
		printf("%5c", first.word[]);
	//}
	//fscanf(fp, "%d", &book.word);
	/*while (w != 0)
	{
		z = fgetc(fp);
		if ((z == 32) || (z == 10) || (z == -1))
		{
			s = s + k - 1;
			k = 0;
			c++;
		}
		if (z == EOF)
			w = 0;
	}*/
	fclose(fp);
	getchar();
    return 0;
}

