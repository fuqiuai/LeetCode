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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //分三步：(1)将链表中的数字转化成字符串形式 (2)两个字符串相加 (3)将相加的结果放入链表中
        
        string num1,num2;//(1)将链表中的数字转化成字符串形式
        while(l1){
            num1+=(l1->val+'0');
            l1=l1->next;
        }
        while(l2){
            num2+=(l2->val+'0');
            l2=l2->next;
        }
        
        string result=addStrings(num1,num2);//(2)两个字符串相加
        
        ListNode *head=new ListNode(0);//(3)将相加的结果放入链表中
        ListNode *tail=head;
        for (int i=0;i<result.size();i++){  
            tail=tail->next=new ListNode(0);
            tail->val=(result[i]-'0');
        }
        return head->next;
    }

private:
    string addStrings(string num1, string num2) {
        // 415. 字符串相加
        string a=num1,b=num2;
        int len=max(a.size(),b.size());//补零
        if (a.size()<len){
            int temp=len-a.size();
            while(temp--){
                a+='0';
                for (int i=a.size()-1;i>=1;i--)
                    a[i]=a[i-1];
                a[0]='0';
            }
        }
        if (b.size()<len){
            int temp=len-b.size();
            while(temp--){
                b+='0';
                for (int i=b.size()-1;i>=1;i--)
                    b[i]=b[i-1];
                b[0]='0';
            }
        }
                
        int add=0;//进位
        string result(len,'0');
        for (int i=len-1;i>=0;i--){
            int temp=(a[i]-'0')+(b[i]-'0');
            result[i]=add+temp%10+'0';
            add=(result[i]-'0')/10+temp/10;
            result[i]=(result[i]-'0')%10+'0';
        }
        if (add==1){
            result+='0';
            for (int i=result.size()-1;i>=1;i--)
                    result[i]=result[i-1];
                result[0]='1';
        }
        return result;
    }
};
