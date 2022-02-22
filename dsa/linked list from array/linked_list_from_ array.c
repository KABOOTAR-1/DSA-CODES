#include<stdio.h>
#include<stdlib.h>
#include "csl102_th2.h"


nodeQ_t* addnode(short values) {
    nodeQ_t* newnode=(nodeQ_t*)malloc(sizeof(nodeQ_t));
    newnode->data=values;
    newnode->next=EMPTYNODE;
    return newnode;
}

int appendnode(nodeQ_t *tail,nodeQ_t *newnode){

    if(EMPTYNODE==newnode|| EMPTYNODE==tail)return 0;

    tail->next=newnode;
    return 1;
}

status_t isdatapresent(nodeQ_t*new,short data){
if(EMPTYNODE==new)return LIST_FALSE;

while(new){
    
    if(data==new->data){
      return LIST_TRUE;
    } new=new->next;
}

}

nodeQ_t* createList(short values[],short sz){

    nodeQ_t *head= EMPTYNODE;
    nodeQ_t *newnode=EMPTYNODE;
    nodeQ_t *tail=EMPTYNODE;

    for(int i=0;i<sz;i++){
       
        newnode=addnode(values[i]);
        if(EMPTYNODE==head){
           
            head=newnode;
            tail=head;
        }
    else{
        
         appendnode(tail,newnode);
        tail=newnode;
    } 
   } 
   return head;
}

status_t deleteNodes(nodeQ_t* head, nodeQ_t** out_newHead, short in_data)
{
    nodeQ_t* curr=EMPTYNODE,*add=EMPTYNODE;
    if(head==EMPTYNODE)
    return LIST_FALSE;
    
    *out_newHead=head;
    int counter =0;
    add=head;
    curr=head->next;
    while(curr!=EMPTYNODE)
    {
    if(head->data==in_data)
    {
        *out_newHead=head->next;
        head=head->next;
        counter++;
    }
    else if(curr->data == in_data)
    {
        add->next = curr->next;
        counter++;
    }

        add = curr;
        curr = curr->next;
    }
    if(counter)
    {
        return LIST_TRUE;
    }
else return LIST_FALSE;
}
status_t splitLists(nodeQ_t* head, nodeQ_t** out_evenList, nodeQ_t** out_oddList){

if(EMPTYNODE==head){
    return  LIST_FALSE;
}

nodeQ_t *first=head;
nodeQ_t*second =head->next;
nodeQ_t *temp1=head;
nodeQ_t *temp2=head->next;
int index=0;
while(temp1->next && temp2->next){
   
    if(0==index%2){
temp1->next=EMPTYNODE;
temp1->next=temp2->next;
temp1=temp1->next;
    }
    else{
        temp2->next=EMPTYNODE;
        temp2->next=temp1->next;
        temp2=temp2->next;
    }
    index++;
}
temp1->next=EMPTYNODE;
temp2->next=EMPTYNODE;

*out_evenList=first;
    *out_oddList=second;
    return LIST_TRUE;

}
status_t getCommonSubList(nodeQ_t* head1, nodeQ_t* head2, nodeQ_t** out_commonSubList){

if(EMPTYNODE==head1|| EMPTYNODE==head2)return LIST_FALSE;

    nodeQ_t*list1=head1;
    nodeQ_t* list2=head2;
    nodeQ_t*temp1,*temp2,*tail=EMPTYNODE;
*out_commonSubList=EMPTYNODE;
    nodeQ_t*newnode;
    int i=0;
    

    while(list2){
        while(list1){
            temp1=list1;
            temp2=list2;

        if(list1->data==list2->data){
        while(list1->data==list2->data){
            newnode=(nodeQ_t*)malloc(sizeof(nodeQ_t));
            newnode->data=list2->data;
            newnode->next=EMPTYNODE;
            if(EMPTYNODE==*out_commonSubList){
                *out_commonSubList=newnode;
                tail=newnode;
                 }
            else{
                tail->next=newnode;
                tail=newnode;
            }
            list1=list1->next;
            list2=list2->next;
            i++;
            if(list1==EMPTYNODE||list2==EMPTYNODE){
                break;
            }
        }
        if(i>=2){
             return LIST_TRUE;
        }
        else{
            i=0;
            *out_commonSubList=EMPTYNODE;
            free(newnode);
            list1=temp1;
            list2=temp2;
        }

        }
        list1=list1->next;
        }
        list2=list2->next;
        list1=head1;
    }
   return LIST_FALSE;
    }

