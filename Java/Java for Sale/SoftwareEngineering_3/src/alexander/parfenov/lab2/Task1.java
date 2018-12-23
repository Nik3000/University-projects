package alexander.parfenov.lab2;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите пол: М или Ж");
        char gender = in.next().charAt(0);
        String answer = String.valueOf(gender).equalsIgnoreCase("М") ? "Мальчики налево" : "Девочки направо";
        System.out.println(answer);
    }
}

//В этом задании не требовалась проверка на правильность введенного символа. Будьте внимательны при тестах