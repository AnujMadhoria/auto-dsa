# Group Anagrams

## Problem Description

Given an array of strings, the goal is to group words that are anagrams of each other together. An anagram is a word formed by rearranging the letters of another word, using all the original letters exactly once. For example, the words "eat", "tea", and "ate" all contain the same set of characters, so they should be grouped into the same sub-list. The final output should be a list of these grouped anagrams, and the groups can be returned in any order.

---

## Approach

The solution utilizes a hash map to group the anagrams efficiently by finding a common identifier (or "signature") for all words that are anagrams of one another.

1. **Identify the Signature**: When sorted alphabetically, any two anagrams will become identical. For example, "eat", "tea", and "ate" all sort to `"aet"`. We can use this sorted version of the word as a key in our hash map.
2. **Hash Map Grouping**: We initialize an `unordered_map` where the key is a `string` (the sorted signature) and the value is a `vector<string>` (the list of original words that share this signature).
3. **Iteration**: 
   * For each string in the input list, we create a copy and sort its characters.
   * We then insert the original string into the map under its sorted key.
4. **Collect Results**: Finally, we iterate through the hash map and collect all the grouped vectors into a single 2D vector, which we return as the final answer.

---

## Complexity Analysis

Let $N$ be the number of strings in the input array `strs`, and $K$ be the maximum length of a string in `strs`.

* **Time Complexity**: $\mathcal{O}(N \cdot K \log K)$
  * We iterate through all $N$ strings.
  * For each string of length at most $K$, sorting it takes $\mathcal{O}(K \log K)$ time.
  * Inserting and looking up keys in the hash map takes $\mathcal{O}(K)$ time on average to hash the string.
  * Thus, the overall time complexity is dominated by the sorting step: $\mathcal{O}(N \cdot K \log K)$.

* **Space Complexity**: $\mathcal{O}(N \cdot K)$
  * We store all $N$ strings of maximum length $K$ in our hash map.
  * The final output structure also holds all the strings, requiring $\mathcal{O}(N \cdot K)$ space.

---

## Edge Cases

* **Empty Strings (`""`)**: An empty string sorts to `""`. The algorithm correctly hashes empty strings to the key `""` and groups them together.
* **Single-Character Strings**: Strings with a single character (e.g., `"a"`) are trivially sorted and grouped correctly.
* **No Anagrams**: If the input has no anagrams, each word will simply form its own individual group containing only one element.
* **Duplicate Words**: If the input contains identical strings, they will naturally have the same sorted key and will be grouped together correctly.