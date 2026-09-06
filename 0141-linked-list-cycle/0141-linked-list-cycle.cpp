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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            if(fast->next) fast=fast->next->next;
            else return 0;
            if(slow) slow=slow->next;

            if(fast==slow) return 1;
        }
        return 0;
    }
};