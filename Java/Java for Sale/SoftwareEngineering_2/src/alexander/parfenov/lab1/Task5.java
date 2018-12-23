package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите год поступления");
        int year1 = in.nextInt();
        System.out.println("Введите текущий месяц");
        int mouth = in.nextInt();
        System.out.println("Введите текущий год");
        int year2 = in.nextInt();
        boolean flag = mouth <= 6;
        int a=year2-year1-Boolean.compare(flag,false);
        boolean flag2 = a >= 4;
        System.out.print(flag2);
    }
}
