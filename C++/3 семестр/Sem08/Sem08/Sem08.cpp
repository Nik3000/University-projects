#include <stdio.h>
#include <iostream>
#include <fstream>
#include "stdafx.h"

using namespace std;

struct Complex //комплексные числа
{
	double x, y;
};
ostream& operator<<(ostream& s, const Complex& c)
{
	s << c.x << "+" << c.y << "i";
	return s;
}

istream& operator>>(istream& s, Complex& c)
{
	s >> c.x >> c.y;
	return s;
}
const Complex operator+(const Complex& l, const Complex& r) //перегрузка оператора умножить
{
	Complex res;
	res.x = l.x + r.x;
	res.y = l.y + r.y;
	return res;
}
const Complex operator-(const Complex& l, const Complex& r) //перегрузка оператора умножить
{
	Complex res;
	res.x = l.x - r.x;
	res.y = l.y - r.y;
	return res;
}
const Complex operator*(const Complex& l, const Complex& r) //перегрузка оператора умножить
{
	Complex res;
	res.x = l.x*r.x - l.y*r.y;
	res.y = l.x*r.y + l.y*r.x;
	return res;
}
const Complex operator/(const Complex& l, const Complex& r) //перегрузка оператора умножить
{
	Complex res;
	res.x = (l.x*r.x + l.y*r.y) / ((r.x)*(r.x) + (r.y)*(r.y));
	res.y = (r.x*l.y - r.y*l.x) / ((r.x)*(r.x) + (r.y)*(r.y));
	return res;
}

int main()
{
	Complex C1, C2, multi, plus, sub, div;
	ifstream kot("in.txt");
	if (!kot.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	kot >> C1;
	kot >> C2;
	kot.close();

	plus = C1 + C2;
	sub = C1 - C2;
	multi = C1*C2;
	div = C1 / C2;

	ofstream put("Output.txt");
	put << plus << endl;
	put << sub << endl;
	put << multi << endl;
	put << div;
	put.close();
	system("pause");
}