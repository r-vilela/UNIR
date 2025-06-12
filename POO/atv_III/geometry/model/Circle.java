package model;

import static java.lang.Math.PI;

public class Circle implements GeometricForm{
    private final double radius;

    public Circle(double radius) throws InvalidDimensionException{
        // FAZER VERIFICACAO COM $ \le 0$
        if(radius <= 0){
            throw new InvalidDimensionException("Radius values error!");
        }else{
            this.radius = radius;
        }
    };

    public double calculateArea(){
        double area = Math.PI * (this.radius * this.radius);

        return area;
    };

    public double calculatePerimeter(){
        double per = 2 * Math.PI * this.radius;

        return per;
    };

    @Override
    public String getDimensionDetails(){
        return "Radius: " + this.radius;
    };

    @Override
    public String getFormName(){
        return "Circle";
    }
}
