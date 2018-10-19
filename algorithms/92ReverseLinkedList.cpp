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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n || !head->next) return head;
        //(1)反转位置 m 到 n 的链表
        ListNode *begin=head; //找到反转开始的位置
        int count=1;
        while(count<m){
            count++;
            begin=begin->next;
        }
        ListNode *new_head=NULL;//进行反转
        ListNode *temp=NULL;
        int num=n-m+1;
        while(num--){
            temp = begin->next;
            begin->next = new_head;
            new_head = begin;
            begin = temp;
        }
        
        //(2)连接三段链表
        ListNode *pummyhead=head;
        if (m>1){
            while(head->next->next) head=head->next;
            head->next=new_head; 
        }
        else{
            pummyhead=new_head;
        }
        while(new_head->next) new_head=new_head->next;
        new_head->next=temp;
        
        return pummyhead;
    }
};
