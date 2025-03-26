public class Contato {
		private String nome;
		private int telefone;
		private String email;

		public Contato(String nome, int telefone, String email) {
				this.nome = nome;
				this.telefone = telefone;
				this.email = email;
		};

		public String getNome(){
				return this.nome;
		};
		public void setNome(String nome){
				this.nome = nome;
		};
		public int getTel(){
				return this.telefone;
		};
		public void setTel(int telefone){
				this.telefone = telefone;
		};
		public String getEmail(){
				return this.email;
		};
		public void setEmail(String email){
				this.email = email;
		};

		public String toString(){
				return "Nome: " + this.nome + ", Telefone: " + this.telefone + ", Email: " + this.email;
		};
}
