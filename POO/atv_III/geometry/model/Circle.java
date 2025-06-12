import java.util.Math;

public class Circle implements GeometricForm{
    private final double raio;

    public Circle(double raio){
        // FAZER VERIFICACAO COM $ \le 0$
        this.raio = raio;
    };

    public double calculateArea(){
        double area = Math.PI * (this.raio * this.raio);

        return area;
    }:

    public doublen calculatePerimeter(){
        double per = 2 * Math.PI * this.raio;

        return per;
    };
}
