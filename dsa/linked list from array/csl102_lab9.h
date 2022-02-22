/**
 * CSL 102 Lab 9
 * Submission deadline Friday July 16 @ 10PM 
 * 
 * Total marks = FOUR
 * Compilation error = ZERO
 * If your code compiles, your get 0.5 minimum marks
 * Late submission will NOT be accepted
 * Submission filename not having your roll no = ZERO
 * Pleading for marks despite compilation error = NEGATIVE FOUR
 * Pleading for marks without running evalution tool = NEGATIVE FOUR
 * Copying code from each other = NEGATIVE FOUR
 * Keeping main function in the submission code = NEGATIVE FOUR
 * Keep the file extension in lower case c
 * 
 * * 
 * Suggestion:
 * * Implement the main function in a separate c file and not in the submission c file
 * */

#define EMPTYNODE 0

struct llNode {
	short data;
	struct llNode* left;
};
typedef struct llNode llNode_t;

struct comboData {
	short num1;
	short num2;
	short num3;	
};
typedef struct comboData comboData_t;

/**
 * For the input linked list, find the kth largest element in the combined lists of all input lists.
 * l1, l2 and l3 = input linked lists
 * For example, 
 * l1 = 3 -> 5 -> 4 -> EMPTYNODE, 
 * l2 = 9 -> 6 -> EMPTYNODE, 
 * l3 = 1 -> 11 -> EMPTYNODE
 * kth largest element where k = 2 is 9 (1,3,4,5,6,*9*,11)
 * kth largest element where k = 6 is 3 (1,*3*,4,5,6,9,11)
 * return the value of kth largest element
 **/ 
unsigned short kthLargestElement(llNode_t* l1, llNode_t* l2, llNode_t* l3, unsigned short k);

/**
 * Get the median value from the combo data
 * vals will be array of combo data.
 * sz will be the size of vals
 * In your implementation, to get the median, comboData in vals must be be ordered by the smallest number of num1, num2 and num3 for each struct in vals
 * 
 * For example vals = [{num1 = 10, num2 = 5, num3 = 12}, {num1 = 1, num2 = 56, num3 = 12}, {num1 = 7, num2 = 15, num3 = 2}]
 * Median for above example will be 2 (5 from vals[0], 1 from vals[1], and 2 from vals[2])
 * **/ 
short getMedianComboData(comboData_t vals[], short sz);


/**
 * Given an array vals, return an array of the square root of each number in vals. 
 * The returned array must be in descending order.
 * vals = input array
 * inSz = size of vals
 **/
double* sortedSquareRoots(unsigned short vals[], unsigned short inSz);