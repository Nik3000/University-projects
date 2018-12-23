package alexander.parfenov.lab4;

public class Task1 {
    public int width;
    public int height;
    public int WCount;
    public int HCount;

    Task1(){
        width = 0;
        height = 0;
        WCount = 0;
        HCount = 0;
    }

    Task1(int w, int h, int wc, int wh){
        width = w;
        height = h;
        WCount = wc;
        HCount = wh;
    }

    public double WPix(){
        double d = width/2.5;
        return WCount/d;
    }

    public double HPix(){
        double d = height/2.5;
        return HCount/d;
    }

    public boolean square(){
        boolean flag = WPix() == HPix();
        return flag;
    }

    public boolean circle(double r, double x, double y){
        boolean flag = (width - x - r*2 <= width) & (height - y - r*2 <= height);
        return (flag);
    }
}
