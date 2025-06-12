import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Regex{
    public static void main(String[] args){
        String text = "O numero de telefone eh 123-456-7890";
        Pattern pattern = Pattern.compile("\\d{3}-\\d{3}-\\d{4}");
        Matcher matcher = pattern.matcher(text);

        if(matcher.find()){
            System.out.println("Numero encontrado!");
        }else{
            System.out.println("Numero nao encontrado!");
        }

    }
}
