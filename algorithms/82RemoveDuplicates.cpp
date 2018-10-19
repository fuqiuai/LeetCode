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
//     ListNode* deleteDuplicates(ListNode* head) {
//         //方法1
//         if (!head || !head->next) return head;//特殊情况，空链表和只有一个元素的链表
//         ListNode *begin=new ListNode(-1);
//         begin->next=head;
//         ListNode *end=begin->next;
//         int ff=0;
//         while(end->next){
//             int count=0;
//             while (end->next && begin->next->val==end->next->val){
//                 end=end->next;
//                 count++;
//             }
//             if (count!=0){ //删除begin和end间的节点
//                 if (!end->next) begin->next=NULL; //end为表尾时
//                 else{
//                     begin->next=end->next;
//                     end=end->next;
//                 }
//             } 
//             else{
//                 begin=begin->next;
//                 ff++;
//                 if (ff==1) head=begin; //begin变化了，head移动一次指向队首，不加此行反例为[1,1,1,2,3]
//                 end=end->next;
//             }

//         }
//         if (ff==0) head=begin->next; //表示begin没变过，不加此行反例为[2,2,2,3,3,4]
//         return head;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //方法2
        if (!head || !head->next) return head;//特殊情况，空链表和只有一个元素的链表
        ListNode *dummyhead=new ListNode(-1);
        dummyhead->next=head;
        ListNode *begin=dummyhead;
        while(begin->next){
            ListNode *end=begin->next;
            while (end->next && end->val == end->next->val) end = end->next;
            if (begin->next!=end)
                begin->next=end->next;
            else
                begin=begin->next;
        }
 
        return dummyhead->next;
    }
};
