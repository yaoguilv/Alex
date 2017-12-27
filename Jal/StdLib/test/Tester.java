package test;

public class Tester {
    public static void main(String[] args) {
        System.out.print("Hello Tester!\n");
        String[] a = StdLib.StdIn.readStrings();

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
        }

    }
}
