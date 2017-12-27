package test;
import Chapter1_Fundamentals.Unit5_UnionFind.UF;

public class Tester {
    public static void main(String[] args) {
        System.out.println("input the number of array to init:");
        int N = StdLib.StdIn.readInt();
        UF uf = new UF(N);
        System.out.println("array has been initialized!");
        System.out.println("union the array? (0 to exit, others to continue):");
        int key = StdLib.StdIn.readInt();
        while(0 != key)
        {
            System.out.println("input to int to Unit Find");
            int p = StdLib.StdIn.readInt();
            int q = StdLib.StdIn.readInt();
            if(uf.connected(p, q)) continue;
            uf.union(p, q);
            System.out.println(p + " " + q);
            System.out.println("continue union? (0 to exit, others to continue):");
            key = StdLib.StdIn.readInt();
        }
        System.out.println(uf.count() + " components");
    }
}
