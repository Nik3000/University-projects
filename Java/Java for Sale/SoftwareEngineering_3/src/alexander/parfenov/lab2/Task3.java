package alexander.parfenov.lab2;
import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String quarter;
        System.out.println("Введите месяц");
        int month = in.nextInt();
        if (month > 0 & month < 4)
            quarter = ("первый");
        else if (month > 3 & month < 7)
            quarter = ("второй");
        else if (month > 6 & month < 10)
            quarter = ("третий");
        else if (month > 9 & month < 13)
            quarter = ("четвертый");
        else
            quarter = ("Невозможный"); //Вместо обработки ошибки
        System.out.println("Предстоит сдавать "+quarter+" квартальный отчет");
    }
}
