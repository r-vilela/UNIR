
import java.util.HashMap;

public class HashMapEx{	

		public static void main(String[] args) {

				HashMap<String, String> bck = new HashMap<>();

				mapa.put("bck1", "Pablo");
				mapa.put("bck2", "Tairone");
				mapa.put("bck3", "Uniqua");
				mapa.put("bck4", "Austin");

				for (String chave: mapa.keySet()) {
						System.out.println("Chave: " + chave + "Valor: " + mapa.get(chave));
				};

		}
}
