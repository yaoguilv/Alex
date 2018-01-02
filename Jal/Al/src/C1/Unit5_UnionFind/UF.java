package C1.Unit5_UnionFind;

public class UF
{
    private int[] id; // access to component id (site indexed)
    private int count; // number of comoponents

    public UF(int N)
    {
        // Initialize component id array.
        count = N;
        id = new int[N];
        for(int i = 0; i < N; i++)
            id[i] = i;
    }

    public int count()
    {
        return count;
    }

    public boolean connected(int p, int q)
    {
        return find(p) == find(q);
    }

    public int find(int p)
    {
        return id[p];
    }

    public void union(int p, int q)
    {
        // Put p and q into the same component.
        int pID = find(p);
        int qID = find(q);

        // Nothing to do if p and q are already in the same component.
        if(pID == qID) return;

        // Rename p's component to q's name.
        for(int i = 0; i < id.length; i++)
            if(id[i] == pID) id[i] = qID;
        count--;
    }

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

