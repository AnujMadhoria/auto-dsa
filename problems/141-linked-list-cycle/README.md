# 141. Linked List Cycle

## Problem Description

The goal is to determine whether a given singly-linked list contains a cycle. A cycle exists if there is some node in the list that can be reached again by continuously following the `next` pointer. We need to return `true` if a cycle is present in the linked list, and `false` if the list terminates normally with a `nullptr`. To meet the optimal follow-up requirements, this should be solved using constant $O(1)$ extra memory.

## Approach

This solution utilizes **Floyd's Cycle-Finding Algorithm** (also known as the **Tortoise and Hare** algorithm). 

1. **Two Pointers**: We initialize two pointers, `slow` and `fast`, both starting at the `head` of the linked list.
2. **Different Speeds**: We traverse the list by moving the `slow` pointer one step at a time (`slow = slow->next`) and the `fast` pointer two steps at a time (`fast = fast->next->next`).
3. **Cycle Detection**:
   * If there is no cycle, the `fast` pointer will eventually reach the end of the list (`nullptr`), and we can safely return `false`.
   * If there is a cycle, the `fast` pointer will enter the loop first and begin running in circles. Eventually, because it moves faster, it will catch up to and "lap" the `slow` pointer. 
   * In this implementation, the condition `if (fast->next == slow)` is used to detect that the two pointers have met (or are about to meet), signaling a cycle and returning `true`.

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            if (fast->next == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the linked list. 
  - If there is no cycle, the `fast` pointer reaches the end of the list in $N/2$ steps.
  - If there is a cycle, the `fast` pointer will catch up to the `slow` pointer in at most $N$ steps after both pointers enter the cycle.
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm only uses two pointer variables (`slow` and `fast`) regardless of the size of the linked list, satisfying the constant memory requirement.

## Edge Cases Handled

1. **Empty List (`head == nullptr`)**: The `while` loop condition `fast != nullptr` is immediately violated, and the function correctly returns `false`.
2. **Single Node without a Cycle**: The condition `fast->next != nullptr` is violated immediately, returning `false`.
3. **Single Node with a Cycle (points to itself)**: `fast->next` points to `slow` (itself) on the first check, correctly returning `true`.
4. **Two Nodes with/without a Cycle**: Handled correctly as the pointers either hit the end or meet within the first few operations.