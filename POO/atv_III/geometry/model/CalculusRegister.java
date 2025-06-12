package model;

public class CalculusRegister{
    private final GeometricForm form;

    private final double calculatedArea;
    private final double calculatedPerimeter;

    public CalculusRegister(GeometricForm form){
        if(form.getFormName() != null){
            this.form = form;
            this.calculatedArea = form.calculateArea();
            this.calculatedPerimeter = form.calculatePerimeter();

        }else{
            System.out.println("Form is null!");
            this.form = null;
            this.calculatedPerimeter = 0;
            this.calculatedArea = 0;
        };
    };

    public GeometricForm getForm(){
        return this.form;
    };

    public double getArea(){
        return this.calculatedArea;
    };

    public double getPerimeter(){
        return this.calculatedPerimeter;
    };
}

