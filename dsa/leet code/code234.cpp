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

class Solution
{

    ListNode *half(ListNode *head)
    {
        ListNode *first = head;
        ListNode *second = head;

        while (second->next != NULL && second->next->next != NULL)
        {
            second = second->next->next;
            first = first->next;
        }
        return first;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode* firsthalfend = half(head);
        ListNode* secondhalfstart=reverseList(firsthalfend->next);
        ListNode* p1=head;
        
        while(p1 && secondhalfstart!=NULL){
            if(p1->val!=secondhalfstart->val) return false;
           p1=p1->next;
           secondhalfstart=secondhalfstart->next;

        }
        return true;
    }
};

int main(){
    Solution s;

    ListNode* one = (struct ListNode*) malloc(sizeof(struct ListNode));
    one->val=1;
    ListNode* two =(struct ListNode*) malloc(sizeof(struct ListNode));;
    two->val =2;
    ListNode* three =(struct ListNode*) malloc(sizeof(struct ListNode));;
    three->val =2;
     ListNode* four = (struct ListNode*) malloc(sizeof(struct ListNode));;
    four->val=1;

    one->next=two;
    two->next=three;
    three->next=four;
    four->next=NULL;

    s.isPalindrome(one);
    
    

}