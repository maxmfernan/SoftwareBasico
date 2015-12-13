class TesteAvancado{
	public int k=10;
	public static int pow(int a, int b){
		int i, resultado = 1;
		for(i=0; i<b; i++){
			resultado *= a;
		}
		return resultado;
	}
	public static int soma(int a, int b){
		return a + b;
	}
	public static int subtracao(int a, int b){
		return a - b;
	}
	public static int soma3(int a, int b, int c){
		return soma( soma( a, b ), c );
	}
	public static int sub3(int a, int b, int c){
		return subtracao( subtracao( a, b ), c );
	}
	public static void main(String[] s)	{
		int i;
		int j = -2;
		final int k=10, l=10;
		int[] meuVetor = new int[10];
		for (i = 0; i < 10; i++){
			meuVetor[i] = pow(j,i);
		}
		for (i = 0; i < 10; i++){
			System.out.println(meuVetor[i]);
		}
	}
}