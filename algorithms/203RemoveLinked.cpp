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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pummyhead=new ListNode(-1);
        pummyhead->next=head;
        ListNode *begin=pummyhead;
        while(begin->next){
            ListNode *end=begin->next;
            if (end->val==val){
                if (!end->next) begin->next=NULL;
                else begin->next=end->next;
            }
            else
                begin=begin->next;
            
        }
        return pummyhead->next;
    }
};
