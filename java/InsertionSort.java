class InsertionSort {

    public static int[] sort(int[] a) {
        int x;
        int n = a.length;

        // Best case Omega(n), Worst O(n^2)
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            x = a[j];
            // Very IMP: its not a[j] but x with whome we compare.
            while (j > 0 && x < a[j - 1]) {
                a[j] = a[j - 1];
                --j;
            }
            a[j] = x;
        }
        return a;
    }

    public static boolean test(int sorted[], int a[]) {
        for (int i = 0; i < a.length; i++) {
            if (sorted[i] != a[i])
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] a1 = { 3, 5, 6, 8, 9, 6 };
        int[] a1Sorted = { 3, 5, 6, 6, 8, 9 };

        a1 = sort(a1);
        System.out.println(test(a1Sorted, a1));
    }
}