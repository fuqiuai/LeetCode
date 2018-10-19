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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=0; //计算链表长度
        ListNode *l1=head;
        while(l1){
            len++;
            l1=l1->next;
        }
        if (len<=1) {head=NULL;return head;}//特殊情况1：只有一个节点
        if (len==n) {head=head->next;return head;}//特殊情况2：删除的是第一个节点
        
        int count=0; //找到倒数第n+1个节点
        ListNode *pos=head;
        while(pos && count<len-n-1){
            pos=pos->next;
            count++;
        }
        
        ListNode *q=pos->next; //删除倒数第n个节点（q位置）
        pos->next=q->next;
        delete q;
        
        return head;
    }
};
