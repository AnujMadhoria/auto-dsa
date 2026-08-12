# LeetCode 125: Valid Palindrome

## Problem Description
The goal of this problem is to determine whether a given string is a palindrome. A palindrome is a sequence of characters that reads the exact same way forward and backward. To make this determination, we must first clean the input string by stripping away all non-alphanumeric characters (such as spaces, punctuation, and symbols) and converting all remaining letters to lowercase. If the filtered sequence is symmetric, the function should return `true`; otherwise, it should return `false`.

## Approach
This solution uses the **Two Pointers** technique to validate the palindrome in-place, which avoids the overhead of creating a new filtered string.

1. **Initialization**: We initialize two pointers: `left` at the beginning of the string (`0`) and `right` at the end of the string (`s.size() - 1`).
2. **Skipping Non-Alphanumeric Characters**: In each iteration of the main loop, we advance the `left` pointer to the right and decrement the `right` pointer to the left as long as they point to non-alphanumeric characters. We use the helper function `isalnum()` to identify valid alphanumeric characters.
3. **Comparison**: Once both pointers point to valid alphanumeric characters, we compare them. To ensure the comparison is case-insensitive, we wrap both characters in the `tolower()` function.
   - If the characters do not match, we immediately return `false`.
   - If they do match, we increment `left` and decrement `right` to check the next pair of characters.
4. **Termination**: If the pointers meet or cross without finding any mismatched characters, the string is a valid palindrome, and we return `true`.

### C++ Code
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `s`. In the worst-case scenario, each character in the string is traversed at most twice (once by the inner loops to skip invalid characters and once during the comparison step).
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm runs entirely in-place, modifying only a few index pointers and using zero additional memory.

## Edge Cases
- **Empty String or Single Character:** If the input string is empty or contains only one character, it is trivially a palindrome and correctly returns `true`.
- **No Alphanumeric Characters:** For strings composed entirely of spaces or punctuation (e.g., `".,"`), the inner loops will gracefully skip all characters until the pointers cross, correctly returning `true`.
- **Case Sensitivity:** Strings with mixed casing (e.g., `"AbBa"`) are processed correctly because characters are converted to lowercase using `tolower()` before comparison.