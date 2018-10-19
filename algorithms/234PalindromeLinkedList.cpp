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
    bool isPalindrome(ListNode* head) {
        //思路：把后半段的链表原地反转(反转见第206题)然后和前半段进行比较
        
        if (!head || !head->next) return true;
        //找到后半段的起点
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //反转后半段
        ListNode *new_head=NULL;
        ListNode *temp=NULL;
        while(slow){
            temp = slow->next;
            slow->next = new_head;
            new_head = slow;
            slow = temp;
        }
        //前半段与后半段进行比较
        while(head && new_head){
            if (head->val!=new_head->val) return false;
            head=head->next;
            new_head=new_head->next;
        }
        return true;
    }
};
