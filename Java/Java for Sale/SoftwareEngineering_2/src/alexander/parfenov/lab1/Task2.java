package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите имя");
        String name = in.nextLine();
        System.out.println("Введите курс");
        int curs = in.nextInt();
        System.out.println("a) "+name+" будет учиться еще максимум "+(4-curs)+" лет");
        String answer = name+" будет учиться еще максимум "+(4-curs)+" лет";
        System.out.print("b)c) "+answer);

    }
}
//обработки ошибок нет, так как не заявлено