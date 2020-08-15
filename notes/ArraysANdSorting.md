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
- Divide and Conq