class Grandfather {
    static int a ;
}

class Parent extends Grandfather
{
    static Integer[] a = new Integer[10];
}
class ClassInitializationDemo6 extends Parent
{
    static int b = 2;
    
    
    
    public static void main (String [] args)
    {
        System.out.println ("b = " + b);
    }
}