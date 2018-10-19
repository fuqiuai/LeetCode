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
    ListNode* reverseList(ListNode* head) {
        //递归法
        // if (!head || !head->next) return head;
        // ListNode *res = reverseList(head->next);
        // head->next->next=head;
        // head->next=NULL;
        // return res;
        
        //迭代法
        if (!head || !head->next) return head;
        ListNode *new_head=NULL;
        ListNode *temp=NULL;
        while(head){
            temp = head->next;//备份head->next
            head->next = new_head;//更新head->next
            new_head = head;//移动new_head
            head = temp;//遍历链表
        }
        return new_head;//返回新链表头节点

    }
};
