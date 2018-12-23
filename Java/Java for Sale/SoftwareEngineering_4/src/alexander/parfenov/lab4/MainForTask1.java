package alexander.parfenov.lab4;

import java.util.Scanner;

public class MainForTask1 {
    public static void main(String[] args){
        Task1 P1 = new Task1();
        Scanner in = new Scanner(System.in);
        System.out.println("Введите ширину в милиметрах");
        P1.width = in.nextInt();
        System.out.println("Введите высоту в милиметрах");
        P1.height = in.nextInt();
        System.out.println("Введите количество точек по ширине");
        P1.WCount = in.nextInt();
        System.out.println("Введите количество точек по высоте");
        P1.HCount = in.nextInt();
        Task1 task = new Task1(P1.width, P1.height, P1.WCount, P1.HCount);
        System.out.println("Ширина "+task.width+"\nВысота "+task.height+"\nКоличество по ширине "+task.WCount+"\nКоличество по высоте "+task.HCount);
        double wp = P1.WPix();
        System.out.println(wp);
        double hp = P1.HPix();
        System.out.println(hp);
        boolean sq = P1.square();
        System.out.println(sq);
        System.out.println("Введите координаты центра окружности\nВведите x");
        double x = in.nextDouble();
        System.out.println("Введите y");
        double y = in.nextDouble();
        System.out.println("Введите радиус");
        double r = in.nextDouble();
        boolean circ = P1.circle(r, x, y);
        System.out.println(circ);
    }
}
