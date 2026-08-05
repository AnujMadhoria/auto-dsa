# 1. Two Sum

## Problem Description
Given an array of integers `nums` and a target integer `target`, find the indices of the two numbers in the array that add up to the target. You are guaranteed that there is exactly one solution, and you are not allowed to use the same element at the same index twice. The result can be returned in any order.

## Approach
The solution uses a single-pass hash map (implemented as `std::map` in C++) to find the complement of each number efficiently:

1. **Complement Look-up**: For any number `nums[i]`, the number we need to find to reach the target is `complement = target - nums[i]`.
2. **Value-to-Index Mapping**: We iterate through the array once. For each element, we check if its required `complement` is already stored in our map.
   - If the complement exists in the map, it means we have previously encountered the matching number. We immediately return the index of the complement and the current index `i`.
   - If the complement does not exist, we insert the current number and its index (`map[nums[i]] = i`) into the map and continue to the next iteration.
3. This approach avoids the $O(n^2)$ brute-force method of comparing every pair by trading space for speed.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \log n)$  
  The solution uses `std::map` in C++, which is implemented as a red-black tree (balanced binary search tree). Lookups and insertions in `std::map` take $\mathcal{O}(\log n)$ time. Since we perform these operations for up to $n$ elements, the total time complexity is $\mathcal{O}(n \log n)$. 
  *(Note: This can be optimized to $\mathcal{O}(n)$ by using `std::unordered_map`, which provides $\mathcal{O}(1)$ average-time lookups and insertions).*

- **Space Complexity:** $\mathcal{O}(n)$  
  In the worst-case scenario, we may need to store up to $n - 1$ elements in the map before finding a valid pair.

## Edge Cases
- **Duplicate Elements:** If the input contains duplicate values that add up to the target (e.g., `nums = [3, 3]`, `target = 6`), the algorithm handles this correctly. Because we check if the complement `3` exists in the map *before* inserting the second `3`, we successfully pair them without the second element overwriting the first one's index in the map.
- **Negative Numbers:** The algorithm naturally handles negative integers and targets (e.g., finding a target of `-5` with elements `-2` and `-3`) because the complement calculation mathematical properties remain the same.
- **Minimal Array Size:** The constraints guarantee at least 2 elements, which is the absolute minimum required to find a pair.