# 217. Contains Duplicate

## Problem Description

The objective of this problem is to determine whether an input list of integers contains any duplicate values. If any number appears at least twice in the array, we should return `true`. If every element in the array is unique, we should return `false`.

## Approach

The provided solution uses a Hash Map (`std::unordered_map` in C++) to keep track of the frequency of each number in the array. 

1. We initialize an empty hash map where the keys represent the integers from the input array and the values represent their corresponding frequency counts.
2. We iterate through each number `n` in the input vector `nums`.
3. For each number, we increment its frequency in the map: `map[n]++`.
4. Immediately after incrementing, we check if the count of the current number has reached 2 or more (`map[n] >= 2`). If it has, we have found a duplicate and can immediately return `true` (early exit).
5. If the loop completes without finding any duplicates, we return `false`.

*Note: While a hash set (`std::unordered_set`) could also be used to simply track the existence of elements, this hash map approach achieves the same goal by tracking frequency counts.*

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in the array. We iterate through the array of size $N$ exactly once. Hash map insertions and lookups operate in $\mathcal{O}(1)$ average time complexity.
- **Space Complexity:** $\mathcal{O}(N)$. In the worst-case scenario where all elements in the array are distinct, the hash map will store all $N$ elements, requiring linear space.

## Edge Cases

- **Single Element Array:** If the input has only one element (e.g., `nums = [1]`), the loop runs once, no frequency reaches 2, and the function correctly returns `false`.
- **Duplicates at the Beginning:** If the duplicate elements are at the very beginning of the array (e.g., `nums = [1, 1, 2, 3]`), the algorithm exits early on the second element, saving computation time.
- **Negative Numbers:** The input constraints allow negative values (down to $-10^9$). Since `std::unordered_map` handles negative integers as keys natively, the algorithm works correctly without any modifications.