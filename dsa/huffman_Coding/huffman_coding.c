#include "csl210_lab3.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct createminheap {
  unsigned size;
  unsigned cap;
  btNode_t **arr;
};

typedef struct createminheap min_node;

min_node *min_heap(unsigned cap) {
  min_node *minHeap = (min_node *)malloc(sizeof(min_node));

  minHeap->size = 0;

  minHeap->cap = cap;

  minHeap->arr = (btNode_t **)malloc(minHeap->cap * sizeof(btNode_t *));
  return minHeap;
}

btNode_t *newnode(char val, unsigned freq) {
  btNode_t *new = (btNode_t *)malloc(sizeof(btNode_t));

  new->left = new->right = NULL;
  new->value = val;
  new->frequency = freq;

  return new;
}

void node_swap(btNode_t **a1, btNode_t **b1) {
  btNode_t *temp = *a1;
  *a1 = *b1;
  *b1 = temp;
}


void heapify(min_node *min, int index) {
  int s = index;
  int l = 2 * index + 1;
  int r = 2 * index + 2;

  if (l < min->size && min->arr[l]->frequency < min->arr[s]->frequency)
    s = l;

  if (r < min->size && min->arr[r]->frequency < min->arr[s]->frequency)
    s = r;

  if (s != index) {
    node_swap(&min->arr[s], &min->arr[index]);
    heapify(min, s);
  }
}


int size_heap(min_node *min_heap) {
  return (min_heap->size == 1);
}


btNode_t *take_min_heap(min_node *min_heap) {
  btNode_t *temp = min_heap->arr[0];
  min_heap->arr[0] = min_heap->arr[min_heap->size - 1];

  --min_heap->size;
  heapify(min_heap, 0);

  return temp;
}


void min_heap_insert(min_node *min_heap, btNode_t *heap_node) {
  ++min_heap->size;
  int i = min_heap->size - 1;

  while (i && heap_node->frequency < min_heap->arr[(i - 1) / 2]->frequency) {
    min_heap->arr[i] = min_heap->arr[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  min_heap->arr[i] = heap_node;
}

void min_heap_build(min_node *min_heap) {
  int n = min_heap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    heapify(min_heap, i);
}

min_node *Create_Heap(char val[], int freq[], int sz) {
  min_node *min = min_heap(sz);

  for (int i = 0; i < sz; ++i){
    min->arr[i] = newnode(val[i], freq[i]);
  }
  min->size =sz;
 min_heap_build(min);

  return min;
}

btNode_t *make_huffm_tree(char val[], int freq[], int sz) {
  btNode_t *left, *right, *top;
  min_node *min_heap = Create_Heap(val, freq, sz);

  while (!size_heap(min_heap)) {
    left = take_min_heap(min_heap);
    right = take_min_heap(min_heap);

    top = newnode('$', left->frequency + right->frequency);
    top->left = left;
    top->right = right;

    min_heap_insert(min_heap, top);
  }

  return take_min_heap(min_heap);
}

btNode_t* createHuffmanTree(char input[], unsigned short sz){
    int temp_array[256]={0};
    int *freq=(int*)malloc(sizeof(int)*sz);
    char *string=(char*)malloc(sizeof(char)*sz);
    unsigned short j=0;

    for(int i=0;i<sz;i++){
        temp_array[input[i]]++;
    }
	for(int i=0;i<256;i++){
        if(temp_array[i] != 0){
        	string[j]=i;
            freq[j]=temp_array[i];
            j++;
      	}
    }

    btNode_t *root = make_huffm_tree(string,freq,j);
	return root;
}

