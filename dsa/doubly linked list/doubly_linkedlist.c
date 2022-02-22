#include"csl102_lab7.h"
#include<stdlib.h>
#include<stdio.h>
/**
 * Example doubly linked list
 * 	   HEAD						   			    TAIL
 * 		|										 |
 * [2,5,1,6] <=> [4,7,8,9] <=> [0,3,6,3] <=> [43,7,32,7] <=> EMPTYNODE
 * */

/**
 * Method to create a node by passing an array. 
 * Create a node on the heap memory and return the address
 **/
nodeQ_t* createNode(short values[4])
{
    nodeQ_t* A_node = (nodeQ_t*)malloc(sizeof(nodeQ_t));
    for (short i = 0; i < 4; i++)
    {
        A_node->data[i]=values[i];
    }

    A_node->next = EMPTYNODE;
    A_node->prev = EMPTYNODE; 
    return A_node;

}
status_t deleteNode(nodeQ_t *head, nodeQ_t **out_newHead, short value)
{

    if (head == EMPTYNODE)
        return LIST_FALSE;

    nodeQ_t *node = head;
    short x = 0;

    while (node != EMPTYNODE)
    {
        for (int i = 0; i < 4; i++)
        {

            if (head->data[i] == value)
            {

                if (head->next == EMPTYNODE)
                {
                    x++;
                    nodeQ_t *T_Node1 = head;
                    head = EMPTYNODE;
                    free(T_Node1);
                    break;
                }
                else
                {
                    x++;
                    nodeQ_t *T_Node1 = head;
                    head = head->next;
                    head->prev = EMPTYNODE;
                    free(T_Node1);
                    break;
                }
            }
            else if (node->data[i] == value)
            {
                x++;
                if (node->next == EMPTYNODE)
                {
                    nodeQ_t *T_Node1 = node;
                    node = node->prev;
                    node->next = EMPTYNODE;

                    free(T_Node1);
                    break;
                }
                else
                {
                    x++;
                    nodeQ_t *T_Node1 = node;
                    node = node->prev;
                    node->next = T_Node1->next;
                    T_Node1->next->prev = node;

                    free(T_Node1);
                    break;
                }
            }
        }

        node = node->next;
    }

    *out_newHead = head;

    if(x)
    return LIST_TRUE;
    else
    return LIST_FALSE;
}

status_t appendNode(nodeQ_t* head, nodeQ_t* newNode)
{
    if (newNode==EMPTYNODE || head==EMPTYNODE){
        return LIST_FALSE;
    }
    
    else
    {
        nodeQ_t* T_Node = head;
        while (T_Node->next != EMPTYNODE)
        {
            T_Node = T_Node->next;
        }
        
        newNode->prev = T_Node;
        if(T_Node!=EMPTYNODE)
        {
            T_Node->next = newNode;
        }
        T_Node = newNode;
        newNode->next = EMPTYNODE;
        return LIST_TRUE;
    }

}

status_t prependNode(nodeQ_t* head, nodeQ_t* newNode)
{

    if (newNode==EMPTYNODE || head==EMPTYNODE)return LIST_FALSE;

    else{
    newNode->next = head;
    if(head!=EMPTYNODE)
    {
        head->prev = newNode;
    }
    head = newNode;
    newNode->prev = EMPTYNODE;
    return LIST_TRUE;
    }
}





