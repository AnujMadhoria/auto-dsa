# Longest Substring Without Repeating Characters

## Problem Description
Given a string `s`, the goal is to find the length of the longest continuous block of characters (a substring) that does not contain any duplicate characters. For example, in the string `"abcabcbb"`, the longest substring without repeating characters is `"abc"`, which has a length of `3`. Note that the characters must be contiguous; a subsequence like `"pwke"` from `"pwwkew"` is not valid because it is not contiguous.

---

## Code Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> window;

        while (right < s.length()) {
            if (window.find(s[right]) == window.end()) {
                window.insert(s[right]);
                int currLen = right - left + 1;
                maxLen = max(maxLen, currLen);
                right++;
            } else {
                window.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
```

---

## Approach
The solution uses the **Sliding Window** technique optimized with a **Hash Set** (`unordered_set`) to keep track of unique characters in the current window. 

1. **Initialize Pointers:** We maintain two pointers, `left` and `right`, representing the boundaries of our current substring window. Both start at index `0`. We also initialize `maxLen` to track the maximum length found so far.
2. **Expand the Window:** We iterate through the string by moving the `right` pointer to the right.
   - If the character `s[right]` is **not** present in our hash set, it means we can safely extend our current substring. We add this character to our set, calculate the current window size (`right - left + 1`), update `maxLen` if the current window is larger, and increment `right`.
3. **Shrink the Window:**
   - If `s[right]` is already in our hash set, we have encountered a duplicate. To make the window valid again, we shrink it from the left. We remove the character `s[left]` from the set and increment `left`. We repeat this step until the duplicate character is evicted from the current window.
4. **Result:** Once the `right` pointer reaches the end of the string, `maxLen` will hold the length of the longest unique substring.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `s`. In the worst-case scenario, each character is visited at most twice: once by the `right` pointer (inserted into the set) and once by the `left` pointer (removed from the set). Hash set insertions, deletions, and lookups take $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(\min(N, M))$, where $N$ is the length of the string and $M$ is the size of the character set (alphabet). In the worst case, the hash set will store all unique characters of the string. Since the input characters are limited to standard ASCII symbols, English letters, and digits, the maximum size of the set is bounded by the alphabet size (which is at most 128 or 256). Thus, the space complexity is effectively $\mathcal{O}(1)$ auxiliary space.

---

## Edge Cases
- **Empty String (`s = ""`):** The loop condition `right < s.length()` is immediately false. The function returns `maxLen = 0`, which is correct.
- **Single Character String (`s = "a"`):** The window expands to size `1`, updates `maxLen` to `1`, and then terminates. Returns `1` correctly.
- **All Identical Characters (`s = "bbbbb"`):** The window expands to size `1`. On the next step, it encounters a duplicate, evicts the leftmost `'b'`, and moves `left` forward. The maximum window size correctly remains `1`.
- **No Duplicate Characters (`s = "abcdef"`):** The `right` pointer moves from the beginning to the end without ever triggering the `else` block. The maximum length returned is the length of the string, which is correct.