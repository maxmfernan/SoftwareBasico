/*
 * Compile assim: javac float_cast.java -target 1.2 -source 1.2
 */
public class float_cast_s_double{
	public static void main(String args[]){
		float a=100.6f;
		short teste=42;

		/*s2l*/
		System.out.println((long)teste);
		/*f2s*/
		System.out.println((short)a);
		/*f2i*/
		System.out.println((int)a);
		/*f2b*/
		System.out.println((byte)a);
		/*s2b*/
		System.out.println((byte)teste);
	}
}
