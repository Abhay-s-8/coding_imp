import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Arrays;

public final class PowerOfTwoMaxHeap<T extends Comparable<? super T>> {
    private Object[] heap;
    private int size;
    private final int childrenPower;
    private final int childrenCount;

    private static final int DEFAULT_CAPACITY = 16;
    private static final int MAX_CHILDREN_POWER = 30;

    public PowerOfTwoMaxHeap(int childrenPower) {
        if (childrenPower < 0 || childrenPower > MAX_CHILDREN_POWER)
            throw new IllegalArgumentException("childrenPower must be in range [0, " + MAX_CHILDREN_POWER + "]");
        this.childrenPower = childrenPower;
        
        this.heap = new Object[Math.max(DEFAULT_CAPACITY, 1)];
        this.size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void insert(T item) {
        if (item == null) throw new NullPointerException("null elements not allowed");
        ensureCapacity(size + 1);
        heap[size] = item;
        siftUp(size);
        size++;
    }

    @SuppressWarnings("unchecked")
    public T popMax() {
        if (size == 0) throw new NoSuchElementException("Heap is empty");
        T max = (T) heap[0];
        size--;
        if (size > 0) {
            heap[0] = heap[size];
            heap[size] = null;
            siftDown(0);
        } else heap[0] = null;
        return max;
    }

    @SuppressWarnings("unchecked")
    public T peekMax() {
        return size == 0 ? null : (T) heap[0];
    }

    private void ensureCapacity(int minCapacity) {
        if (minCapacity <= heap.length) return;
        int newCap = heap.length << 1;
        if (newCap < minCapacity) newCap = minCapacity;
        heap = Arrays.copyOf(heap, newCap);
    }

    @SuppressWarnings("unchecked")
    private void siftUp(int idx) {
        int cur = idx;
        T val = (T) heap[cur];
        while (cur > 0) {
            int parent = parentIndex(cur);
            T parentVal = (T) heap[parent];
            if (val.compareTo(parentVal) > 0) {
                heap[cur] = parentVal;
                cur = parent;
            } else break;
        }
        heap[cur] = val;
    }

    @SuppressWarnings("unchecked")
    private void siftDown(int idx) {
        int cur = idx;
        T val = (T) heap[cur];
        final int n = size;
        while (true) {
            long firstChildLong = (((long) cur) << childrenPower) + 1L;
            if (firstChildLong >= n) break;
            int firstChild = (int) firstChildLong;
            int maxChildIndex = firstChild;
            T maxChildValue = (T) heap[firstChild];
            int lastChild = Math.min(n - 1, firstChild + childrenCount - 1);
            for (int c = firstChild + 1; c <= lastChild; c++) {
                T candidate = (T) heap[c];
                if (candidate.compareTo(maxChildValue) > 0) {
                    maxChildValue = candidate;
                    maxChildIndex = c;
                }
            }
            if (maxChildValue.compareTo(val) > 0) {
                heap[cur] = maxChildValue;
                cur = maxChildIndex;
            } else break;
        }
        heap[cur] = val;
    }

    private int parentIndex(int i) {
        return (i - 1) >> childrenPower;
    }

    public static void main(String[] args) {
        PowerOfTwoMaxHeap<Integer> heap = new PowerOfTwoMaxHeap<>(2);
        heap.insert(10);
        heap.insert(85);
        heap.insert(42);
        heap.insert(17);
        heap.insert(69);
        heap.insert(5);
        System.out.println("Max popped: " + heap.popMax());
        System.out.println("Next max: " + heap.peekMax());
        while (!heap.isEmpty()) System.out.print(heap.popMax() + " ");
        System.out.println();
    }
}
