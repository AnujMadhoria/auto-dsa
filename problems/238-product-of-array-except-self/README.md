# 238. Product of Array Except Self

## Problem Description

Given an array of integers, construct a new array of the same length where the value at each index is the product of all the numbers in the original array except for the one at that index. You must solve this in $O(n)$ time complexity and without using the division operation.

## Approach

Since division is forbidden, we cannot simply calculate the total product of the array and divide it by each element. Instead, we can observe that the product of all elements except `nums[i]` is the product of all elements to the left of `i` (the prefix product) multiplied by the product of all elements to the right of `i` (the suffix product).

To solve this with $O(1)$ auxiliary space (excluding the output array), we can perform the calculations in two passes using the output array `ans` to accumulate the results:

1. **Left-to-Right Pass (Prefix Product)**: 
   We traverse the array from left to right. We maintain a running product of all elements seen so far (`prefix`). For each index `i`, we store the current `prefix` in `ans[i]`, and then update `prefix` by multiplying it by `nums[i]`. After this pass, `ans[i]` contains the product of all elements to the left of `i`.

2. **Right-to-Left Pass (Suffix Product)**: 
   We traverse the array in reverse (from right to left). We maintain a running product of all elements to the right (`suffix`). For each index `i`, we multiply the existing value in `ans[i]` (which is the prefix product) by `suffix`, and then update `suffix` by multiplying it by `nums[i]`. 

By the end of the second pass, each position in `ans` contains the product of its prefix and suffix, which is the desired product of all elements except itself.

### C++ Source Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the input array. We traverse the array exactly twice.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The output array `ans` is required by the problem and does not count toward the extra space complexity.

## Edge Cases

- **Single Zero in the Input:** If there is exactly one zero in the array (e.g., `[1, 2, 0, 4]`), the output at the zero's index will be the product of all other elements (non-zero), while all other indices will output `0`. This approach handles this naturally without division-by-zero checks.
- **Multiple Zeros in the Input:** If there are two or more zeros in the array (e.g., `[1, 0, 3, 0]`), every position in the output array will correctly resolve to `0`.
- **Negative Numbers:** The product calculations naturally handle negative numbers and preserve the correct sign of the product.