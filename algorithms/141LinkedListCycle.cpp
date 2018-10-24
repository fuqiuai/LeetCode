/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         //方法1，自己想的方法
//         if (!head) return false;
//         int k=10000;
//         while(head && k--){
//             head=head->next;
//         }
//         if (k==-1) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //方法2，参考的方法
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) //只要有环，那么fast与slow一定会撞上的
                return true;
        }
        return false;
    }
};
