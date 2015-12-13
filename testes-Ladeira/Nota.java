
public class Nota {

	/**
	 * @param args
	 */
	
	private static final int N_ALUNOS = 3;
	
	
	public static void main(String[] args) {
		int[][] matricula_nota = new int [N_ALUNOS][2];
		matricula_nota[0][0] = 3234;
		matricula_nota[0][1] = 10;
		matricula_nota[1][0] = 2132;
		matricula_nota[1][1] = 6;
		matricula_nota[2][0] = 5353;
		matricula_nota[2][1] = 4;
		
		Calculadora.calcularNota(matricula_nota);
		

	}

}
