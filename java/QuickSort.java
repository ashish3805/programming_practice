public class QuickSort {

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

    private static void sort(int[] a, int p, int r) {
        if (p >= r - 1) {
            return;
        } else {
            int q = partition(a, p, r);
            sort(a, p, q);
            sort(a, q + 1, r);
        }
    }

    private static void swap(int a[], int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }


    private static int partition(int[] a, int p, int r) {
        int pivot = a[p];
        int i = r;
        int j = r - 1;

        for (; j > p; --j) {
            if (a[j] > pivot) {
                swap(a, j, --i);
            }
        }

        swap(a, --i, p);
        return i;
    }
}
