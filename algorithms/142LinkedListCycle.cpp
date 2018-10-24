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
    ListNode *detectCycle(ListNode *head) {
        //在141. 环形链表的基础上改进，重样采取双指针，出现重复之后，
        //慢指针返回到头结点，快指针继续，两者每次都走一步，直到相遇，相遇的地方就是环的第一个节点了
                ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){  //有环，找到第一个节点
                slow=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
