package alexander.parfenov.lab2;
import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите месяц");
        int month = in.nextInt();
        if (month > 0 & month < 7)
            System.out.println("Предстоит сдавать отчет за первое полугодие");
        else if (month > 6 & month < 13)
            System.out.println("Предстоит сдавать зачет за второе полугодие");
    }
}