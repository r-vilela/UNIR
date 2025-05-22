import javax.swing.JOptionPane;

public class Main{
    public static void main(String  args[]){
        JOptionPane.showMessageDialog(null, "Apenas um teste", "Titulo Test", JOptionPane.INFORMATION_MESSAGE);

        String [] students = {"Antonio", "Filiph", "Amanda", "Geovane", "JP", "Anna Julia"};

        int opt = JOptionPane.showOptionDialog(
                null,
                "Choose one Student",
                "Options",
                JOptionPane.DEFAULT_OPTION,
                JOptionPane.INFORMATION_MESSAGE,
                null, students, students[0]);
        System.out.println(students[opt] + " is been KICKED OUT FROM THE SCHOOL!!!");
    }
}
