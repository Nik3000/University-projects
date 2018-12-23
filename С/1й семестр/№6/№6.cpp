#include <stdio.h> 
#include <math.h>
#include <ctime>

int n = 11;
int a[10][10];
int p;
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
 	FILE *fp;								
	fp=fopen("in.txt","r");	
	  //    int n = scan;
		  for (int m = 1; m<n; m++)
		  {
		    for (int i = 1; i<n; i++)
		      {
	            fscanf(fp,"%d",&a[m][i]);
	          }
	      }
    fclose(fp);
}
void Res()
{
   int tmp;
   for (int i=1; i<n; i++)
   {
     tmp = a[i][i];
	 a[i][i] = a[i][n-i];
 	 a[i][n-i] = tmp;
   }
     
}


void Vivod()
{
    FILE *fp;
	fp=fopen("out.txt","w");
	fprintf(fp,"  New Massive \n\n");

    for (int m=1; m<n; m++) 
      {
		  for (int i = 1; i<n; i++)
		  {
	        fprintf(fp,"%5d", a[m][i]);
	      }
	      fprintf(fp, "  \n\n");
      }
	fprintf(fp,"%3d", n);
	fclose(fp);
}	
