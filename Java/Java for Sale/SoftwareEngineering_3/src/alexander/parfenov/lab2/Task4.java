package alexander.parfenov.lab2;

import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int answer = 60;
        System.out.println("Уличная закусочная 'Ильшата' приветствует вас");
        System.out.println("Введите пожалуйста вид кофе: Американо (60р) или Эспрессо (70р)");
        String coffee = in.next();
        System.out.println("Добавить сливки? (10р) (Да/Нет)");
        String cream = in.next();
        if (coffee.equalsIgnoreCase("Эспрессо"))
            answer = 70;
        if (cream.equalsIgnoreCase("Да"))
            answer = answer + 10;
        System.out.println("Сумма вашего заказа = "+answer+"р");
    }
}

//В этом задании опять же не требовалась проверка на правильность введенных символов. Будьте внимательны при тестах