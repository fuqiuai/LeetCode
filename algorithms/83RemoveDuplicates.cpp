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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;//特殊情况，空链表
        ListNode *tail=head;
        while(tail->next){
            ListNode *p=tail->next;
            bool flag=true;
            if (tail->val==p->val){ //删除p
                if (!p->next) tail->next=NULL; //p为表尾时
                else tail->next=p->next;
                delete p;
                flag=false;
            }
            if(flag && tail->next) tail=tail->next;
        }
        return head;
    }
};
