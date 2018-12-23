package alexander.parfenov.lab5;

import java.lang.reflect.Array;
import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Для создания квадратной матрицы введите ее размерность");
        Task1 A1 = new Task1();
        A1.n = in.nextInt();
        int[][] ar = A1.Array();
        System.out.println("Полученная матрица");
        for(int i = 0; i < A1.n; i++) {
            System.out.print("\n");
            for (int j = 0; j < A1.n; j++)
                System.out.print(ar[i][j] + " ");
        }
    }
}

//Вывод матрицы