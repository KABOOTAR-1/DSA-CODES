/**
 *
Instructions:
0. Failure to follow instructions will lead to ZERO marks

1. You must implement following functions.

2. DO NOT change function names, output type, input type etc.

3. Comment out the main function before submitting, or simply delete the main function. 

4. Implement all the functions in this C file. Rename it as YourRollNo.c - e.g., bt20cse019.c. 
- NO SPACES, name or any other characters
- Entire filename is LOWER CASE only
- Submit only this c file. 

5. The header file csl102lab2.h must be in the same folder/directory as your C file when you
implement. DO NOT submit the header file.

6. Failure to do 3 and 4 will result in ZERO marks.

7. Compilation error will result in ZERO marks.

8. Late submission will result in ZERO marks.

9. IF and ONLY IF Moodle does not let you upload the file, email me immediately 
- email subject: CSL 102 Lab assignment 2

10. DO NOT delete any comments in the file.

11. Failure in submitting the correct file will result in a ZERO.

12. You can add a new function in the file. If you do so, DO NOT delete the function while submission.
**/
#include <stdio.h>
#include "csl102lab2.h"

/**
 * In this exercise, you find the second largest and second smallest element.
 * The function must return the difference between second largest and second smallest.
 * For example, in the array [21, 7, 6, 13, 56, 2, 8, 99], 
 * 56 is the second largest element and 7 is the second smallest element. 
 * Thus, the function must return 56 - 7 = 49.
 * You can reuse the code @ https://github.com/aniket-acad/csl102_ds_iiitn.
 * arr = starting address of the array. 
 * sz = number of elements in the array. Assume sz will be greater than 4.
 * */
int csl102_diff_2smallest_2biggest(int arr[], unsigned short sz){
/**
 * Write your code here.
 * PLEASE DO NOT WRITE CODE INSIDE THIS COMMENTS SECTION
 * */
int m=0;
for(int i=0;i<sz-1;i++){
        for(int j=i+1;j<sz;j++){
            if(arr[j]<arr[i]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    

m=arr[sz-2]-arr[1];
    return m;
}

/**
 * In this exercise you will find if the input array is in a sorted order
 * arr = starting address of the array.
 * If the array is not sorted, return 0
 * If the array is sorted in ascending order, return 1
 * If the array is sorted in descending order, return 2
 * */
unsigned short csl102_is_array_sorted(int arr[], unsigned short sz){
/**
 * Write your code here.
 * PLEASE DO NOT WRITE CODE INSIDE THIS COMMENTS SECTION
 * */int l = 1, m = 1, i = 0;

  while ((l == 1 || m == 1) && i < sz - 1) {
    if (arr[i] < arr[i+1])
      m = 0;
    else if (arr[i] > arr[i+1])
      l = 0;
    i++;
  }

  if (l == 1)
    return 1;
  else if (m == 1)
    return 2;
  else
    return 0;
}
    

/**
 * In this exercise you will find if the input array has duplicate elements
 * Assume maximum one duplicate value
 * For example, in the array [21, 7, 99, 13, 56, 2, 8, 99], 99 is duplicate
 * arr = starting address of the array (has positive values only).
 * If the array has duplicate return the value/element (99 in the example)
 * If the array does not have duplicate return -1.
 * */
int csl102_find_duplicate(int arr[], unsigned short sz){
/**
 * Write your code here.
 * PLEASE DO NOT WRITE CODE INSIDE THIS COMMENTS SECTION
 * */  
int n, l = 0;
    for(int i = 0; i < sz; i ++)
        {
            for(int j = i+1 ;j < sz; j ++)
                {
                    if(arr[j] == arr[i])
                        {
                            n = arr[i];
                            l ++;
                            break;
                        }
                }
        }
    if( l!= 0)
        return n;
    else
        return -1;
    
}

/**
 * Comment out the main function (or delete it entirely) before submitting
 * No marks will be awarded if the main function is left uncommented
 * All code in main is sample code for your reference
 * You can change it as per your wish
 * */

/*int main(){
    return 0;
}*/