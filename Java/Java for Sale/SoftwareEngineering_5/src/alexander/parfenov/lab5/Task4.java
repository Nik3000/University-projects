package alexander.parfenov.lab5;

import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Для создания квадратной матрицы введите ее размерность");
        Task3 A1 = new Task3();
        A1.n = in.nextInt();
        int[][] rmatr = A1.Array();

        int sMax;
        int iMax = 0;
        int sMin;
        int iMin = 0;
        int sum = 0;
        for (int j = 0; j < A1.n; j++)  //присвоим максимуму и минимуму значение суммы элементов первой строки
            sum += rmatr[0][j];
        sMax = sMin = sum;

        for(int i = 1; i < A1.n; i++) {
            sum = 0;
            for (int j = 0; j < A1.n; j++)
                sum += rmatr[i][j];
            if (sMax < sum) {
                sMax = sum;
                iMax = i;
            }
            if (sMin > sum) {
                sMin = sum;
                iMin = i;
            }
        }
        System.out.println("Полученная матрица");
        for(int i = 0; i < A1.n; i++) {
            System.out.print("\n");
            for (int j = 0; j < A1.n; j++)
                System.out.print(rmatr[i][j] + " ");
        }
        System.out.println("\n\nМаксимальная сумма = "+sMax);
        for(int i = 0; i < A1.n; i++)
            System.out.print(rmatr[iMax][i]+" ");
        System.out.println("\n\nМинимальная сумма = "+sMin);
        for(int i = 0; i < A1.n; i++)
            System.out.print(rmatr[iMin][i]+" ");
    }
}

//Работа с рандомным массивом по заданию из 5го варианта