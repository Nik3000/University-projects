package alexander.parfenov.lab2;
import java.util.Scanner;

public class Task6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Помните, что длина больше ширины");
        System.out.println("Введите ширину участка");
        double WPlot = in.nextDouble();
        System.out.println("Введите длину участка");
        double LPlot = in.nextDouble();
        System.out.println("Введите ширину дома");
        double WHouse = in.nextDouble();
        System.out.println("Введите длину дома");
        double LHouse = in.nextDouble();
        System.out.println("Введите ширину бани");
        double WSauna = in.nextDouble();
        System.out.println("Введите длину бани");
        double LSauna = in.nextDouble();

        boolean flag = false;
        if ((LPlot >= LHouse & LPlot >= LSauna || LPlot >= LHouse+LSauna) & (WPlot >= WHouse & WPlot >= WSauna || WPlot >= WHouse+WSauna))
            flag = true;
        else if ((LPlot >= WHouse & LPlot >= WSauna || LPlot >= WHouse+WSauna) & (WPlot >= LHouse & WPlot >= LSauna || WPlot >= LHouse+LSauna))
            flag = true;
        else if ((LPlot >= LHouse & LPlot >= WSauna || LPlot >= LHouse+WSauna) & (WPlot >= WHouse & WPlot >= LSauna || WPlot >= WHouse+LSauna))
            flag = true;
        else if ((LPlot >= WHouse & LPlot >= WSauna || LPlot >= WHouse+LSauna) & (WPlot >= LHouse & WPlot >= WSauna || WPlot >= LHouse+WSauna))
            flag = true;

        if (flag == true)
            System.out.println("На участке можно построить дом и баню");
        else
            System.out.println("На участке нельзя построить дом и баню");
    }
}
