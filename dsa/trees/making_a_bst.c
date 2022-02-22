#include "csl102_lab8.h"
#include <stdio.h>
#include <stdlib.h>

nodeQ_t* createNode(short value)
{
    nodeQ_t* newnode = (nodeQ_t*)malloc(sizeof(nodeQ_t));

    newnode->data = value;
    newnode->left = EMPTYNODE;
    newnode->right = EMPTYNODE;

    return newnode;
}




void getInorder(nodeQ_t* node, short **out_array, short *out_size)
{
  nodeQ_t *current,*pre;
  short sz = *out_size;
  short *temp_arr = (short*)malloc(sz * sizeof(short));
  if(node == EMPTYNODE)
     return; 

  short i=0;
  current = node;
  while(current != EMPTYNODE)
  {
    if(current->left == EMPTYNODE)
    {
      temp_arr[i]= current->data;
      i++;
      current = current->right;
    }
    else
    {
      pre = current->left;
      while(pre->right != EMPTYNODE && pre->right != current)
        pre = pre->right;

      if(pre->right == EMPTYNODE)
      {
        pre->right = current;
        current = current->left;
      }

      else
      {
        pre->right = EMPTYNODE;
        temp_arr[i]=current->data;
        i++;
        current = current->right;
      } 
    } 
  } 
  *out_size = i;
  *out_array = temp_arr;
  return;
}



void buildbst(nodeQ_t* node, short *out_array)
{
  nodeQ_t *current,*pre;
  if(node == EMPTYNODE)
     return; 

  short i=0;
  current = node;
  while(current != EMPTYNODE)
  {
    if(current->left == EMPTYNODE)
    {
      current->data = out_array[i];
      i++;
      current = current->right;
    }
    else
    {
      pre = current->left;
      while(pre->right != EMPTYNODE && pre->right != current)
        pre = pre->right;

      if(pre->right == EMPTYNODE)
      {
        pre->right = current;
        current = current->left;
      }

      else
      {
        pre->right = EMPTYNODE;
        current->data = out_array[i];
        i++;
        current = current->right;
      } 
    } 
  } 

  return;
}



void swap(short *a, short *b) {
  short temp = *a;
  *a = *b;
  *b = temp;
}
 void selectionSort(short arr[], short n){
    short minIdx = 0;
    for (short i = 0; i < n-1; i++){
        minIdx = i;
        for (int j = i+1; j < n; j++){
          if (arr[j] < arr[minIdx]){
            minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
      }
  }




nodeQ_t* arrtobst(short* arr , short stind , short endind )
{
    if (stind > endind)
      return NULL;
 
    short mid = (stind + endind)/2;
    nodeQ_t *root = createNode(arr[mid]);

    root->left =  arrtobst(arr, stind, mid-1);
 

    root->right = arrtobst(arr, mid+1, endind);
 
    return root;



}



nodeQ_t* convertBinaryTree2BST(nodeQ_t* binTreeRoot)
{


    short *out_array;
    short out_size;
    out_array = (short*)malloc(sizeof(short));
   

    getInorder(binTreeRoot,&out_array,&out_size);
    selectionSort(out_array,out_size);
 for( short i=0; i<out_size; i++)
    {
        for( short j=i+1; j< out_size; j++)
        {
            if(out_array[i] == out_array[j])
            {
                for(short k=j; k < out_size - 1; k++)
                {
                    out_array[k] = out_array[k + 1];
                }

                out_size--;

                j--;
            }
        }
    }
    
    nodeQ_t* root = arrtobst(out_array,0,out_size-1);

    return root;
    
}




nodeQ_t* flipBST(nodeQ_t* bstRoot)
{
    
    short *out_array;
    short out_size;
    out_array = (short*)malloc(out_size*sizeof(short));

    //storing the bst inorder in out_array
    getInorder(bstRoot,&out_array,&out_size);

    //reversing the array using a temp array
    short* arr = (short*)malloc(out_size*sizeof(short));
    for (short i = 0; i < out_size; i++)
    {
      arr[i] = out_array[out_size - i - 1];

    }

    //building flipper bst
    buildbst(bstRoot,arr);

    return bstRoot;


}




nodeQ_t* mergeTwoBSTs(nodeQ_t* bst1Root, nodeQ_t* bst2Root)
{

  short *arr1 , *arr2;
  short sz1 , sz2 , mergsz=0;
  arr1 = (short*)malloc(sizeof(short));
  arr2 = (short*)malloc(sizeof(short));
  printf("a");
  getInorder(bst1Root,&arr1,&sz1);
  getInorder(bst2Root,&arr2,&sz2);
  printf("c");

short* mergarr = (short*)malloc(mergsz*sizeof(short));

  short i=0,j=0,z=0;

  while (i!=sz1 && j!= sz2)
  {
    if(arr1[i] > arr2[j])
    {
      mergsz++;
      mergarr[z]=arr2[j];
      j++;
      z++;
    }

    else if(arr1[i]<arr2[j])
    {
      mergsz++;
      mergarr[z]=arr1[i];
      i++;
      z++;
    }
    else if(arr1[i]==arr2[j])
    {
      mergsz++;
      mergarr[z] = arr1[i];
      z++;
      i++;
      j++;
    }
  }
  if(i<sz1)
  {
     for (short d = i; d < sz1; d++)
     {
        mergarr[z] = arr1[d];
        z++;
     }
     
  }

    if(j<sz2)
  {
     for (short d = j; d < sz2; d++)
     {
        mergarr[z] = arr2[d];
        z++;
     }
  }

  nodeQ_t* root = arrtobst(mergarr,0,mergsz-1);
  return root;

}


void printInorder(nodeQ_t* root)
{
  short* arr;
  short sz;
  arr = (short*)malloc(sizeof(short));

  getInorder(root,&arr,&sz);
  for (short i = 0; i < sz; i++)
  {
    printf("%d\t",arr[i]);
  }
  
}

 

void main()
{
  nodeQ_t* root;
    root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->right->right = createNode(40);

    nodeQ_t* root1;
    root1 = createNode(25);
    root1->left = createNode(15);
    root1->right = createNode(35);
    root1->left->left = createNode(5);
    root1->right->right = createNode(45);

  nodeQ_t * root2;
  root2 = mergeTwoBSTs(root,root1);
  printInorder(root2);

}