class Program {
    public static void main () {
          
        int a;
        int b;
        b = 9;
        a = getNumberPlusOne(b);
        System.out.println(a);
    }

    public static int getNumberPlusOne(int a) {
        a = a + 1;
        return a;
    }
}

