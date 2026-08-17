# 876. Middle of the Linked List

## Problem Description
We need to find and return the middle node of a given singly linked list. If the list has an odd number of nodes, there is a single clear middle node. If the list has an even number of nodes, there are two middle nodes, and the goal is to return the second one.

## Approach
This problem can be efficiently solved in a single pass using the **Two-Pointer (Tortoise and Hare)** technique. 

We initialize two pointers, `slow` and `fast`, both pointing to the `head` of the linked list. During each iteration:
- The `slow` pointer moves forward by one node (`slow = slow->next`).
- The `fast` pointer moves forward by two nodes (`fast = fast->next->next`).

Because the `fast` pointer travels twice as fast as the `slow` pointer, by the time `fast` reaches the end of the list (either pointing to `nullptr` or its next node is `nullptr`), `slow` will have reached exactly the middle node. This approach eliminates the need to measure the list's length first and then iterate again.

### C++ Code
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the linked list. We traverse the list at most once, with the loop running approximately $N / 2$ times.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we only use two pointer variables (`slow` and `fast`) to traverse the list.

## Edge Cases
- **Single Node List:** If the list contains only one node (e.g., `[1]`), the loop condition `fast->next != nullptr` is immediately false. The function correctly returns the `head` (the only node).
- **Two Nodes List:** For a list like `[1, 2]`, the loop runs once. `fast` becomes `nullptr` and `slow` advances to the second node (`2`). The loop terminates, returning the second node, which is correct since we need the second middle node for even-length lists.
- **Odd vs. Even Lengths:** 
  - For **odd-length** lists (e.g., `[1, 2, 3]`), the loop terminates when `fast->next` is `nullptr`.
  - For **even-length** lists (e.g., `[1, 2, 3, 4]`), the loop terminates when `fast` is `nullptr`. 
  The termination condition `fast != nullptr && fast->next != nullptr` handles both of these cases seamlessly.