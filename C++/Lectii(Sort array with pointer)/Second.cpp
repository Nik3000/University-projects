#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <malloc.h>

const unsigned int n = 15;
double a[n] = {5, 6, 9, 8, 3, 7, 10, 5, 33, 11, 0, -69, 48, 0.3, 64};
void Read();

double *minArray(double *start, double *fin)
  {double *pmin;
   for(pmin = start++; start <= fin; start++)
     if(*pmin > *start)
       pmin = start;
   return pmin;
  }

double *sortArray(double *fst, double *lst)
{
    if(fst >= lst) return NULL;
    double *pmin;
    double temp;
    for(; fst < lst; fst++)
    {
        pmin = minArray(fst,lst);
        temp = *pmin;
        *pmin = *fst;
        *fst = temp;
    }
    return NULL;
}

int main()
{
    //cout << "Enter array size \n";
    //cin >> n;
    //a = (double*)malloc(n*sizeof(double));
    //Read();
    cout << "initial Array" << "\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << "\n";

    sortArray(a, a + n-1);

    cout << "Sort array" << "\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << "\n";
    getchar();
}

void Read()
{
    cout << "Enter elements of the array\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

