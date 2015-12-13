class potencia {
	static int base = 2;
	static int exp = 10;

	public static int potencia(int base, int exp) {
		int resultado = 1;

		for(int i = 1; i <= exp; i++) {
			resultado = resultado * base;
		}
		return (resultado*base/base);
	}

	public static void main(String[] s) {
		int resultado;

		resultado = potencia(base, exp);

		System.out.println(base);
		System.out.println(" elevado a ");
		System.out.println(exp);
		System.out.println(" eh igual a: " );
		System.out.println(resultado);
	}
}
