#include <cstdlib>
#include <stdio.h> 
#include <math.h>
#include <ctime>

float ch;
float lastch;
float coh;
int eps;
int n;
float kv;
float fac;
float cfac;
int x;

void Vvod();
void Res();
void Vivod();

int main()
{
	Vvod();
	Res();
	Vivod();
}

void Vvod()
{
	char pust[100];
	FILE *fp;
    fp=fopen("in.txt","r");
    fscanf(fp,"%s",pust);
    fscanf(fp,"%d",&eps);
    fscanf(fp,"%s",pust);
    //for (int i = 1; i <= 10; i++)
    //{
		fscanf(fp,"%d",&x);
	//}
}

void Res()
{
	ch = 1;
	lastch = 0;
	fac = 2;
	cfac = 2;
	while (fabs(lastch - ch) > eps)
	 {
		lastch = ch;
		ch += kv/cfac;
		kv *= x*x;
		fac +=2;
		cfac += fac;
		
	
	}
	printf ("%5lf", ch);
	
}

void Vivod()
{
	FILE *fp;
	fp=fopen("out.txt","w");
	for(int i=1; i<=10;i++)
	{
		fprintf(fp,"  ch \n\n");
		fprintf(fp,"%15lf\n\n", ch[i]);
		fprintf(fp,"  cosh \n\n");
		fprintf(fp,"%15lf\n\n", coh[i]);
		// fprintf(fp,"  погрешность \n\n");
		//fprintf(fp,"%15lf\n\n", s[i]);
	}
	fclose(fp);
}
