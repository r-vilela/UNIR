public class CalculusRegister{
    private final GeometricForm form;

    private final double calculatedArea;
    private final double calculatedPerimeter;

    public CalculusRegister(GeoemtricForm form){
        it(form.getFormName() != null){
            this.form = form;
            this.calculatedArea = form.calculateArea();
            this.calculatedPerimeter = form.calculatePerimeter();

        }else{
            System.out.println("Form is null!");
        }
    };

    public GeometricForm getForm(){
        return this.form;
    };

    public GeometricForm getArea(){
        return this.calculatedArea;
    };

    public GeometricForm getPerimeter(){
        return this.calculatedPerimeter;
    };
}

