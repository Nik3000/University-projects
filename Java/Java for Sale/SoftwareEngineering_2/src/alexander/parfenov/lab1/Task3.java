package alexander.parfenov.lab1;

import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите имя");
        String name = in.nextLine();
        System.out.println("Введите рост в сантиметрах");
        double height = in.nextDouble();
        System.out.printf("Пользователь: "+name+"\n"+"Статус: студент\nХарактерные особенности: лень матушка\nРост:\n"
                +height+" в сантиметрах\n"+height/100+" в метрах\n"+height/30.48+
                " в футах\n"+height/2.5+" в дюймах\n"+height/45+" в локтях");

    }
}
