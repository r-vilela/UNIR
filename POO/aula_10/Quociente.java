import java.util.Scanner;

public class Quociente{
    public static int quociente(int num1, int num2){
        return num1/num2;
    }

    public static void main(String[] args){
        int numerador, denominador;
        Scanner entrada = new Scanner(System.in);
        boolean continuar = true;

        do{
            try{
                System.out.println("Informe o numerador: ");
                numerador = entrada.nextInt();

                System.out.println("Informe o denominador: ");
                denominador = entrada.nextInt();

                System.out.println("Quocient: " + quociente(numerador, denominador));
                continuar = false;
            }catch( ArithmeticException e ){
                System.err.println("Nao e permitido! " + e.getMessage());
            }catch( InputMismatchException e ){
                System.err.println("Operacao Invalida!");
            }
        }while(continuar);

    }
}
