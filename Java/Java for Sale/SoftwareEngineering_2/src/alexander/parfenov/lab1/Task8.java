package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите число");
        int x = in.nextInt();
        int a = x/100;
        int b = x/10 % 10;
        int c = x % 10;
        boolean isSpecial = ((a + b + c >= 5) & (a + b + c < 10) | (a + b + c > 15) & (a + b + c <= 20)) & (a + b + c < b*c);
        System.out.println(isSpecial);
    }
}
//252 = true; 256 = false