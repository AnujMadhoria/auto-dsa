# Valid Anagram

## Problem Description
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. In plain English, the goal of this problem is to determine whether two given strings, `s` and `t`, contain the exact same characters with the exact same frequencies, regardless of the order in which they appear. If they do, they are anagrams, and we return `true`; otherwise, we return `false`.

## Approach
The provided solution utilizes a multi-set data structure to keep track of character frequencies:

1. **Length Check**: If the lengths of `s` and `t` are not equal, they cannot be anagrams of each other. The function immediately returns `false`.
2. **Populate the Bucket**: We initialize a `std::multiset<char>` named `bucket`. A multiset is chosen because it allows and maintains duplicate elements. We loop through the first string `s` and insert all of its characters into the multiset.
3. **Verify and Match**: We then loop through the second string `t`. For each character:
   - We search for it in our `bucket` using `bucket.find(t[i])`.
   - If the character is found, we erase exactly *one* instance of it by passing its iterator to `bucket.erase(it)`. 
   - If the character is not found, it means `t` contains a character that either does not exist in `s` or has appeared more times than it did in `s`. In this case, we immediately return `false`.
4. **Conclusion**: If we successfully match and remove every character in `t` from the bucket, the strings are anagrams, and we return `true`.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N \log N)$, where $N$ is the length of the strings. 
  - Inserting $N$ characters into a `std::multiset` of size up to $N$ takes $\mathcal{O}(N \log N)$ time.
  - Searching and erasing elements by iterator in a `std::multiset` takes $\mathcal{O}(\log N)$ time per operation, resulting in $\mathcal{O}(N \log N)$ for the second loop.
  - *Note*: This can be optimized to $\mathcal{O}(N)$ time by using a fixed-size frequency array of size 26 or a hash map (`std::unordered_map`).

- **Space Complexity**: $\mathcal{O}(N)$ to store the characters of string `s` in the `std::multiset`.

## Edge Cases & Follow-up

### Edge Cases Handled:
- **Different Lengths**: Handled at the very beginning of the function, preventing unnecessary processing.
- **Duplicate Characters**: Handled correctly by using a `multiset` and deleting elements using iterators rather than keys (which would otherwise delete all duplicate instances of a character).

### Follow-up: Handling Unicode Characters
If the inputs contain Unicode characters (which can span beyond the basic ASCII range):
- The `multiset` approach would still conceptually work if the string characters are encoded as wide characters (e.g., `wchar_t` or standard `std::wstring` elements).
- However, the most efficient way to adapt to Unicode characters is to use a hash map (`std::unordered_map<char32_t, int>` or `std::unordered_map<string, int>` if using UTF-8 representation) to store character counts. This avoids the $\mathcal{O}(N \log N)$ overhead of tree-based structures like `multiset` and scales efficiently for millions of possible Unicode characters while maintaining $\mathcal{O}(N)$ time complexity.