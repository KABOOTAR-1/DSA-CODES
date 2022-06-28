#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* ans=NULL;
        ListNode* tail= new ListNode();
        int answer=0,carry=0;
      while(head1 || head2 || carry)
      {
         int x = (head1 != NULL) ? head1->val : 0;
        int y = (head2 != NULL) ? head2->val : 0;
        answer=((x+y) + carry)%10;
        ListNode* newNode=new ListNode();
           newNode->val=answer;
        if(ans==NULL)
        {
           ans=newNode;
           tail=ans;
        }else
        {
           tail->next=newNode;
           tail=tail->next;
        }

        carry=((x+y) + carry)/10;
  if(head1)head1=head1->next;
  if(head2)head2=head2->next;

}


return ans;
   
    }
};

int main()
{
    Solution s;

    ListNode* l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);

    ListNode* l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);

    s.addTwoNumbers(l1,l2);
}