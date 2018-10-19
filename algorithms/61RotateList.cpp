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
    ListNode* rotateRight(ListNode* head, int k) {
        //首先k对链表长度取模，然后再进行处理
        if (!head || !head->next) return head;
        int len=0; //计算链表长度
        ListNode *l1=head;
        while(l1){
            len++;
            l1=l1->next;
        }
        k%=len;
        if (k==0) return head;
        
        ListNode *ans=head;
        int n=len-k-1;
        while(n--) ans=ans->next;
        ListNode *temp=ans;
        ans=ans->next;
        temp->next=NULL;
        ListNode *result=ans;
        while(ans->next) ans=ans->next;
        cout<<ans->val;
        ans->next=head;
        
        return result;    
    }
};
