# 42. Trapping Rain Water

## Problem Statement

Imagine a terrain of adjacent bars of width 1, where the heights of the bars are given by an array of non-negative integers. When it rains, water fills the valleys between these bars. The goal is to calculate the total volume of rainwater that remains trapped within these valleys once the rain stops.

---

## Approach

This solution utilizes the **Two-Pointer Approach** to solve the problem in a single pass with constant extra space.

The volume of water that can be trapped above any single bar at index `i` is determined by the minimum of the maximum height to its left and the maximum height to its right, minus the height of the bar itself: 
$$\text{Water}[i] = \min(\text{max\_left}, \text{max\_right}) - \text{height}[i]$$

Instead of precomputing these maximums using auxiliary arrays, we can use two pointers, `left` and `right`, starting at the two ends of the array:

1. **Initialization**: 
   * `left` starts at index `0`, and `right` starts at the last index.
   * `leftMax` and `rightMax` are initialized to `0` to keep track of the tallest bars encountered so far from each direction.
   
2. **Two-Pointer Traversal**:
   * At each step, we update `leftMax` with `height[left]` and `rightMax` with `height[right]`.
   * We compare `leftMax` and `rightMax`:
     * If `leftMax < rightMax`, it guarantees that any water trapped at the `left` pointer is bounded by `leftMax` (since we know there is a bar on the right that is at least as tall as `rightMax`). Thus, we can safely compute the water trapped at index `left` as `leftMax - height[left]`, add it to our total, and increment `left`.
     * If `leftMax >= rightMax`, the bottleneck is on the right side. We compute the water trapped at index `right` as `rightMax - height[right]`, add it to our total, and decrement `right`.
   * The loop terminates when the two pointers meet.

### C++ Source Code

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax) {
                water += leftMax - height[left];  
                left++;
            } else {
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  The algorithm uses a single pass where the `left` and `right` pointers move toward each other. Each element is visited exactly once.

- **Space Complexity:** $\mathcal{O}(1)$
  Only a constant amount of extra space is used for the pointers and tracking variables (`left`, `right`, `leftMax`, `rightMax`, and `water`).

---

## Edge Cases

- **Fewer than 3 Bars ($n < 3$):** 
  If the array has a size of 1 or 2, it is impossible to trap any water because a container requires a left wall, a right wall, and a middle depression. The `while (left < right)` loop handles these cases naturally and returns `0` because `leftMax` and `rightMax` will match the current heights, resulting in `0` trapped water.

- **Monotonically Increasing or Decreasing Heights:** 
  For arrays like `[1, 2, 3, 4]` or `[4, 3, 2, 1]`, there are no valleys to trap water. The condition `leftMax - height[left]` or `rightMax - height[right]` will always evaluate to `0` because the boundary maximums will always equal the current bar's height.

- **Uniform Heights:** 
  For inputs like `[3, 3, 3, 3]`, there are no relative depressions. No water is trapped, and the algorithm correctly returns `0`.