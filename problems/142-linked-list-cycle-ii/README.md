# 142. Linked List Cycle II

## Problem Description

Given the head of a singly linked list, determine if there is a cycle in the list. If a cycle exists, return the specific node where the cycle begins; if there is no cycle, return `nullptr`. A cycle exists if any node can be reached again by continuously following the `next` pointer. Do not modify the original linked list, and aim to solve the problem using $O(1)$ auxiliary space.

---

## Approach: Floyd's Cycle Finding Algorithm (Tortoise and Hare)

This problem can be efficiently solved in two phases using two pointers moving at different speeds.

### Phase 1: Cycle Detection
1. Initialize two pointers, `slow` and `fast`, at the `head` of the linked list.
2. Move `slow` by one step (`slow = slow->next`) and `fast` by two steps (`fast = fast->next->next`).
3. If `fast` or `fast->next` becomes `nullptr`, the list has no cycle, and we return `nullptr`.
4. If `slow` and `fast` meet at the same node, a cycle exists. Proceed to Phase 2.

### Phase 2: Finding the Cycle Start
To find where the cycle begins, we use the mathematical relationship of the pointers' traversal distances:
* Let $L_1$ be the distance from the head of the list to the start of the cycle.
* Let $L_2$ be the distance from the start of the cycle to the meeting point.
* Let $C$ be the total length of the cycle.

When the pointers meet:
* The distance traveled by `slow` is $L_1 + L_2$.
* The distance traveled by `fast` is $L_1 + L_2 + n \cdot C$ (where $n$ is the number of full loops completed by the fast pointer).

Since `fast` travels twice as fast as `slow`:
$$2(L_1 + L_2) = L_1 + L_2 + n \cdot C$$
$$L_1 + L_2 = n \cdot C$$
$$L_1 = n \cdot C - L_2$$

This equation tells us that the distance from the head to the start of the cycle ($L_1$) is equal to the distance from the meeting point to the start of the cycle (taking into account full cycle laps). 

Thus, we can find the start of the cycle by:
1. Resetting `slow` back to the `head` of the list.
2. Keeping `fast` at the meeting point.
3. Moving both `slow` and `fast` forward one node at a time.
4. The node where they meet again is the exact start of the cycle.

---

## C++ Solution

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            // Cycle detected
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the linked list. 
  - In Phase 1, the fast pointer will meet the slow pointer in less than $N$ iterations if a cycle exists.
  - In Phase 2, the pointers travel at most $N$ steps to meet at the start of the cycle.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. Only two pointers are maintained, satisfying the constant memory constraint.

---

## Edge Cases

1. **Empty List (`head == nullptr`)**: The loop condition `fast != nullptr` immediately fails, and the function correctly returns `nullptr`.
2. **Single Node without Cycle**: `fast->next` is `nullptr`, so the loop terminates immediately and returns `nullptr`.
3. **Single Node with a Self-Cycle**: `fast` and `slow` will meet at the single node. `slow` resets to `head` (which is already the meeting point), the nested loop terminates instantly, and the node itself is correctly returned.
4. **Entire List is a Cycle**: If the tail connects back to the head, the entry point is the head itself. The algorithm handles this seamlessly since $L_1 = 0$.