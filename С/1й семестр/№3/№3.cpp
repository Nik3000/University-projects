#include <cstdlib>
#include <iostream>
using namespace std;

int n=10;                                   		// размерность массива
int a[10];
int minimum;

void Vvod();
void Res();


int main()
{
    	Vvod();
    	Res();
}
void Vvod()
{
    	char  pust[100];
    	int scan;
    	FILE *fp;								// указатель на файл
    	fp=fopen("open3.txt","r");				    	// открыть файл для чтения
                                            		// чтение из файла
    	fscanf(fp,"%s",pust);
    	for (int i=0; i<n; i++)
	    {
			fscanf(fp,"%d",&scan); 
			a[i]=scan;
		}

    	fclose(fp);							// закрыть файл для чтения
}
void Res()
{
	int minimum = a[1];
    	FILE *fp;
    	fp=fopen("out.txt","w");		 			// открыть файл для записи
				                            	// запись в файл
    	fprintf(fp,"  Найти наименьший положительный элемент в массиве\n\n");
    	fprintf(fp,"  Исходный массив\n\n");
    	for (int i=0; i<n; i++) 
		fprintf(fp,"%4d",a[i]);
    	fprintf(fp,"\n\n  Наименьший положительный массив равен\n\n");
    	for (int i=0; i<n; i++)
    	{	
        if (a[i] > 0){
    	if (minimum > a[i])
    	{
    	minimum = a[i];
		}
    }
    	}
    	fprintf(fp,"%4d", minimum);	
    	fclose(fp);	
}
