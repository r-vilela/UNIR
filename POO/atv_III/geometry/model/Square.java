package model;

import static java.lang.Math.*;

public class Square implements GeometricForm{
    private final double side;

    public Square(double side) throws InvalidDimensionException{
         if(side <= 0){
            throw new InvalidDimensionException("Sibe values error!");
        }else{
            this.side = side;
        }
       // FAZER VERIFICACAO COM $ \le 0$
    };

    public double calculateArea(){
        double area = pow(this.side, 2);

        return area;
    };

    public double calculatePerimeter(){
        double per = 4 * this.side;

        return per;
    };

    @Override
    public String getDimensionDetails(){
        return "Side: " + this.side;
    };

    @Override
    public String getFormName(){
        return "Square";
    }

}

