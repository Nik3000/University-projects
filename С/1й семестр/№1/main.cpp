#include <cstdlib>
#include <stdio.h>


int n,s;
void Vvod();
void Res();
void Vyvod();

int main()
{
    Vvod();
    Res ();
    Vyvod();
    }
void Vvod()
{
     
	char pust[100];
	int scan;
	FILE *fp;								// ��������� �� ����
	fp=fopen("Chislo.txt","r");					// ������� ���� ��� ������
										// ������ �� �����
	fscanf(fp,"%d",&n);

	fclose(fp);							// ������� ���� ��� ������
}
void Vyvod()
{
	FILE *fp;
	fp=fopen("Otvet.txt","w");		 			// ������� ���� ��� ������
	// ������ � ����
	if (s == 0)
	fprintf(fp, "������� ������ ����������");
	else
	fprintf(fp, "07/11/1998");
	fclose(fp);
}

void Res()
{
	s = n % 5;
}
