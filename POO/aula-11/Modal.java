import javax.swing.*;

public class Modal{
    public static void main(String[] args){
        JFrame frame = new JFrame("Tela Inicial");
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDialog modal = new JDialog(frame, "Janela Modal", true);
        modal.setSize(200, 200);
        JLabel label = new JLabel("Esta eh uma label!");

        modal.add(label);

        frame.setVisible(true);
        modal.setVisible(true);
    }
}
