package model;

public class Rectangle implements GeometricForm{
    private final double base;
    private final double height;

    public Rectangle(double base, double height) throws InvalidDimensionException{
        if(base <= 0 || height <= 0){
            throw new InvalidDimensionException("Base or Height values error!");
        }else{
            this.base = base;
            this.height = height;
        }
       // FAZER VERIFICACAO COM $ \le 0$
    };

    public double calculateArea(){
        double area = this.base * this.height;

        return area;
    };

    public double calculatePerimeter(){
        double per = 2 * (this.base * this.height);

        return per;
    };

    @Override
    public String getDimensionDetails(){
        return "Base: " + this.base + " Height: " + this.height;
    };

    @Override
    public String getFormName(){
        return "Rectangle";
    }
}


