# Maximum Subarray

## Problem Description
Given an array of integers that can contain both positive and negative values, the goal is to find a contiguous block of elements (a subarray) that yields the highest possible sum when added together. We only need to return this maximum sum value, rather than the subarray itself. The subarray must contain at least one element.

---

## Approach

This solution utilizes **Kadane's Algorithm**, which is a dynamic programming approach that solves the problem in a single linear scan $O(n)$ of the array. 

The core intuition behind the algorithm is as follows:
1. We maintain a running sum of the current subarray (`currSum`) and the maximum sum found so far (`maxTillNow`).
2. We iterate through the array element by element, adding the current element to `currSum`.
3. If `currSum` exceeds `maxTillNow`, we update our maximum sum.
4. If `currSum` falls below `0`, we reset `currSum` to `0`. This is because any prefix sum that is negative will only decrease the sum of any subsequent subarray we might form. By discarding it, we start fresh with the next element.

### C++ Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxTillNow = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (currSum > maxTillNow) {
                maxTillNow = currSum;
            }
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxTillNow;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the `nums` array. We iterate through the array exactly once, performing constant time $\mathcal{O}(1)$ operations at each step.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The algorithm only uses two pointer-like integer variables (`currSum` and `maxTillNow`) to keep track of the sums.

---

## Edge Cases Worth Noting

- **All Negative Numbers:** (e.g., `[-3, -2, -5]`).
  - Because `maxTillNow` is initialized to `INT_MIN`, the code will correctly update to the least negative value (which is the maximum possible subarray sum, in this case, `-2`). The `currSum < 0` condition resets the running sum to `0` after each check, ensuring we do not accumulate a progressively worse negative sum.
- **Single Element Arrays:** (e.g., `[1]` or `[-5]`).
  - The loop runs exactly once. `maxTillNow` is updated to that single element, and the function correctly returns it.
- **Array with alternating large positive and negative numbers:**
  - The resetting mechanism `currSum = 0` effectively isolates local maximum-yielding segments and ignores segments that degrade the cumulative total below zero.