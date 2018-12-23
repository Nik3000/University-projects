package alexander.parfenov.lab2;

import java.util.Scanner;

public class Task9 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Вводите числа через 'Enter'");
        System.out.println("Для завершения, введите 'n'");
        String number = "0";
        double s = 0;
        int n = -1;
        while (number.equalsIgnoreCase("n") == false) {
            s += Double.valueOf(number);
            n++;
            number = in.next();
        }
        System.out.print("Среднее арифметическое всех чисел = "+s/n);
    }
}
