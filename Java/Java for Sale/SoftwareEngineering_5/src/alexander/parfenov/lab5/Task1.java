package alexander.parfenov.lab5;

import java.util.Scanner;

public class Task1 {
    private int[][] array;
    public int n;
    public int[][] Array() {
        array = new int [n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n - i; j++)
                array[i][j] = j + i + 1;
         return array;
    }
}

//Создание массива по образцу из 5го варианта