#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "csl210_lab1.h"

nodeQ_t *convertSparseMatrixToLinkedList(unsigned short **matrix, unsigned short rows, unsigned short columns)
{
	nodeQ_t *sparsed_list_head = EMPTYNODE;
	nodeQ_t *temp_list;
	nodeQ_t *temp_list2 = EMPTYNODE;
	nodeQ_t *main_head = (nodeQ_t *)malloc(sizeof(nodeQ_t));
	int val = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			if (0 != matrix[i][j])
			{
				if (EMPTYNODE == sparsed_list_head)
				{
					sparsed_list_head = (nodeQ_t *)malloc(sizeof(nodeQ_t));
					sparsed_list_head->value = matrix[i][j];
					sparsed_list_head->row = i;
					sparsed_list_head->column = j;
					temp_list2 = sparsed_list_head;
					val++;
				}
				else
				{
					temp_list = (nodeQ_t *)malloc(sizeof(nodeQ_t));
					temp_list->value = matrix[i][j];
					temp_list->row = i;
					temp_list->column = j;
					temp_list->next = NULL;
					temp_list2->next = temp_list;
					temp_list2 = temp_list;
					val++;
				}
			}
		}
	}
	main_head->next = sparsed_list_head;
	main_head->value = val;
	main_head->column = columns;
	main_head->row = rows;

	return main_head;
}

nodeQ_t *multiplySparseMatricesLinkedLists(nodeQ_t *matrix_llist_1, nodeQ_t *matrix_llist_2)
{

    nodeQ_t *head1 = matrix_llist_1->next;
    nodeQ_t *head2 = matrix_llist_2->next;

    nodeQ_t *head3 = NULL;
    head3 = (nodeQ_t *)malloc(sizeof(nodeQ_t));
    head3->row = matrix_llist_1->row;
    head3->column = matrix_llist_2->column;
    head3->value = 0;
    head3->next = NULL;

    nodeQ_t *check = NULL;
    nodeQ_t *front = NULL;
    nodeQ_t *end = NULL;

    if (matrix_llist_1->column != matrix_llist_2->row)
    {
        return NULL;
    }
    while (head2)
    {
        while (head1)
        {
            if (head1->column == head2->row)
            {

                int flag = 0;
                check = front;

                while (check != NULL)
                {
                    if (check->row == head1->row && check->column == head2->column)
                    {
                        check->value += head1->value * head2->value;
                        flag = 1;
                    }
                    end = check;
                    check = check->next;
                }

                if (flag == 0)
                {
                    nodeQ_t *temp = NULL;
                    temp = (nodeQ_t *)malloc(sizeof(nodeQ_t));
                    head3->value=0;
                    temp->row = head1->row;
                    temp->column = head2->column;
                    temp->value = head1->value * head2->value;
                    temp->next = NULL;
                    
                    if (end != NULL)
                    {
                        end->next = temp;
                    }
                    if (front == NULL)
                    {
                        front = temp;
                    }
                }
            }
            head1 = head1->next;
        }
        head2 = head2->next;
        head1= matrix_llist_1->next;
    }
    head3->next = front;
    return head3;
}

void insertPriorityHashTable(priorityNodeQ_t *item)
{

	int idx = hashFuncLab1(item->value);
	priorityNodeQ_t *hold = item;
	priorityNodeQ_t *check, *head = EMPTYNODE;
	int x = 0;

	if (0 == g_priorityHashTable[idx])
	{
		g_priorityHashTable[idx] = item;
		item->next = EMPTYNODE;
	}

	else if (0 != g_priorityHashTable[idx])
	{

		head = g_priorityHashTable[idx];
		
		priorityNodeQ_t *prev = EMPTYNODE;
		check = head;
		prev = head->next;
		priorityNodeQ_t *lol = head;

		if (head == EMPTYNODE )

		{
			g_priorityHashTable[idx] = item;
		head=g_priorityHashTable[idx];
		}

		else
		{
			if (head->priority >= item->priority)
			{
				if(head->priority==item->priority){
					priorityNodeQ_t*hulk;
               while(head->priority==item->priority){
				   hulk=head;
             head=head->next;
			 hulk->next=head;
			   }
			   hulk->next=item;
			   item->next=head;

				}
			   else{
                g_priorityHashTable[idx]=item;
                item->next=head;
                head=item;}
                
				
			}

            else{

			while (prev)
			{

				if (prev->priority > item->priority)
				{
					item->next = prev;
					lol->next = item;
					x = 1;
				}

				prev = prev->next;
				lol = lol->next;
			}

			if (x == 0)
			{

				lol->next = item;
				item->next = EMPTYNODE;
			}
		}}
	}
}

priorityNodeQ_t *dequeueFromPriorityHashTable(unsigned short key)
{

	int idx = hashFuncLab1(key);

	if (g_priorityHashTable[idx] != EMPTYNODE)
	{
		priorityNodeQ_t *head = NULL;
		head = g_priorityHashTable[idx];
		g_priorityHashTable[idx] = head->next;
		return head;
		free(head);
	}
	else
	{
		return NULL;
	}
}




