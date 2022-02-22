#include <stdlib.h>
#include <stdio.h>
#include "csl210_lab2b.h"
#include<stdbool.h>


bool isbst(btNode_t* root);


btNode_t* getBSTSubtree(btNode_t* rootNode){
    

    
    if (rootNode == EMPTYNODE)
        return EMPTYNODE;
 
    if(isbst(rootNode)==true && rootNode->left!=EMPTYNODE && rootNode->right!=EMPTYNODE){
        return rootNode;
    }
    
    getBSTSubtree(rootNode->left);
    getBSTSubtree(rootNode->right);
        
    
 }

bool isbst(btNode_t* root)
{
    if (root == EMPTYNODE)
        return true;
 if (root->right != EMPTYNODE && root->right->value < root->value)
        return false;

if (root->left != EMPTYNODE && root->left->value > root->value)
        return false;
   
if (!isbst(root->left) || !isbst(root->right))
        return false;
  return true;
}


int main(){

    btNode_t* n0 = (btNode_t*)malloc(sizeof(btNode_t));
    n0->left=NULL;
    n0->right=NULL;
    n0->value=10;

    btNode_t* n1 = (btNode_t*)malloc(sizeof(btNode_t));
    n1->left=NULL;
    n1->right=NULL;
    n1->value=5;
    
    btNode_t* n2 = (btNode_t*)malloc(sizeof(btNode_t));
    n2->left=NULL;
    n2->right=NULL;
    n2->value=7;

    btNode_t* n3 = (btNode_t*)malloc(sizeof(btNode_t));
    n3->left=NULL;
    n3->right=NULL;
    n3->value=17;

    btNode_t* n4 = (btNode_t*)malloc(sizeof(btNode_t));
    n4->left=NULL;
    n4->right=NULL;
    n4->value=15;

    btNode_t* n5 = (btNode_t*)malloc(sizeof(btNode_t));
    n5->left=NULL;
    n5->right=NULL;
    n5->value=11;

    // btNode_t* n6 = (btNode_t*)malloc(sizeof(btNode_t));
    // n5->left=NULL;
    // n5->right=NULL;
    // n5->value=14;

     btNode_t* n7 = (btNode_t*)malloc(sizeof(btNode_t));
    n7->left=NULL;
    n7->right=NULL;
    n7->value=1;

    n0->left=n1;
    n1->right=n2;
    n1->left=n7;
    n0->right=n4;
    n4->right=n3;
    n4->left=n5;
   /// n5->right=n6 ;

    btNode_t* head = getBSTSubtree(n0);

    printf("%d",head->value);

}
