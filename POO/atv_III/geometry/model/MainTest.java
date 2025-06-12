package model;

import java.util.ArrayList;
import java.util.List;

public class MainTest{
    public static void main(String[] args) {
        List<GeometricForm> forms = new ArrayList<>();

        try {
            forms.add(new Circle(5.0));
            forms.add(new Square(4.0));
            forms.add(new Rectangle(3.0,4.0));
            forms.add(new TriangleRectangle(3.0,4.0));

            System.out.println("\nTrying to create an invalid form");
            forms.add(new Circle(-1.0));
        } catch (InvalidDimensionException e) {
            //TODO: handle exception
            System.err.println("Error when creating a form: " + e.getMessage());
        }

        for(GeometricForm form : forms){
            System.out.println("Form: " + form.getFormName());
            System.out.println("Dimensions:  " + form.getDimensionDetails());
            System.out.println("Area: " + form.calculateArea());
            System.out.println("Perimeter: " + form.calculatePerimeter());
            System.out.println("\n");

            CalculusRegister register = new CalculusRegister(form);

            System.out.println("Register - Area: " + String.format("%.2f", register.getArea()));
            System.out.println("Register - Perimeter: " + String.format("%.2f", register.getPerimeter()));
            System.out.println("----");
        }


    }
}

