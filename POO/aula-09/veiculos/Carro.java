public class Carro extends Veiculo{
		public Carro(String cor, String chassi, String placa){
				super(cor, chassi, placa);
		}
		public void emitirGuiaSeguro(){
				System.out.println("Isso eh um Carro");
				super.emitirGuiaSeguro();
		}
}
