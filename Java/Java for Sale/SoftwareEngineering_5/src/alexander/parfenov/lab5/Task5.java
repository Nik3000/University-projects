package alexander.parfenov.lab5;

public class Task5 {
    public String MySubstring(String str, int num, int count) {
        char[] chars = str.toCharArray();
        String answer = "";
        for(int i = num; i < num + count; i++)  //в данном примере рациональней использовать стандартный цикл for
            answer +=  String.valueOf(chars[i]);// возможна реализация с foreach, но тогда придется использовать break
        return answer;
    }
}
