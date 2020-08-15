public class MergeSort {

    public static void sort(int[] a, int p, int q) {
        if (p == q - 1) {
            return;
        } else {
            int mid = (p + q) / 2;
            sort(a, p, mid);
            sort(a, mid, q);
            merge(a, p, mid, q);
        }
    }

    private static void merge(int[] a, int p, int q, int r) {

        int n = r - p;

        int b[] = new int[n];
        int i, j, k;
        i = p;
        j = q;
        k = 0;

        while (i < q && j < r) {
            if (a[i] < a[j]) {
                b[k] = a[i];
                i++;
            } else {
                b[k] = a[j];
                j++;
            }
            k++;
        }

        while (j < r) {
            b[k] = a[j];
            j++;
            k++;
        }

        while (i < q) {
            b[k] = a[i];
            i++;
            k++;
        }

        for (i = 0; i < n; i++) {
            a[p + i] = b[i];
        }
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

        sort(a1, 0, a1.length);
        System.out.println(test(a1Sorted, a1));
    }

}