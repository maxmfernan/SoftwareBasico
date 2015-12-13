class FibonacciRec2{

      public static void main(String[] s){

          int num = 20;

          System.out.println("Serie De Fibonacci: ");
		for (int i = 1; i < num; i++)
		{
             System.out.println(fib(i));
             System.out.println(" ");
		}




   }
   public static int fib(int i)
   {
	if(i<=2)
		return 1;

	return fib(i-1)+fib(i-2);
   }


}

