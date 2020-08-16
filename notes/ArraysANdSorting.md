# Arrays

# Sorting
- Heap and Merge sort have nlogn for all three average, worst best.
- Radix is nk fo all three.
- Selection sort is work with n^2 for all three.
- Inserstion and Bubble have OmegaN rest N^2, can say second worse
- Worst case is usually O(n^2) 

## Insertion Sort
- Omega(n), Theta(n square), O(n spuare)
- Loop Invariant: 
    - After ith iteration first i elements are sorted.
    - After ith iteration A[0,9] are sorted.
[Java Code](../java/InsertionSort.java)

## Merge Sort
- Divide and Conquer Paradigm
- There are logN sub-problems, and it takes Theta(N) to solve one.
- Average, Worst and Best all are same hence Theta(N).
- Space Complexity for merge procedure is O(N), and the stack for a recursion requires O(logN) space.
- Infinities in sub arrays in merge procedure can be used to avoid loops.
[Java Code](../java/MergeSort.java)


## Quick Sort
- Idea is an element if placed at its right position has all elements left to it as less and all element right to it greater.
- So, For an Array A[p,r] the q th element can be placed in right place in an iteration then, A[p,q-1] & A[q+1, r] can be sorted.
- The PARTITION procedure places the qth element at its right place in a run and returns q.
- Worst case is O(N square), but its in place, avg case is O(nlogn) and works for Virtual Memory.
- you can avoid running both i and j from both ends. See impl [Java Code](../java/QuickSort.java)

## Bubble Sort
- intuitive and easy, runs in O(n square)
- in each iteration the ith largest element gets to its correct position.
[Java Code](../java/BubbleSort.java)
- once in an iteration completes with no swap. we can terminate the program. use sorted flag for this.

## Selection Sort
- select the least ith element in ith iteration and put it in the sorted array, boundary indicated by 'i'.
- runs in O(n square)
- [Java Code](../java/SelectionSort.java)
