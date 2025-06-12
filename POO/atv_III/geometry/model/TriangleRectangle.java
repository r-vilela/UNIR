import java.util.Math;

public class TriangleRectangle implements GeometricForm{
    private final double base;
    private final double height;

    public TriangleRectangle(double base, double height){
        // Exception using InvalidDimensionException
        this.base = base;
        this.height = height;
    };

    public double calculateArea(){
        double area = (this.base * this.height)/2;

        return area;
    };

    public double calculatePerimeter(){
        double per = this.base + this.height + Math.pow(this.base, 2) + Math.pow(this.height, 2);

        return per;
    };

}
