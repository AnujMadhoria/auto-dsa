# 21. Merge Two Sorted Lists

## Problem Description
The goal is to take two sorted linked lists, `list1` and `list2`, and merge them into a single, continuously sorted linked list. Instead of creating brand new nodes and copying the values, the merge must be done in-place by splicing the existing nodes together by rearranging their pointers. The function should ultimately return the head of this newly merged sorted list.

## Approach
The solution uses an **iterative two-pointer approach** aided by a **dummy node**:

1. **Base Cases**: The code first handles scenarios where one or both of the input lists are empty. If either list is null, it immediately returns the other list.
2. **Dummy Node Initialization**: A sentinel or "dummy" node is created to act as a placeholder head for the merged list. This simplifies edge cases because we do not have to write special logic to initialize the head of our merged list. A tracker pointer `temp` is set to point to this dummy node.
3. **Comparison Loop**: We traverse both lists simultaneously using a `while` loop that runs as long as both lists have remaining nodes:
   - We compare the values at the current nodes of `list1` and `list2`.
   - The smaller value's node is linked to `temp->next`.
   - We then advance the pointer of the list from which we took the node.
   - Finally, we advance the `temp` pointer to continue building the chain.
4. **Appends Remaining Nodes**: Once one of the lists is fully exhausted, the loop terminates. Because the original lists were already sorted, any remaining nodes in the non-empty list can simply be appended to the end of our merged list in a single step (`temp->next = remaining_list`).
5. **Return Result**: The actual merged list starts right after the dummy node, so we return `dummy->next`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + M)$, where $N$ and $M$ are the number of nodes in `list1` and `list2` respectively. In the worst-case scenario, we must traverse and compare every node in both lists.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The algorithm merges the lists in-place by updating pointer references. Only a single dummy node and a few pointer variables are allocated, consuming constant extra memory.

## Edge Cases
- **Both lists are empty (`list1 = []`, `list2 = []`):** Handled by the initial check, returning `nullptr`.
- **One list is empty, the other is not (`list1 = []`, `list2 = [1, 3]`):** The algorithm immediately appends the non-empty list to the dummy node and returns it.
- **Lists of different sizes:** The `while` loop processes elements until the shorter list is exhausted, and the remaining portion of the longer list is correctly appended in $\mathcal{O}(1)$ time.
- **Lists with duplicate values:** The `<=` operator handles duplicates gracefully by preserving their relative order.