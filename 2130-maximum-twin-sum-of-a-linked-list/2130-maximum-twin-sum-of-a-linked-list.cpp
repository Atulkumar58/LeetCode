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
    int pairSum(ListNode* head) {
        int length=0;
        ListNode* curr= head;
        while(curr){
            curr= curr->next;
            length++;
        }
        stack<int> s;
        curr = head;
        int temp= length/2;
        while(temp--){
            s.push(curr->val);
            curr= curr->next;
        }
        // if(length%2 == 1) curr= curr->next;
        int ans= 0;
        while(curr){
            ans= max(ans, curr->val + s.top());
            s.pop();
            curr= curr->next;
        }
        return ans;
    }
};