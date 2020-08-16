public class SelectionSort {
    private static void swap(int a[], int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static boolean test(int sorted[], int a[]) {
        for (int i = 0; i < a.length; i++) {
            if (sorted[i] != a[i])
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] a1 = {3, 5, 6, 8, 9, 6};
        int[] a1Sorted = {3, 5, 6, 6, 8, 9};

        sort(a1);
        System.out.println(test(a1Sorted, a1));
    }

    private static void sort(int[] a) {
        int n = a.length;

        int smallest;
        int smallest_index;

        for (int i = 0; i < n; i++) {
            // in ith iteration find the ith smallest element and swap it with the i.
            smallest = Integer.MAX_VALUE;
            smallest_index = -1;

            for (int j = i; j < n; j++) {
                if(a[j]<smallest){
                    smallest = a[j];
                    smallest_index = j;
                }
            }

            swap(a, smallest_index, i);
        }
    }
}
