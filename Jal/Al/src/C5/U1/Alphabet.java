package C5.U1;

public class Alphabet {
    // the characters in the alphabet
    private char[] alphabet;
    // indices
    private int[] inverse;
    // the radix of the alphabet
    private int R;

    // Create a new Alphabet from chars in string.
    public Alphabet(String alpha)
    {
        // check that alphabet contains no duplicate chars
        boolean[] unicode = new boolean[Character.MAX_VALUE];
        for(int i = 0; i < alpha.length(); i++)
        {
            char c = alpha.charAt(i);
            if(unicode[c])
                throw new RuntimeException("Illeagal alphabet: character = '" + c + "'");
            else
                unicode[c] = true;
        }

        alphabet = alpha.toCharArray();
        R = alpha.length();
        inverse = new int[Character.MAX_VALUE];
        for(int i = 0; i < inverse.length; i++)
            inverse[i] = -1;

        // can't use char since R can be as big as 65,536
        for(int c = 0; c < R; c++)
            inverse[alphabet[c]] = c;
    }


    // Create a new Alphabet of Unicode chars 0 to R-1
    private Alphabet(int R)
    {
        alphabet = new char[R];
        inverse = new int[R];
        this.R = R;

        // can't use char since R can be as big as 65,536
        for(int i = 0; i < R; i++)
            alphabet[i] = (char)i;
        for(int i = 0; i < R; i++)
            inverse[i] = i;
    }

    // Create a new Alphabet of Unicode chars 0 to 255(extended ASCII)
    public Alphabet()
    {
        this(256);
    }

    // is character c in the alphabet?
    public boolean contains(char c)
    {
        return inverse[c] != -1;
    }

    // return radix R
    public int R()
    {
        return R;
    }

    // return number of bits to represent an index
    public int lgR()
    {
        int lgR = 0;
        for(int t = R; t > 1; t /= 2)
            lgR++;
        return lgR;
    }

    // convert c to index between 0 and R-1.
    public int toIndex(char c)
    {
        if(c < 0 || c >= inverse.length || inverse[c] == -1)
        {
            throw new RuntimeException("Character " + c + " not in alphabet");
        }
        return inverse[c];
    }

    // convert String s over this alphabet into a base-R integer
    public int[] toIndices(String s)
    {
        char[] source = s.toCharArray();
        int[] target = new int[s.length()];
        for(int i = 0; i < source.length; i++)
            target[i] = toIndex(source[i]);
        return target;
    }

    // convert an index between 0 and R-1 into a char over this alphabet
    public char toChar(int index)
    {
        if(index < 0 || index >= R)
        {
            throw new RuntimeException("Alphabet out of bounds");
        }
        return alphabet[index];
    }

    // Convert base-R integer into a String over this alphabet
    public String toChars(int[] indices)
    {
        StringBuilder s = new StringBuilder(indices.length);
        for(int i = 0; i < indices.length; i++)
            s.append(toChar(indices[i]));
        return s.toString();
    }

    public static void main(String[] args)
    {
        Alphabet alpha = new Alphabet(args[0]);
        int R = alpha.R();
        int[] count = new int[R];

        In in = new In(args[1]);
        String s = in.readAll();
        int N = s.length();
        for(int i = 0; i < N; i++)
            if(alpha.contains(s.charAt(i)))
                count[alpha.toIndex(s.charAt(i))]++;

        for(int c = 0; c < R; c++)
            StdOut.println(alpha.toChar(c) + " " + count[c]);
    }

}
