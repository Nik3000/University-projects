package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task7 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите год");
        int year = in.nextInt();
        boolean flag = year % 4 == 0;
        System.out.print(flag);
    }
}
