#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "csl102_lab6.h"

void getInorder(nodeQ_t* node, short **out_array, short *out_size)
{
  nodeQ_t *curr,*p;
  short size = *out_size;
  short *arr = (short*)malloc(size * sizeof(short));
  if(node == EMPTYNODE)
     return; 

  short i=0;
  curr = node;
  while(curr != EMPTYNODE)
  {
    if(curr->left == EMPTYNODE)
    {
      arr[i]= curr->data;
      i++;
      curr = curr->right;
    }
    else
    {
      p = curr->left;
      while(p->right != EMPTYNODE && p->right != curr)
        p = p->right;

      if(p->right == EMPTYNODE)
      {
        p->right = curr;
        curr = curr->left;
      }

      else
      {
        p->right = EMPTYNODE;
        arr[i]=curr->data;
        i++;
        curr = curr->right;
      } 
    } 
  } 
  *out_size = i;
  *out_array = arr;
  return;
}


void getPreorder(nodeQ_t* node, short **out_array, short *out_size)
{
  nodeQ_t* curr=node;
  short size = *out_size;
  short j=0;
  short *arr = (short*)malloc(size * sizeof(short));
  if(node == EMPTYNODE)
    return; 
  
  else
  {
    while(curr!=EMPTYNODE)
    {
      if(curr->left == EMPTYNODE)
      {
        arr[j] = curr -> data;
        j++;
        curr = curr->right;
      }
      else
      {
        nodeQ_t* extra = curr->left;
        while(extra->right && extra -> right != curr)
        extra=extra->right;

     if (extra->right == curr)
            {
             extra->right = EMPTYNODE;
                curr = curr->right;
            }
     else
          {
            arr[j]= curr->data;
            j++;
            extra->right = curr;
            curr = curr->left;
          }
      }
    }
  }
  *out_size = j;
  *out_array = arr;
  return;
}

struct s
{
  short size;
  short up;
  nodeQ_t** arrs;
};

typedef struct s nodeS;

nodeS* create(short sz)
{
  nodeS *s = (nodeS *)malloc(sizeof(nodeS)*sz);
  s->size = sz;
  s->up = -1;
  s->arrs = (nodeQ_t**)malloc(s->size * sizeof(nodeQ_t*));
  return s;
}

void push(nodeS* s , nodeQ_t* node)
{
  if(s->up == 299)
  {
    return;
  }
  s->up++;
  s->arrs[s->up]=node;
}

nodeQ_t* pop(nodeS *s)
{
  if(s->up == -1)
  return EMPTYNODE;
  short t = s->up;
  s->up--;
  return s->arrs[t];

}

void getPostorder(nodeQ_t* node, short **out_array, short *out_size)
{
  short size = *out_size;
  short i=0;
  short *arr = (short*)malloc(size * sizeof(short));

  if(node == EMPTYNODE)
  return;

  nodeS* s1 = create(300);
  nodeS* s2 = create(300);
  push(s1 , node);
  nodeQ_t*curr;
  
  while (s1->up != -1)
  {
    curr = pop(s1);
    push(s2, curr);

    if (curr->left)
    {
    push(s1, curr->left);
    }
    if (curr->right)
    {
    push(s1, curr->right);
    }
  }

  while (s2->up != -1) 
  {
      curr = pop(s2);
      arr[i]=curr->data;
      i++;
  }

*out_array = arr;
*out_size = i;
return;
}

