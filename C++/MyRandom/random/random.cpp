#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include <locale.h>

const int n = 10000;

int myrandom[n];
int sysrandom[n];

int array0[15];
int array[24][3][3][3][3][3][3][3][3][3];
int t;
int k;
int b;
int c;
int i;
int i1 = 1;
int i2 = 1;
int i3 = 1;
int i4 = 1;
int i5 = 1;
int i6 = 1;
int i7 = 1;
int i8 = 1;
int i9 = 1;

void VS();
void piece();
int random();
int main()
{
	setlocale(LC_ALL, "rus");
	//piece();
	for (int z = 0; z < 1; z++)
		VS();
	getchar();
    return 0;
}

int random()
{
		t = time(NULL);
		clock_t b;
		b = clock();
		t = t*b;
		//t = t % 90;
		//t = abs(t);
		return (t);
}


void VS()
{
	int c = 0;
	int b = 0;
	int k = 0;
		for (i = 1; i <= n; i++)
			myrandom[i] = abs((random()*i + i) % n);
		for (i = 1; i <= n; i++)
			sysrandom[i] = rand() % n;

		/*
		for (i = 1; i <= n; i++)
			printf("%5d", myrandom[i]);
		printf("\n\n");
		for (i = 1; i <= n; i++)
			printf("%5d", sysrandom[i]);
		printf("\n\n");
		*/

		int f1 = 0;
		int f2 = 0;
		int f3 = 0;
		int f4 = 0;
		int f5 = 0;
		for (int i = 0; i < n; i++)
		{
			if (myrandom[i] >= 0 && myrandom[i] <= n / 5)
				f1++;
			if (myrandom[i] >= n / 5 + 1 && myrandom[i] <= 2 * n / 5)
				f2++;
			if (myrandom[i] >= 2 * n / 5 + 1 && myrandom[i] <= 3 * n / 5)
				f3++;
			if (myrandom[i] >= 3 * n / 5 + 1 && myrandom[i] <= 4 * n / 5)
				f4++;
			if (myrandom[i] >= 4 * n / 5 + 1 && myrandom[i] <= n)
				f5++;
		}
		printf("Распределение элементов в моем рандоме \n");
		printf("%5d%5d%5d%5d%5d\n\n", f1, f2, f3, f4, f5);

		printf("\n");

		int p1 = 0;
		int p2 = 0;
		int p3 = 0;
		int p4 = 0;
		int p5 = 0;
		for (int i = 0; i < n; i++)
		{
			if (sysrandom[i] >= 0 && sysrandom[i] <= n/5)
				p1++;
			if (sysrandom[i] >= n/5+1 && sysrandom[i] <= 2*n/5)
				p2++;
			if (sysrandom[i] >= 2*n/5+1 && sysrandom[i] <= 3*n/5)
				p3++;
			if (sysrandom[i] >= 3*n/5+1 && sysrandom[i] <= 4*n/5)
				p4++;
			if (sysrandom[i] >= 4*n/5+1 && sysrandom[i] <= n)
				p5++;
		}
		printf("Распределение элементов в системном рандоме \n");
		printf("%5d%5d%5d%5d%5d\n\n", p1, p2, p3, p4, p5);

		for (int i = 0; i < n; i++)
		{
			k = 1;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
					if (myrandom[i] == myrandom[j])
					{
						k = 0;
						break;
					}

			}
			if (k == 1)
				c++;
		}

		for (int i = 0; i < n; i++)
		{
			k = 1;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
					if (sysrandom[i] == sysrandom[j])
					{
						k = 0;
						break;
					}

			}
			if (k == 1)
				b++;
		}
		printf("\n Количество повторений в моем рандоме \n");
		printf("%5d\n", n - c);
		printf("\n Количество повторений в системном рандоме \n");
		printf("%5d\n", n - b);
		//getchar();
}


void piece()
{
	
	for (int k = 1; k <= 1; k++)
	{
		for (i = 1; i <= 15; i++)
		{
			c = abs(random()*i % 90 + 1);
			for (int j = 1; j <= i; j++)
				if ((c == 0) || (c == array0[j]))
				{
					c = abs(random()*j % 90);
				}
			array0[i] = c;
			if ((array0[i] > 0) && (array0[i] < 10))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i1++;
			}
			if ((array0[i] > 9) && (array0[i] < 20))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i2++;
			}
			if ((array0[i] > 19) && (array0[i] < 30))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i3++;
			}
			if ((array0[i] > 29) && (array0[i] < 40))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i4++;
			}
			if ((array0[i] > 39) && (array0[i] < 50))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i5++;
			}
			if ((array0[i] > 49) && (array0[i] < 60))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i6++;
			}
			if ((array0[i] > 59) && (array0[i] < 70))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i7++;
			}
			if ((array0[i] > 69) && (array0[i] < 80))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i8++;
			}
			if ((array0[i] > 79) && (array0[i] < 91))
			{
				array[k][i1][i2][i3][i4][i5][i6][i7][i8][i9] = array0[i];
				i9++;
			}
		}
	}
	i = 1;
	for(i1=1; i1<=3; i1++)
		for(i2=1; i2<=3; i2++)
	printf("%d", array[1][i1][i2][i][i][i][i][i][i][i]);
	getchar();
	
	/*
	int c = random()*15;
	printf("%d", c);
	getchar();
	*/
	/*
	for (int i = 1; i <= 15; i++)
	{
		random();
		array[i] = t;
	}
	*/
}