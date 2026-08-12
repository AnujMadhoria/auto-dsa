# LeetCode 56: Merge Intervals

## Problem Description

Given a collection of numerical intervals, some of which might overlap, the goal is to combine all overlapping intervals into single, continuous segments. The output should be a list of these merged, mutually exclusive intervals that collectively cover the exact same range as the original input.

---

## Approach

The optimal way to solve this problem is using a **greedy algorithm** after **sorting** the intervals.

1. **Sort the Intervals**: 
   We sort the list of intervals primarily by their start times. Sorting guarantees that any intervals that could potentially merge are positioned adjacent to each other.
   
2. **Iterate and Merge**: 
   We initialize an empty list `ans` to store our merged intervals. We then loop through the sorted intervals one by one:
   * **No Overlap**: If `ans` is empty or if the start time of the current interval is strictly greater than the end time of the last interval in `ans`, it means there is no overlap. We safely append the current interval to `ans`.
   * **Overlap**: If the start time of the current interval is less than or equal to the end time of the last interval in `ans`, they overlap. We merge them by updating the end time of the last interval in `ans` to be the maximum of its current end time and the end time of the current interval.

Using this approach, we can process all intervals in a single linear pass after sorting.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$, where $N$ is the number of intervals. Sorting the array takes $\mathcal{O}(N \log N)$ time, while the subsequent linear scan to merge the intervals takes $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(\log N)$ or $\mathcal{O}(N)$ auxiliary space. This is required for the internal stack space used by the sorting algorithm (`std::sort` in C++). If we exclude the memory allocated for the output list `ans`, the algorithm runs in $\mathcal{O}(1)$ auxiliary space beyond the sorting overhead.

---

## Edge Cases

- **Single Interval:** If the input contains only one interval (e.g., `[[1, 3]]`), the loop executes once and correctly returns the interval as-is.
- **Completely Nested Intervals:** For inputs like `[[1, 10], [2, 5]]`, the algorithm correctly merges them into `[[1, 10]]` by taking the maximum end time.
- **Adjacent/Touching Boundaries:** Intervals that share a boundary point but do not deeply overlap (e.g., `[[1, 4], [4, 5]]`) are correctly merged into `[[1, 5]]`.
- **Unsorted Input:** Inputs that are not ordered by start times (e.g., `[[4, 7], [1, 4]]`) are handled seamlessly because the very first step of the algorithm is to sort them.