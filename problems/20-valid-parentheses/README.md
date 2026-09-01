# 20. Valid Parentheses

## Problem Description
Given a string containing only the characters `(`, `)`, `{`, `}`, `[`, and `]`, determine if the input string is valid. A string is considered valid if all opening brackets are closed by the exact same type of closing brackets, closed in the correct order (most recently opened must be closed first), and every closing bracket has a corresponding open bracket preceding it.

## Approach
This problem is solved using a **Stack** data structure, which naturally models the Last-In, First-Out (LIFO) behavior required for matching nested brackets. The last bracket opened must be the first one to close.

### Algorithm
1. **Initialize an empty stack** to store opening brackets.
2. **Iterate through each character** in the string:
   - If the character is an opening bracket (`(`, `[`, `{`), push it onto the stack.
   - If the character is a closing bracket (`)`, `]`, `}`):
     - Check if the stack is empty. If it is, we have a closing bracket with no matching opening bracket, so the string is invalid.
     - Peek at the top of the stack. If the top element is not the corresponding opening bracket for our current closing bracket, the string is invalid.
     - If it matches, pop the opening bracket off the stack and continue.
3. **Final Check**: Once the loop finishes, verify if the stack is empty. If the stack is empty, all brackets were matched correctly. If the stack still contains elements, some opening brackets were never closed, making the string invalid.

### C++ Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string $s$. We traverse the string exactly once, and each stack operation (`push`, `pop`, `top`, `empty`) runs in $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(N)$ in the worst case (e.g., an input consisting entirely of opening brackets like `((((((`), where we store all characters in the stack.

## Edge Cases

- **Only Opening Brackets (e.g., `(((`):** The stack will never trigger the closing logic but will return `false` at the end because the stack is not empty.
- **Only Closing Brackets (e.g., `]]]`):** The empty check `st.empty()` immediately catches this on the first character and returns `false`.
- **String Starts with a Closing Bracket (e.g., `)()`):** The check `st.empty()` immediately fails, returning `false` without unnecessary processing.
- **Mismatched Order (e.g., `([)]`):** The stack detects that the top element `[` does not match the closing bracket `)` and correctly returns `false`.
- **Minimum Constraints (e.g., length $1$):** A single-character string will always return `false` because it either goes to the stack and fails the final empty check, or fails the initial empty check for closing brackets.