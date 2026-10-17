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
    ListNode* rotateRight(ListNode* head, int k) {
               if (head == NULL || head->next == NULL)
            return head;
        ListNode* last = head;
        int count = 1;
        
        while(last->next!=NULL){
            last = last->next;
            count++;
        }
        int newk = k%count;
          if (newk == 0)
            return head;
        int n = count - newk ;
       
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(n--){
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
        last->next = head;

        return temp2;
    }
};