package alexander.parfenov.lab1;

import java.util.Scanner;

import static java.lang.StrictMath.sin;

public class Task4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите x");
        double x = in.nextDouble();
        double answer = (sin(x*x+2)/11*Math.log(x*x+2))+(x*x/11);
        System.out.println(answer);
    }
}
//Не реализован вывод в формате мантиссы