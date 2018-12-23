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
	FILE *fp;								// указатель на файл
	fp=fopen("Chislo.txt","r");					// открыть файл для чтения
										// чтение из файла
	fscanf(fp,"%d",&n);

	fclose(fp);							// закрыть файл для чтения
}
void Vyvod()
{
	FILE *fp;
	fp=fopen("Otvet.txt","w");		 			// открыть файл для записи
	// запись в файл
	if (s == 0)
	fprintf(fp, "Дульцев Никита Алексеевич");
	else
	fprintf(fp, "07/11/1998");
	fclose(fp);
}

void Res()
{
	s = n % 5;
}
