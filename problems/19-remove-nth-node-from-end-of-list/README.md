# Remove Nth Node From End of List

## Problem Description
The objective is to remove a specific node from a singly-linked list by counting backward from the end of the list. Given the head of the list and an integer $n$, we need to locate and delete the $n$-th node from the tail (where $n = 1$ refers to the very last node, $n = 2$ refers to the second-to-last node, and so on) and return the head of the modified list. This must be completed efficiently, ideally in a single traversal of the list.

## Approach
This solution uses the **Two-Pointer (or Sliding Window) technique** to achieve a one-pass traversal:

1. **Create a Gap**: We initialize two pointers, `first` and `second`, at the head of the list. We advance the `first` pointer $n$ steps forward. This establishes a constant gap of $n$ nodes between the two pointers.
2. **Handle Head Removal**: If the `first` pointer becomes `nullptr` after moving $n$ steps, it indicates that the list has exactly $n$ nodes. Consequently, the node to be removed is the head itself. In this case, we simply return `head->next`.
3. **Simultaneous Traversal**: If `first` is not `nullptr`, we move both `first` and `second` pointers forward one node at a time until `first` reaches the last node of the list (`first->next == nullptr`). 
4. **Deletion**: Because of the maintained $n$-node gap, when `first` reaches the last node, `second` will point to the node **immediately preceding** the target node. We then bypass the target node by updating `second->next` to point to `second->next->next`.

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        // Move first pointer n steps ahead
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        // If first reached the end, we need to remove the head node
        if (first == nullptr) {
            return head->next;
        }

        // Move both pointers until first reaches the last node
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Skip the nth node from the end
        second->next = second->next->next;

        return head;
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the linked list. The list is traversed exactly once, satisfying the follow-up constraint for a single-pass solution.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The algorithm only uses two pointer variables (`first` and `second`) to keep track of positions, requiring no additional memory allocations.

## Edge Cases

- **Single-Node List ($sz = 1, n = 1$):**
  If the list contains only one node and we want to remove it, `first` moves $1$ step and becomes `nullptr`. The code correctly identifies this and returns `head->next` (which is `nullptr`), effectively clearing the list.
  
- **Removing the Head Node ($n = sz$):**
  When removing the first node of a multi-node list, `first` will walk off the end of the list and become `nullptr` during the initial loop. The condition `first == nullptr` triggers, returning `head->next` and safely discarding the original head.

- **Removing the Last Node ($n = 1$):**
  When deleting the last node, the `while` loop runs until `first` is at the last element, placing `second` at the second-to-last element. Setting `second->next = second->next->next` updates the pointer to `nullptr`, cleanly severing the last node.