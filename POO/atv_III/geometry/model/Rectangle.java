public class Square implements GeometricForm{
    private final double base;
    private final double height;

    public Square(double base, double height){
        // FAZER VERIFICACAO COM $ \le 0$
        this.base = base;
        this.height = height;
    };

    public double calculateArea(){
        double area = this.base * this.height;

        return area;
    }:

    public doublen calculatePerimeter(){
        double per = 2 * (this.lado * this.height);

        return per;
    };
}


