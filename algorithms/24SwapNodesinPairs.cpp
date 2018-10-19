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
    ListNode* swapPairs(ListNode* head) {
        //双指针
         ListNode **pp = &head;
		 ListNode*a, *b;
		 while ((a=*pp)&&(b=a->next))
		 {
			 a->next = b->next;
			 b->next = a;
			 *pp = b;
			 pp = &(a->next);
		 }
        return head;
    }
};
