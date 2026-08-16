# 206. Reverse Linked List

## Problem Description

The goal of this problem is to take a singly linked list and reverse the direction of all its pointers. Instead of starting at the head and moving forward to the tail, the list must be rearranged so that the original tail becomes the new head, and each node points backward to the node that originally preceded it.

## Approach (Iterative)

The provided solution uses an in-place **iterative** approach with three pointers to reverse the list efficiently without using extra memory:

1. **Initialize Pointers**: We maintain two primary pointers:
   * `curr`: Points to the node currently being processed (initialized to `head`).
   * `prev`: Points to the node immediately preceding `curr` (initialized to `nullptr`, which will eventually become the `next` pointer of the new tail).
2. **Traverse and Reconnect**: We iterate through the list using a `while` loop as long as `curr` is not null:
   * **Save the Next Node**: Before modifying any pointers, we store the next node in a temporary variable (`ListNode* temp = curr->next`). This step is crucial because changing `curr->next` will sever our connection to the rest of the list.
   * **Reverse the Pointer**: We point `curr->next` backward to `prev`.
   * **Move Forward**: We slide our tracking pointers forward by setting `prev` to `curr` and `curr` to `temp`.
3. **Return New Head**: Once `curr` becomes null, the traversal is complete. The `prev` pointer will be left pointing to the last node of the original list, which is now the head of the reversed list.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
```

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the number of nodes in the linked list. We traverse the list exactly once, performing constant-time $\mathcal{O}(1)$ operations at each node.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The reversal is done entirely in place, using only a few pointer variables (`prev`, `curr`, and `temp`) regardless of the size of the list.

## Edge Cases

- **Empty List (`head = nullptr`)**: The function immediately skips the `while` loop because `curr` is null, and returns `prev` (`nullptr`). This is correct.
- **Single-Node List**: The loop runs exactly once. The only node's `next` pointer is set to `nullptr` (reversing the trivial connection), and that same node is returned as the new head.
- **Large List (up to 5000 nodes)**: Because this solution is iterative, it runs in constant call-stack space and is not susceptible to stack overflow issues that recursive implementations might encounter with very deep recursion.