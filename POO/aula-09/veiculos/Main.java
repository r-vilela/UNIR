public class Main{
		public static void main(String[] args) {
				Carro carro = new Carro("vermelho", "123123123", "NF3F123");
				carro.emitirGuiaSeguro();

				Moto moto = new Moto("amarela", "123123123", "GT3M332");
				moto.emitirGuiaSeguro();
		}
}
