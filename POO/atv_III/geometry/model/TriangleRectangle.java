package model;

import static java.lang.Math.*;

public class TriangleRectangle implements GeometricForm{
    private final double base;
    private final double height;

    public TriangleRectangle(double base, double height) throws InvalidDimensionException{
        // Exception using InvalidDimensionException
        if(base <= 0 || height <= 0){
            throw new InvalidDimensionException("Base or Height values error!");
        }else{
            this.base = base;
            this.height = height;
        }
    };

    public double calculateArea(){
        double area = (this.base * this.height)/2;

        return area;
    };

    public double calculatePerimeter(){
        double per = this.base + this.height + Math.pow(this.base, 2) + Math.pow(this.height, 2);

        return per;
    };

    @Override
    public String getDimensionDetails(){
        return "Base: " + this.base + " Height: " + this.height;
    };

    @Override
    public String getFormName(){
        return "Triangle Rectangle";
    }

}
