# 2. Add Two Numbers

## Problem Description
The problem asks us to add two non-negative integers represented as singly-linked lists, where each node contains a single digit. The digits are stored in reverse order, meaning the head of the list represents the least significant digit (the ones place). We need to perform standard addition on these two numbers and return the resulting sum as a new linked list, also structured in the same reversed format.

---

## Approach
The solution uses an iterative schoolbook addition algorithm (column-by-column addition) starting from the least significant digit (the head of the lists) and moving towards the most significant.

1. **Dummy Head Pointer**: We initialize a `dummy` node to act as the anchor for the result list. A `temp` pointer is used to build and traverse the new list.
2. **Carry Initialization**: We maintain an integer variable `carry` (initially set to `0`) to handle cases where the sum of two digits exceeds `9`.
3. **Iterative Traversal**: We run a `while` loop that continues as long as there is still a node to process in `l1`, a node to process in `l2`, or a remaining `carry` that needs to be appended as a new digit.
4. **Digit Summation**: 
   - In each iteration, we calculate `sum` by adding the values of the current nodes of `l1` and `l2` (if they are not null) along with the existing `carry`.
   - We update `carry` to `sum / 10`.
   - We create a new node with the value of `sum % 10` and link it to our result list (`temp->next`).
   - We advance the pointers (`l1`, `l2`, and `temp`) where applicable.
5. **Return Result**: Once the loop terminates, we return `dummy->next`, which points to the head of the newly constructed sum list.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\max(N, M))$, where $N$ is the number of nodes in `l1` and $M$ is the number of nodes in `l2`. We iterate through both lists at most once.
- **Space Complexity:** $\mathcal{O}(\max(N, M))$ to store the output linked list. The length of the new list is at most $\max(N, M) + 1$. Excluding the space required for the output list, the auxiliary space complexity is $\mathcal{O}(1)$ as we only use a few pointers and temporary variables.

---

## Edge Cases Handled
* **Lists of Different Lengths:** The algorithm gracefully handles lists of unequal sizes (e.g., adding $999$ and $9$) by checking if a list pointer is null before accessing its value. If one list is exhausted, it is treated as having a value of `0` for the remaining iterations.
* **Final Carry Overflow:** For additions like $99 + 1 = 100$, the carry needs to propagate to a new node even after both lists have been fully traversed. The condition `while (carry || ...)` ensures that the loop runs one final time to append the leftover carry of `1`.
* **Zero Values:** If both lists represent $0$ (e.g., `l1 = [0]` and `l2 = [0]`), the loop executes exactly once, producing a single-node list `[0]`.