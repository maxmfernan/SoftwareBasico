class encadeamento {

	static float quadrado(float valor) {
		return (valor * valor);
	}

	static float cubo(float valor)	{
		return (valor * quadrado(valor));
	}

	public static void main(String[] s) {
		float 	f,
			resultado;

		f = 65.5f;
		resultado = cubo(f);
		System.out.println(f);
		System.out.println(" elevado a 3 eh igual a ");
		System.out.println(resultado);

	}
}