import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Hello extends Application {

    @Override
    public void start(Stage stage) {
        try{
            //Parent root = FXMLLoader.load(getClass().getResource("basic.fxml"));
            String javaVersion = System.getProperty("java.version");
            String javafxVersion = System.getProperty("javafx.version");
            Label l = new Label("Hello, from JavaFX " + javafxVersion + ", running on Java " + javaVersion + ".");
            Scene scene = new Scene(new StackPane(l), 640, 480);
            stage.setScene(scene);
            stage.show();
        } catch (Exception e){
            System.err.println("erro: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        launch();
    }

}

