public class Livro {
		private String titulo;
		private String autor;
		private Boolean available;

		public Livro(String titulo, String autor){
				this.titulo = titulo;
				this.autor = autor;
				this.available = true;
		}

		public Boolean isAvailable(){
				return this.available;
		}

		protected void marcarComoEmprestado(){
				this.available = false;
		}

		protected void marcarComoDevolvido(){
				this.available = true;
		}

		public String toString(){
				return ("Titulo: " + this.titulo + 
						"\nAutor: " + this.autor +
						"\nDisponivel: " + (this.available ? "Sim" : "Nao"));

		}

		public String getTitulo(){
				return this.titulo;
		}
}
