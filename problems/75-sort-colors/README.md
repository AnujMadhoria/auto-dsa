# Sort Colors

## Problem Description

Given an array of integers `nums` containing only `0`, `1`, and `2` (representing the colors red, white, and blue, respectively), the task is to sort the array in-place so that all identical numbers are grouped together. The final sorted array must follow the order of `0`s first, then `1`s, and finally `2`s. This must be solved without relying on any built-in library sorting functions and ideally in a single pass with $O(1)$ auxiliary space.

---

## Approach: Dutch National Flag Algorithm

This problem can be efficiently solved in a single pass using the **Dutch National Flag algorithm** designed by Edsger Dijkstra. The algorithm uses three pointers to partition the array into four regions:
1. `nums[0` to `low-1]`: Region containing only `0`s.
2. `nums[low` to `mid-1]`: Region containing only `1`s.
3. `nums[mid` to `high]`: Region containing unexamined elements.
4. `nums[high+1` to `end]`: Region containing only `2`s.

### Step-by-Step Logic
- Initialize three pointers: `low = 0`, `mid = 0`, and `high = nums.size() - 1`.
- Iterate through the array as long as `mid <= high`:
  - **If `nums[mid] == 0`**: Swap the elements at `low` and `mid`. Since we know the element swapped to `mid` is a `1` (or `mid` and `low` are pointing to the same index), we can safely increment both `low` and `mid`.
  - **If `nums[mid] == 1`**: The element is already in its correct relative position. Simply increment `mid`.
  - **If `nums[mid] == 2`**: Swap the elements at `mid` and `high`, then decrement `high`. Do not increment `mid` in this step because the new element swapped from `high` to `mid` is unexamined and must be evaluated in the next iteration.

### C++ Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) { // else if ensures only one condition triggers per iteration
                mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the number of elements in the array. The algorithm processes each element at most once, as either the `mid` pointer increases or the `high` pointer decreases at every iteration step.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The sorting is done completely in-place using only three integer pointers.

---

## Edge Cases to Note

- **Single Element Array:** If `nums = [0]`, `[1]`, or `[2]`, the loop condition `mid <= high` terminates immediately or executes once without incorrect swaps, leaving the array unchanged.
- **Array of Identical Elements:** If the input consists entirely of one color (e.g., `[1, 1, 1]`), the pointers adjust smoothly without performing unnecessary swaps.
- **Array with Missing Colors:** If one or two colors are missing (e.g., `[2, 0, 2, 0]` or `[1, 2, 1]`), the three-pointer logic correctly partitions the existing values without throwing out-of-bounds errors.
- **Already Sorted Array:** Input arrays like `[0, 1, 2]` will only cause pointer increments without any redundant swaps.