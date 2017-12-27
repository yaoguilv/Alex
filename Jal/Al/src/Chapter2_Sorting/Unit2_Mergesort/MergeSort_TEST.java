package Chapter2_Sorting.Unit2_Mergesort;

public class MergeSort_TEST {
    public static void merge(int[] a, int lo, int mid, int hi) {
        int N = a.length;
        int aux[] = new int[N];
        for (int m = lo; m <= hi; m++) {
            aux[m] = a[m];
        }
        int i = lo;
        int j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (aux[i] < aux[j])
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
        }
    }

    public static void sort(int[] a, int lo, int hi) {
        if (lo >= hi)
            return;
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid);
        sort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    public static void main(String[] args) {
//        int[] arr = { 3, 2 };
         int[] arr = { 3, 2, 1, 8, 6, 5, 4, 7 };

        sort(arr, 0, arr.length - 1);
        for (int k = 0; k < arr.length; k++) {
            System.out.print(arr[k]);
            System.out.print(" ");
        }
    }
}
