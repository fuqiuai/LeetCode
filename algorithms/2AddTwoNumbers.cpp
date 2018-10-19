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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *tail=head;
        
        int add=0;//进位
        while(l1 || l2){
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            int temp=x+y+add;
            tail=tail->next=new ListNode(0);
            tail->val=temp%10;
            add=temp/10;
            
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        //处理最后可能的进位
        if (add){
            tail=tail->next=new ListNode(0);
            tail->val=add;
        }
        
        return head->next;
    }
};
