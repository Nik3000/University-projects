package alexander.parfenov.lab5;

import java.util.Scanner;

public class Task6 {
    public static void main(String[] args) {
        Task5 S1 = new Task5();
        Scanner in = new Scanner(System.in);
        System.out.println("Введите текст");
        String str = in.nextLine();
        System.out.println("Введите номер, с которого начнется выделение");
        int num = in.nextInt();
        System.out.println("Введите количество символов, которые вы хотите выделить");
        int count = in.nextInt();
        System.out.print(S1.MySubstring(str, num, count));
    }
}