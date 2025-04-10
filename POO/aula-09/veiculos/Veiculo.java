public class Veiculo{
		private String cor;
		private String chassi;
		private String placa;

		public Veiculo(String cor, String chassi, String placa){
				this.cor = cor;
				this.chassi = chassi;
				this.placa = placa;
		}

		public void emitirGuiaSeguro(){
				System.out.println("Cor: " + this.cor);
				System.out.println("Chassi: " + this.chassi);
				System.out.println("Placa: " + this.placa);
		}
}
