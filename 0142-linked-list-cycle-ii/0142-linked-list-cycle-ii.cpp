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

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Step 2: Find cycle starting point
                ListNode* entry = head;

                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        // No cycle
        return nullptr;
    }
};