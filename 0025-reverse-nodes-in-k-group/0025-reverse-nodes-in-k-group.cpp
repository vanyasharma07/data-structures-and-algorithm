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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* start = head;
        ListNode* temp = head;

        // Find the new head after reversing first k nodes
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp;

        while (start != NULL) {

            // Find kth node of current group
            ListNode* end = start;

            for (int i = 1; i < k; i++) {
                if (end->next == NULL)
                    return newHead;

                end = end->next;
            }

            // Save the first node of next group
            ListNode* groupNext = end->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = start;

            while (curr != groupNext) {
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect current group with previous group
            if (start != head) {
                temp->next = end;
            }

            // start is now the tail of reversed group
            temp = start;

            // Move to next group
            start = groupNext;
        }

        return newHead;
    }
};