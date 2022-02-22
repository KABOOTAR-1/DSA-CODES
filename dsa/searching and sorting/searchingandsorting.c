#include "csl102_lab3.h"
/* Check header file for documentation on these functions*/

unsigned long csl102_diff_k_median(
    short array[], 
    unsigned short szArr,
    unsigned short k
){
    /**
     * Write your code here
     * */int m = array[(szArr + 1)/2 - 1];
    int swap, l = 0;
    for(int i = 0; i < szArr - 1; i ++)
        {
            for(int j = 0; j < szArr - i - 1; j ++)
                {
                    if(array[j] > array[j + 1])
                        {
                            swap = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = swap;
                        }
                }
        }
    l = m- array[k - 1];
    if(l < 0)
        l *= -1;
    return l;

   
}

void csl102_sort_lab3(
short arrayOne[], 
unsigned short szArrOne,
short arrayTwo[],
unsigned short szArrTwo){
     /**
     * Write your code here
     * */int k, swap;
    unsigned short mer = szArrOne + szArrTwo;
    short arr[mer];
    for(int i = 0;i < szArrOne; i ++)
        {
            arr[i] = arrayOne[i];
            k = i + 1;
        }
    for(int i = 0;i < szArrTwo; i ++)
        {
            arr[k] = arrayTwo[i];
            k ++;
        }
    for(int i = 0; i < mer- 1; i ++)
        {
            for(int j = 0; j < mer - i - 1; j ++)
                {
                    if (arr[j] >  arr[j + 1])
                        {
                            swap = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = swap;
                        }
                }
        }
    for(int i = szArrOne; i < mer - 1; i ++)
        {
            for(int j = szArrOne; j < mer - 1; j ++)
                {
                    if (arr[j] < arr[j + 1])
                        {
                            swap = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = swap;
                        }
                }
        }
    for(int i = 0; i < szArrOne; i ++)
        arrayOne[i] = arr[i];
    for(int i = 0, k = szArrOne;i < szArrTwo, k < mer; i ++, k ++)
        arrayTwo[i] = arr[k];
    return;
}
