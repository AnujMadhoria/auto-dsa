# LeetCode 704. Binary Search

## Problem Description

Given a sorted array of unique integers `nums` and a target value `target`, search for the target within the array. If the target exists, return its index; otherwise, return `-1`. The solution must run in $O(\log n)$ time complexity, which prevents us from using a simple linear search.

## Approach

This problem is a textbook application of the **Binary Search** algorithm. Because the input array is already sorted in ascending order, we can repeatedly divide the search space in half to locate the target efficiently:

1. **Initialize Pointers**: Define two pointers, `low` at the beginning of the array (`0`) and `high` at the end of the array (`nums.size() - 1`).
2. **Iterative Search**: While `low` is less than or equal to `high`:
   - Calculate the midpoint index `mid`. To prevent potential integer overflow, we calculate it as `low + (high - low) / 2` instead of `(low + high) / 2`.
   - Compare the value at `mid` with the target:
     - If `nums[mid] == target`, we have found the target and return its index `mid`.
     - If `nums[mid] > target`, the target must be in the left half of the current search space. Thus, we discard the right half by updating `high = mid - 1`.
     - If `nums[mid] < target`, the target must be in the right half. We discard the left half by updating `low = mid + 1`.
3. **Target Not Found**: If the loop terminates without finding the target (i.e., `low` exceeds `high`), return `-1`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log n)$  
  With each iteration of the `while` loop, the search space is divided in half. For an array of size $n$, this logarithmic reduction ensures a maximum of $\log_2 n$ comparisons.
  
- **Space Complexity:** $\mathcal{O}(1)$  
  The algorithm is iterative and performs the search in-place, requiring only a constant amount of extra memory for the pointer variables (`low`, `high`, and `mid`).

## Edge Cases to Consider

- **Single-Element Array**: If `nums` contains only one element, the algorithm correctly initializes `low = high = 0`, evaluates the element, and either returns `0` (if it matches) or terminates and returns `-1`.
- **Target Out of Bounds**: If the target is smaller than the first element or larger than the last element, the boundaries (`low` or `high`) will quickly shift past each other, safely returning `-1`.
- **Target at Boundaries**: If the target is located at the very first or very last index, the pointers adjust correctly to eventually point `mid` to the boundary index.
- **Integer Overflow**: Calculating the midpoint as `low + (high - low) / 2` prevents overflow errors that can occur in languages like C++ when `low + high` exceeds the maximum value of a 32-bit signed integer.