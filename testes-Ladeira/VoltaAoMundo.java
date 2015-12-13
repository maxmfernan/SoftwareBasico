
class VoltaAoMundo{
	public static void main(String[] s)	{
    float circunf = 40075.02f;
    float consAviao = 18.71f;
    int vAviao = 900;
    float consCarro = 0.08f;
    int vCarro = 120;
    float consPeh = 0.0f;
    int vPeh = 6;

    float nPassos;
    float precos0,precos1;

	  precos0 = 1.41f; // querosene
	  precos1 = 2.60f; // gasolina

		System.out.println("Aviao:");
		System.out.println("Consumo(L): ");
		System.out.println(consumoTotal(consAviao, circunf) );
		System.out.println("Preco(R$): ");
		System.out.println(Combustivel.precoTotal( Combustivel.consumoTotal( consAviao, circunf ), precos0 ) );
		System.out.println("Tempo(Horas): ");
		System.out.println(Tempo.tempoTotal( vAviao, circunf ));
		System.out.println("Tempo(Dias): ");
		System.out.println( Tempo.tempoTotal( vAviao, circunf ) / 24);
		System.out.println("----------------------------------------------");
		System.out.println("Carro:");
		System.out.println("Consumo(L): ");
		System.out.println(Combustivel.consumoTotal( consCarro, circunf ) );
		System.out.println("Preco(R$): ");
		System.out.println(Combustivel.precoTotal( Combustivel.consumoTotal( consCarro, circunf ), precos1 ) );
		System.out.println("Tempo(Horas): ");
		System.out.println(Tempo.tempoTotal( vCarro, circunf ));
		System.out.println("Tempo(Dias): ");
		System.out.println( Tempo.tempoTotal( vCarro, circunf ) / 24);
		System.out.println("----------------------------------------------");
		System.out.println("A peh:");
		System.out.println("Consumo(L): ");
		System.out.println(Combustivel.consumoTotal( consCarro, circunf ) );
		System.out.println("Preco(R$): ");
		System.out.println(Combustivel.precoTotal( Combustivel.consumoTotal( consPeh, circunf ), 0 ) );
		System.out.println("Tempo(Horas): ");
		System.out.println(Tempo.tempoTotal( vPeh, circunf ));
		System.out.println("Tempo(Dias): ");
		System.out.println( Tempo.tempoTotal( vPeh, circunf ) / 24.f);
    nPassos = circunf / 0.0007f;
    System.out.println("Numero de passos: ");
    System.out.println(nPassos);
	}

	public static float consumoTotal( float consumo, float dist ){
	        return dist * consumo;
	}
	public static float precoTotal( float consumo, float preco ){
	        return consumo * preco;
    }
}
