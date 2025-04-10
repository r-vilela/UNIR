public class Moto extends Veiculo{
		public Moto(String cor, String chassi, String placa){
				super(cor, chassi, placa);
		}
		public void emitirGuiaSeguro(){
				System.out.println("Isso eh uma moto");
				super.emitirGuiaSeguro();
		}
}
