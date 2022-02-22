#include<stdio.h>
#include"csl210_lab2a.h"
#include<stdlib.h>

int arr[200]={0};
int j=0;

quadNode_t* newnode(int data)
{
   quadNode_t* node = (quadNode_t*) malloc (sizeof(quadNode_t));
    node->value= data;
    node->child0= NULL;
    node->child1 = NULL;
    node->child2=NULL;
    node->child3=NULL;
    return (node);
}

quadNode_t* insert(quadNode_t* root,int key){

    if(key<root->value){
        if(root->child0==EMPTYNODE){
            root->child0=newnode(key);
            return root;
        }
        else{
            insert(root->child0,key);
            return root;
        }
        
        if(root->child1==EMPTYNODE){
            root->child1=newnode(key);
            return root;
        }
        else{
            insert(root->child0,key);
            return root;
        }
    }
    else if(key>root->value){
        if(root->child2==EMPTYNODE){
            root->child2=newnode(key);
            return root;
        } 
        else{
            insert(root->child2,key);
            return root;
        }
        
        if(root->child3==EMPTYNODE){
            root->child3=newnode(key);
            return root;
        }
        else{
            insert(root->child2,key);
            return root;
        }
    }
    else{
        return root ;
    }
}

int inorder(bstNode_t*root){
if(EMPTYNODE==root)
return j;

inorder(root->left);
arr[j++]=root->value;
inorder(root->right);
}

int preorder(bstNode_t*root){
   
if(EMPTYNODE==root)
return j;

arr[j]=root->value;
j++;
preorder(root->left);
preorder(root->right);
}

int postorder(bstNode_t*root){
   

if(EMPTYNODE==root)
return j;

postorder(root->left);
postorder(root->right);
arr[j]=root->value;
j++;
}

quadNode_t* convertBST2QuadTree(bstNode_t* rootBST, traversal_t order){

    if(EMPTYNODE==rootBST)
    return NULL;
    
    int count=0;
    int i=0;
 if(0==order){
    count= inorder(rootBST);
     j=0;
     }
 if(1==order){
   j=0;
        
 count= preorder(rootBST);
  }
    
 if(2==order){
   count=postorder(rootBST);
   j=0;
    }
 
 i=0;
 quadNode_t* root_node=newnode(arr[0]);
 i++;
 quadNode_t*temp=EMPTYNODE;
 j=count;

while(1!=count){
  temp=insert(root_node,arr[i]);
  i++;
  count--;
  
}
return root_node;
}

void printInOrder(quadNode_t* node)
{
    if(node != NULL)
    {
        printInOrder(node->child0);
        printInOrder(node->child1);
        printf("%d ",node->value);
        printInOrder(node->child2);
        printInOrder(node->child3);
    }

}

int main(){
    bstNode_t* n0 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n0->left=NULL;
    n0->right=NULL;
    n0->value=90;

    bstNode_t* n1 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n1->left=NULL;
    n1->right=NULL;
    n1->value=88;
    
    bstNode_t* n2 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n2->left=NULL;
    n2->right=NULL;
    n2->value=89;

    bstNode_t* n3 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n3->left=NULL;
    n3->right=NULL;
    n3->value=91;

    bstNode_t* n4 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n4->left=NULL;
    n4->right=NULL;
    n4->value=92;

    bstNode_t* n5 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n5->left=NULL;
    n5->right=NULL;
    n5->value=87;

    bstNode_t* n6 = (bstNode_t*)malloc(sizeof(bstNode_t));
    n6->left=NULL;
    n6->right=NULL;
    n6->value=95;

    n0->left=n1;
    n0->right=n4;
    n1->right=n2;
    n4->left=n3;
    n1->left=n5;
    n4->right=n6;

    traversal_t type=2;

    quadNode_t* head = convertBST2QuadTree(n0,type);

    printf("\n");
    printInOrder(head);

    return 0;
}
