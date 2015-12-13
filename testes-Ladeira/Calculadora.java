
public class Calculadora {
	private static final int N_ALUNOS = 3;
	
	private static final String II = "II";
	private static final String MI = "MI";
	private static final String MM = "MM";
	private static final String MS = "MS";
	private static final String SS = "SS";
	
	public static void calcularNota(int[][] matricula_nota) {
		for(int i=0; i < N_ALUNOS;i++) {
			System.out.println("MATRICULA: ");
			System.out.println(matricula_nota[i][0]);
			System.out.println("MENCAO: ");
			if (matricula_nota[i][1] >= 9) {
				System.out.println(SS);
			} else if (matricula_nota[i][1] >= 7) {
				System.out.println(MS);				
			} else if (matricula_nota[i][1] >= 5) {
				System.out.println(MM);				
			} else if (matricula_nota[i][1] >= 3) {
				System.out.println(MI);				
			} else if (matricula_nota[i][1] >= 1) {
				System.out.println(II);
			}
		}
	}
}
