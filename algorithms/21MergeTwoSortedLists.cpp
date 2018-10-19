// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };

//具体思想就是新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中

// 设p是指向结构体变量的指针，则可以通过以下的方式，调用指向的那个结构体中的成员：
// （1）结构体变量.成员名。如，stu.num。
// （2）(*p).成员名。如，(*p).num。
// （3）p->成员名。如，p->num。

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *tail=head;
        while(l1 && l2){
            if (l1->val<=l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if (l1) tail->next=l1;
        if (l2) tail->next=l2;
        
        return head->next;
            
    }
};
