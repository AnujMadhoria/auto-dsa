# 739. Daily Temperatures

## Problem Description

Given an array of integers representing daily temperatures, determine how many days you have to wait after each day to experience a warmer temperature. If no warmer temperature is expected in the future for a given day, the answer for that day should be `0`.

---

## Approach

A naive approach would use nested loops to search for the next warmer day for each element, resulting in an $O(N^2)$ time complexity. To optimize this to $O(N)$, we can use a **Monotonic Decreasing Stack**.

Instead of storing the temperature values directly, we store their **indices** in the stack. This allows us to easily calculate the number of days between the current day and a previous colder day.

### Algorithm Steps:
1. Initialize an array `answer` of the same size as `temperatures` with all elements set to `0`.
2. Initialize an empty stack to keep track of the indices of the days we have seen but haven't found a warmer day for yet.
3. Iterate through the temperatures from left to right:
   - While the stack is not empty and the current temperature is strictly greater than the temperature at the index stored at the top of the stack:
     - We have found a warmer day for the index at the top of the stack.
     - Pop this index (`prev_index`) from the stack.
     - Calculate the distance: `answer[prev_index] = current_index - prev_index`.
   - Push the current index onto the stack.
4. Return the `answer` array.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        stack<int> stack;

        for (int i = 0; i < n; i++) {
            // Check if the current temperature is warmer than the temperature at the top of the stack
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int prev_index = stack.top();
                stack.pop();

                answer[prev_index] = i - prev_index;
            }
            stack.push(i);
        }
        return answer;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in the `temperatures` array. Although there is a nested `while` loop, each index is pushed onto the stack exactly once and popped from the stack at most once. Thus, the amortized time complexity is linear.
- **Space Complexity:** $\mathcal{O}(N)$ in the worst case (e.g., when temperatures are in non-increasing order), where the stack will store up to $N$ indices.

---

## Edge Cases

- **Strictly Decreasing Temperatures:** For an input like `[80, 70, 60, 50]`, no day will ever find a warmer day. The stack will grow to size $N$ and never trigger the `while` loop condition. The output will correctly remain `[0, 0, 0, 0]`.
- **Strictly Increasing Temperatures:** For an input like `[30, 40, 50, 60]`, each day's warmer temperature is immediately the next day. The stack will never hold more than one element at the end of an iteration, and the output will be `[1, 1, 1, 0]`.
- **Duplicate Temperatures:** If the array contains consecutive identical temperatures (e.g., `[70, 70, 72]`), the solution handles it correctly because the condition `temperatures[i] > temperatures[stack.top()]` uses a strict inequality. The duplicate elements will remain in the stack until a strictly greater temperature is encountered.