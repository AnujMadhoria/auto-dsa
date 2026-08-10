# Minimum Window Substring

## Problem Description

Given two strings `s` and `t`, find the shortest substring in `s` that contains all the characters of `t`, including duplicate characters. If no such substring exists, return an empty string `""`. The problem guarantees that if such a window exists, its solution is unique.

---

## Approach

The optimal solution employs the **Sliding Window** (Two-Pointer) technique combined with a frequency map to achieve linear time complexity:

1. **Frequency Mapping**: We build a frequency map of all characters in string `t` to keep track of the exact characters and counts required. We also initialize a `count` variable to the length of `t`, representing the number of characters we still need to match.
2. **Expanding the Window (Right Pointer)**: We iterate through string `s` using the `end` pointer. For each character, we decrement its count in our frequency map. If the character was actually needed (meaning its count in the map was greater than 0 before decrementing), we decrement our global `count`.
3. **Shrinking the Window (Left Pointer)**: Once `count` reaches 0, the current window `s[start...end-1]` contains all characters of `t`. We then try to shrink this window from the left using the `start` pointer to find the minimum possible length:
   - We update our minimum window tracking variables (`minLen` and `startIndex`) if the current window is smaller than any previously found valid window.
   - We then slide the `start` pointer to the right, removing `s[start]` from the window.
   - If the removed character was a required character (meaning its frequency in our map is 0 before incrementing), our window becomes invalid, so we increment `count` to break out of the inner loop and continue searching.
   - We increment the character's frequency back in our map.
4. **Result Extraction**: After the loop finishes, if `minLen` was updated, we return the corresponding substring; otherwise, we return `""`.

---

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(m + n)$, where $m$ is the length of `s` and $n$ is the length of `t`. 
  - Creating the frequency map takes $\mathcal{O}(n)$ time.
  - Both the `start` and `end` pointers traverse the string `s` at most once, meaning each character in `s` is processed at most twice. Since the character set is bounded (at most 52 English letters), the map operations take $\mathcal{O}(1)$ time.
- **Space Complexity**: $\mathcal{O}(K)$ or $\mathcal{O}(1)$ auxiliary space, where $K$ is the size of the alphabet (character set). Since the input only consists of uppercase and lowercase English letters, the size of the frequency map is bounded by a constant (at most 52 unique keys).

---

## Edge Cases

- **`s` is shorter than `t`**: If `s.length() < t.length()`, it is mathematically impossible to form a valid window. This is handled by an immediate return of `""` at the start.
- **No valid window exists**: If `s` contains some but not all characters of `t`, `minLen` will remain `INT_MAX`, and the function correctly returns `""`.
- **Duplicate characters in `t`**: If `t` contains duplicates (e.g., `"aa"`), the frequency map ensures that the sliding window must contain at least that many duplicates before the window is marked valid.
- **Single character strings**: Works seamlessly when both `s` and `t` are of length 1 (e.g., `s = "a"`, `t = "a"`).