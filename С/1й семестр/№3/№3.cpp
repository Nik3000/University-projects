#include <cstdlib>
#include <iostream>
using namespace std;

int n=10;                                   		// ����������� �������
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
    	FILE *fp;								// ��������� �� ����
    	fp=fopen("open3.txt","r");				    	// ������� ���� ��� ������
                                            		// ������ �� �����
    	fscanf(fp,"%s",pust);
    	for (int i=0; i<n; i++)
	    {
			fscanf(fp,"%d",&scan); 
			a[i]=scan;
		}

    	fclose(fp);							// ������� ���� ��� ������
}
void Res()
{
	int minimum = a[1];
    	FILE *fp;
    	fp=fopen("out.txt","w");		 			// ������� ���� ��� ������
				                            	// ������ � ����
    	fprintf(fp,"  ����� ���������� ������������� ������� � �������\n\n");
    	fprintf(fp,"  �������� ������\n\n");
    	for (int i=0; i<n; i++) 
		fprintf(fp,"%4d",a[i]);
    	fprintf(fp,"\n\n  ���������� ������������� ������ �����\n\n");
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
