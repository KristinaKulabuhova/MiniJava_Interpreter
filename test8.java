class Program {
    public static void main () {
          
        int a;
        a = 0;
        System.out.println(a);
    }
}

class MyClass {
    public void main2 () {

        int a;
        int b;
        b = 9;
        a = this.getNumberPlusOne(b);
        System.out.println(a);
    }

    public int getNumberPlusOne(int a) {
        a = a + 1;
        return a;
    }
}

