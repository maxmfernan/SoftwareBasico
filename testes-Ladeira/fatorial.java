public class fatorial
{
	public static void main( String[ ] args )
	{
		System.out.println( fat( 6 ) ) ;
	}
	public static int fat( int num )
	{
		if( num == 0 )
		{
			return 1 ;
		}
		else
		{
			return num * fat( num - 1 ) ;
		}
	}
}
