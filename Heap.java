import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Heap {
    private List<Integer> heap = new ArrayList<>();
    private int lastIndex = -1;

    private void swap(int i, int j) {
        int t = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, t);
        
    }

    private void shiftUp(int ci) {
        int pi = (ci - 1) / 2;
        if (pi < ci && heap.get(pi)<heap.get(ci)) {
            swap(ci, pi);
            shiftUp(pi);
        }
    };

    private void shiftDown(int ci) {
        int lc = 2*ci+1;
        int rc = 2*ci+2;
        if (lc<=lastIndex) {
            if(rc<=lastIndex){
                if(heap.get(lc)<heap.get(rc)){
                    if(heap.get(ci)<heap.get(rc)){
                        swap(rc, ci);
                        shiftDown(rc);
                    }
                }else{
                    if(heap.get(ci)<heap.get(lc)){
                        swap(lc, ci);
                        shiftDown(lc);
                    }
                }
            }else{
                if(heap.get(ci)<heap.get(lc)){
                    swap(lc, ci);
                    shiftDown(lc);
                }
            }
        }
    };

    public void insert(int x) {
        heap.add(x);
        lastIndex++;
        shiftUp(lastIndex);
    }

    public int extractMax() {
        if(lastIndex<0) return -1;
        swap(lastIndex, 0);
        lastIndex--;
        shiftDown(0);
        return heap.remove(lastIndex+1);
    }

    public int getMax() {
        if(lastIndex<0) return -1;
        return heap.get(0);
    }

    public static void main(String[] args) {
        Heap heap = new Heap();
        heap.insert(42);
        heap.insert(16);
        heap.insert(18);
        heap.insert(22);
        heap.insert(21);
        heap.insert(19);
        heap.insert(6);
        heap.insert(52);

        // default is min heap.
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> -1 * o1.compareTo(o2));

        pq.add(42);
        pq.add(16);
        pq.add(18);
        pq.add(22);
        pq.add(21);
        pq.add(19);
        pq.add(6);
        pq.add(52);

        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
        assert (Integer) pq.remove() == heap.extractMax();
    }
}