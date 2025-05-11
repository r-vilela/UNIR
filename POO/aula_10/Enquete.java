public class Enquete{
    public static void main(String[] args){
        int respostas[] = {1,1,2,3,2,3,6,4,5,2,3};

        int frequencia[] = new int[6];

        for( int i = 0; i < respostas.length; i++){
            try{
                ++frequencia[respostas[i]];
            } catch(ArrayIndexOutOfBoundsException e) {
                System.err.printf("Numero %d fora do indece de frequencia!\n", i);

            }
        }

        System.out.printf("%s %10s\n", "Respostas", "Frequencia");

        for( int i = 0; i < frequencia.length; i++){
            System.out.printf("%6d%10d\n", i, frequencia[i]);
        }
    }
}
