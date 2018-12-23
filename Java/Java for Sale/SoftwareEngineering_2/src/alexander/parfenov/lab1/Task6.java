package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите вес в граммах");
        int weight = in.nextInt();
        System.out.println("Введите рост в сантиметрах");
        int growth = in.nextInt();
        boolean flag = (weight/growth >= 350)&(weight/growth <= 400);
        System.out.print(flag);
    }
}
