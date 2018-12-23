#include <stdio.h>
#include <math.h>
#include <ctime>
#include "Graph.h"

double a, b; //bourder
double eps;
double c; //half
double answ;
double xk;
double x0;
double x1;

int counter_Diho = 0;
int counter_Sec = 0;

double f(double x);

void Read();
void Diho();
void Sec();
void Write();
void Draw();

int main()
{
	Read();
	Draw();
	Diho();
	Sec();
	Write();
	printf("%5lf", answ);
	printf("%25lf\n\n", xk);
	printf("%5d", counter_Diho);
	printf("%25d\n\n", counter_Sec);
	printf("%5lf", f(answ));
	printf("%25lf", f(xk));
	
}

void Read()
{
	char pust[100];

	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&a);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&b);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&eps);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&x0);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&x1);
	fclose(fp);
}

void Diho()
{
	while (fabs(b - a) >= eps)
	{
		c = (b + a)/2;
		if (f(c) > 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
		counter_Diho++;
	}
	
	answ = (a + b)/2;
}

void Sec() //проверку, количество операций, графически для метода секущей
{
	xk = x1;
	double xkm1 = x0;
	double xkp1 = 0;

	SetColor(200,0,0);
	while (fabs (f(xk)) >= eps)
	{
		xkp1 = xk - ((xk - xkm1)/(f(xk) - f(xkm1))) * f(xk);
		counter_Sec++;
		
		SetPoint(xkm1, f(xkm1));
		Line (xkp1, 0);
		SetPoint(xkm1,0);
		Line(xkm1,f(xkm1));
		xkm1 = xk;
		xk = xkp1;
	}
	
	CloseWindow();
}

void Write()
{
	FILE *fp;
	fp=fopen("out.txt","w");
	fprintf(fp,"  Diho          Counter of operations          Eps\n\n");
	fprintf(fp,"%10lf", answ);
	fprintf(fp,"%17d", counter_Diho);
	fprintf(fp,"%25lf", f(answ));
	fprintf(fp,"\n\n  Secant        Counter of operations          Eps\n\n");
	fprintf(fp,"%10lf", xk);
	fprintf(fp,"%17d", counter_Sec);
	fprintf(fp,"%25lf", f(xk));
	fclose(fp);
}

void Draw()
{
	SetColor(250,250,250);
	SetWindow(0.6,1.1,-0.3,1); //координатые линии от x1 до x2 и от y1 до y2
	SetColor(0,0,0);
	xyLine(0.6,0,0.1,0.1);  //шаг
	
	SetColor(0,200,0);
	double step=(b-a)/200;
	double x=a;
	SetPoint(x,f(x));
	for (int i=0; i<200; i++)
	{ 
		x+=step;
		Line2(x,f(x));
	}
	
	//SetColor(200,0,0);
	//double step2=(b-a)/5;
	////double x=a;
	//SetPoint(xk,0);
	//for (int i=0; i<5; i++)
	//{ 
		//x+=step2;
		//Line(xk,f(xk));
	//}
	CloseWindow();
}

double f(double x)
{
	return 1/x;
	//return (sin(x) + pow(x,7) - 1);
}
