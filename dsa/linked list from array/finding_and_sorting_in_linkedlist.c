#include "csl102_lab9.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

unsigned short kthLargestElement(llNode_t* l1, llNode_t* l2, llNode_t* l3, unsigned short k){
    
}

short find_small(comboData_t val){
    short min = val.num1;
    if(min >= val.num2){
        min = val.num2;
    }
    if(min >= val.num3){
        min = val.num3;
    }

    

    return min;
}

short getMedianComboData(comboData_t vals[], short sz){
    
    short mins[sz];

    for(int i=0;i<sz;i++){
        mins[i]=find_small(vals[i]);
    }

    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if(mins[j]>mins[i]){
                short a=mins[j];
                mins[j]=mins[i];
                mins[i]=a;
            }
        }
    }

    if(sz%2==0){
        int temp = (mins[sz/2] + mins[(sz/2)-1])/2;
        return temp;
    }
    else{
        return mins[sz/2];
    }


}

void dswap(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void sort(double arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        dswap(&arr[min_idx], &arr[i]);
    }
}

double* sortedSquareRoots(unsigned short vals[], unsigned short inSz){
    double *arr;
    
    arr=(double*)malloc(sizeof(inSz));

    for(int i=0;i<inSz;i++){
        arr[i]=sqrt(vals[i]);
    }

    sort(arr,inSz); 

    return arr;

}

int main(){

    llNode_t* head0;
    head0->data=10;
    
    llNode_t* n1;
    n1->data=1;
    head0->left=n1;

    llNode_t* n2;
    n2->data=1;
    n1->left=n2;

    llNode_t* n3;
    n3->data=3;
    n2->left=n3;

    llNode_t* head1;
    head1->data=10;
    
    llNode_t* n11;
    n11->data=1;
    head1->left=n11;

    llNode_t* n21;
    n21->data=1;
    n11->left=n21;

    llNode_t* n31;
    n31->data=1;
    n21->left=n31;

    llNode_t* head2;
    head2->data=10;
    
    llNode_t* n12;
    n12->data=1;
    head2->left=n12;

    llNode_t* n22;
    n22->data=1;
    n12->left=n22;

    llNode_t* n32;
    n32->data=1;
    n22->left=n32;
    
    printf("%d",kthLargestElement(head0,head1,head2,1));


    short arr[6]={4,9,16,25,36,49};
    double *x;
    x=sortedSquareRoots(arr,6);
    for(int i=0;i<6;i++){
        printf("%f",x[i]);
        printf(" ");
    }

    comboData_t vals[3];
    
    vals[0].num1=13;
    vals[0].num2=50;
    vals[0].num3=12;

    vals[1].num1=1;
    vals[1].num2=56;
    vals[1].num3=12;
    
    vals[2].num1=7;
    vals[2].num2=15;
    vals[2].num3=2;


    printf("%d",getMedianComboData(vals,3));

}