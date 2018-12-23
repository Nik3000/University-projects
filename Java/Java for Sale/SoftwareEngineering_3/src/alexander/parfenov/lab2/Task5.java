package alexander.parfenov.lab2;

import java.util.Scanner;

public class Task5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String quarter = "Невозможный";
        System.out.println("Введите месяц");
        String month = in.next();
        switch (month) {
            case "Январь": quarter = "первый";
                break;
            case "Февраль": quarter = "первый";
                break;
            case "Март": quarter = "первый";
                break;
            case "Апрель": quarter = "второй";
                break;
            case "Май": quarter = "второй";
                break;
            case "Июнь": quarter = "второй";
                break;
            case "Июль": quarter = "третий";
                break;
            case "Август": quarter = "третий";
                break;
            case "Сентябрь": quarter = "третий";
                break;
            case "Октябрь": quarter = "четвертый";
                break;
            case "Ноябрь": quarter = "четвертый";
                break;
            case "Декабрь": quarter = "четвертый";
                break;
        }
        System.out.println("Предстоит сдавать "+quarter+" квартальный отчет");
    }
}
