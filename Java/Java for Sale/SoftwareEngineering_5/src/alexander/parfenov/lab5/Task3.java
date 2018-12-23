package alexander.parfenov.lab5;
import java.util.Random;

public class Task3 {
    Random rnd = new Random(System.currentTimeMillis());
    private int[][] array;
    public int n;
    public int[][] Array() {
        array = new int [n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                array[i][j] = rnd.nextInt();
        return array;
    }
}

//Создание рандамного массива