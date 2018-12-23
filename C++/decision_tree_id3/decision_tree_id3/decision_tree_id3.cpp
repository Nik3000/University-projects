#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Программа пока больше как черновик. Если потребуется, могу доработать
//использование динамических массивов не эффективно, так как из-за особенностей языка С++, требуется изначально выделить динамическую память под него
//а затем заполнять. увеличивать же массив в каком-либо цикле по мере поступления не представляется возможным. разве что прогнать цикл для подсчета требуемой памяти
//потом выделить ее, а затем прогнать еще раз тот же самый цикл для заполнения данных уже в массив. если знаете как можно обойти этот гемор - буду рад.

double *arr;  //массив, содержащий в себе количество повторений для каждого атрибута
double *arr8;  //массив, содержащий в себе количество случаев, когда один атрибут равен другому. и так для каждого атрибута.
const int n = 4178;
const int m = 9;
//string *ftest = new string[n*m];  //можно перевести в динамический массив все string массивы
string test[m][n];
string copytest[m][n];
string search[m-1][5];
double E[m][n];
double G[m];
double numG[8];  //содержит номера атрибутов в порядке убывания Gain
string copyar[m][n];

void Read() //считывание из файла и запись в двумерный строковый массив данных. строки - атриуты, столцы - значения.
{
	string line;
	int p = 0;
	ifstream f("abalone.data.csv");
	for (int i = 0; i < n; i++)  //чтение и заполнение массива test всеми значениями атрибутов (обучающая выборка)
	{
		f >> line;
		int j = 0;
		for (int k = 0; k < line.size(); k++)
		{
			if (line[k] != ',')
			{
				test[j][i] += line[k];
				//ftest[p] += line[k];
			}
			else
			{
				j++;
				//p++;
			}
		}
		//p=j*8;
	}
	f.close();
	int l = 0;
	for (int i = n - 1; i >= 0; i--)  //выделение тестовой выборки
	{
		if (test[8][i] == "")
		{
			for (int p = 0; p < m - 1; p++)
			{
				search[p][l] = test[p][i];
				test[p][i] = "";
			}
			l++;
		}
		else
			break;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			copytest[i][j] = test[i][j];
}

double Entropy(int j)  //вычисление энтропии (используется правда только для подсчета энтропии искомого атрибута) не изменяя исходного массива
{
	int c = 1;
	int l = 0;
	string a[n];
	double s[n];
	for (int i = 0; i < n; i++)
		a[i] = test[j][i];
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != "")
		{
			for (int k = i + 1; k < n; k++)
			{
				if (a[i] == a[k])
				{
					c++;
					a[k] = "";
				}
			}
			s[l] = c;
			l++;
			c = 1;
		}
	}
	double E = 0;
	for (int i = 0; i < l; i++)
	{
		E += s[i] / n * (log(s[i] / n) / log(2));
	}
	return -E;
}

//Изначально хотел использовать функцию Entropy для подсчета энтропии для всех атрибутов, но после углубления в теорию, а именно подсчет Gain
//из-за нужды поиска количества случаев, когда n-й атрибут с определенным значением равняется 9му атрибуту со своим значением 
//пример 1 атрибут = M , 9й атрибут = 15 сколько раз такое встречается?  
//пришлось реализовать подсчет в функции Count
int Count(int j)//подсчет количества одинаковых значений каждого из атрибутов
{
	int cc = 1;
	int c = 1;  //счетчик количества одинаковых значений атрибута
	int l = 0;  //счетчик количества типов
	int ll = 0;
	string a8[n];

	for (int i = 0; i < n-1; i++)
	{
		if (test[j][i] != "")
		{
			a8[0] = test[m][i];
			for (int k = i+1; k < n; k++)
				if (test[j][i] == test[j][k])
				{
					a8[c] = test[8][k];  //запись значений из 8го атрибута при n-м атрибуте
					c++;
					test[j][k] = "";
				}
			//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-
			ll = 0;
			for (int ii = 0; ii < c; ii++)  //подсчет одинаковых значений 8-го атрибута при n-м атрибуте
			{
				if (a8[ii] != "")
				{
					for (int kk = ii + 1; kk < c+1; kk++)
					{
						if (a8[ii] == a8[kk])
						{
							cc++;
							a8[kk] = "";
						}
					}
					arr8[ll] = cc;
					ll++;
					cc = 1;
				}
			}
			//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-
			arr[l] = c;
			for (int ii = 0; ii < ll; ii++)  //вычисление общей энтропии для дальнейшего подсчета Gain
			{
				E[j][l] += -1*arr[l]/n * (arr8[ii] / arr[l] * log(arr8[ii] / arr[l]) / log(2));
			}
			//cout << E[j][l] << "\n";
			l++;
			c = 1;	
		}
	}
	return(l);
}

void Gain()
{
	double e8 = Entropy(8);
	for (int k = 0; k < 8; k++)
	{
		int l = Count(k);
		G[k] = e8;
		for (int i = 0; i < l; i++)
		{
			G[k] -= E[k][i];
		}
	}
}

void SortGain()
{
	double Gg[8];  //массив для копирования
	  
	for (int i = 0; i < 8; i++)  //скопируем массив Gain в новый
	{
		Gg[i] = G[i];
	}
	for (int j = 0; j < 8; j++)
	{
		double max = Gg[0];
		int n = 0;
		for (int i = 1; i < 8; i++)
			if (Gg[i] > max)
			{
				max = Gg[i];
				n = i;
			}
		numG[j] = n;
		Gg[n] = 0;
	}
}

//поиск значения атрибута по алгоритму id3. Только реализованный алгоритм не строит древо всевозможных решений, так как при большом количестве значений атрибутов
//древо получается слишком многозначным и работать с таким количеством ветвей не рационально. поэтому строятся ветви решений для каждого частного решения отдельно
//алгоритм выдаст предполагаемое значение, только если в базе найдется хотябы несколько значений каждого атрибута
void SearchAtr(int p)
{
	bool f = false;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			copyar[i][j] = copytest[i][j];
	int k;
	for (int i = 0; i < m-1; i++)
	{
		k = numG[i];
		for (int j = 0; j < n; j++)
		{
			if (search[k][p] != copyar[k][j])
				for (int l = 0; l < m; l++)
					copyar[l][j] = "";
			if (i == m - 2 && search[k][p] == copyar[k][j])
			{
				cout << copyar[m - 1][j] << "\n";
				f = true;
			}
		}
	}
	if (f == false)
		cout << "unable to determine value of sought attribute" << "\n";
}

int main()
{
	arr = (double*)malloc(n * sizeof(double));
	arr8 = (double*)malloc(n * sizeof(double));
	Read();
	Gain();
	//for (int i = 0; i < 8; i++)
		//cout << G[i] << "\n";
	SortGain();
	/*for (int i = 0; i < 8; i++)
		cout << numG[i] << "\n";*/
    //тестовые выборки были выбраны таким образом, что значение аргумента с самым большим значением Gain встречается в обучающих выборках минимум 5 раз
	//однако базы обучающих выборок все равно мало для определения значения искомого аргумента
	for(int i = 0; i < 5; i++)
		SearchAtr(i);
	//getchar();
}

