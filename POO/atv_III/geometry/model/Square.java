import java.util.Math;

public class Square implements GeometricForm{
    private final double lado;

    public Square(double lado){
        // FAZER VERIFICACAO COM $ \le 0$
        this.lado = lado;
    };

    public double calculateArea(){
        double area = this.lado**2;

        return area;
    }:

    public doublen calculatePerimeter(){
        double per = 4 * this.lado;

        return per;
    };
}

