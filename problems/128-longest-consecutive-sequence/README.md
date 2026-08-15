# 128. Longest Consecutive Sequence

## Problem Description

Given an unsorted list of integers, find the length of the longest sequence of consecutive numbers (i.e., numbers that can be arranged in an unbroken chain where each number is exactly 1 greater than the previous one, such as `1, 2, 3, 4`). The elements do not need to be adjacent in the original array, but the algorithm must find the sequence in linear $O(n)$ time, ruling out a simple sorting-based approach.

---

## Approach

The solution utilizes a hash set (`std::unordered_set`) to achieve $O(1)$ lookups, which is key to keeping the runtime linear. 

1. **Set Initialization**: We first insert all numbers from the input vector into an `unordered_set`. This automatically removes duplicates and allows us to check the existence of any number in constant time.
2. **Identifying Sequence Starters**: We iterate through each unique number in the set. To avoid redundant checks and ensure we only traverse each sequence once, we only begin counting a sequence if the current number is the **start** of a sequence. We determine this by checking if `num - 1` exists in the set. If it does, we skip the current number because it will be counted as part of a sequence starting at some smaller number.
3. **Counting Sequence Length**: If `num - 1` does not exist, we have found the beginning of a sequence. We then use a `while` loop to check for the presence of consecutive numbers (`num + 1`, `num + 2`, etc.) and increment a counter.
4. **Updating the Maximum**: After reaching the end of a consecutive chain, we compare its length with the maximum length found so far and update our global tracker `longest`.

By only starting the sequence search from the minimum value of each consecutive block, each element in the set is visited at most twice: once in the outer loop and at most once during the sequence building in the inner loop. This guarantees a linear runtime.

---

## Code (C++)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numsSet) {
            // Check if 'num' is the start of a sequence
            if (numsSet.find(num - 1) == numsSet.end()) {
                int length = 1;
                // Count the length of this consecutive sequence
                while (numsSet.find(num + length) != numsSet.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the number of elements in the array. Inserting elements into the hash set takes $\mathcal{O}(n)$ time. The outer loop runs $n$ times, but the inner `while` loop only executes for the start of each sequence. Since each number is part of exactly one sequence, the inner loop processes each number at most once across the entire execution. Thus, the total time complexity is linear.
- **Space Complexity:** $\mathcal{O}(n)$ to store the elements of the array in the `unordered_set`.

---

## Edge Cases

- **Empty Input (`nums` is empty):** The code safely handles this. The set is empty, the loop does not run, and the function returns `0`.
- **Single Element Array:** The set contains one element. `num - 1` is not found, the sequence length is counted as `1`, and `1` is returned.
- **Duplicate Elements:** Duplicates are naturally resolved and ignored because the `unordered_set` only stores unique keys.
- **All Elements Consecutive or Decisive Discontinuity:** 
  - For input `[1, 2, 3, 4]`, the algorithm identifies `1` as the start and counts to `4`.
  - For input `[100, 4, 200, 1, 3, 2]`, it correctly identifies `1` and counts up to `4`, while skipping `2, 3, 4` during the outer loops because their predecessors exist.