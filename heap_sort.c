#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_HEAP_SIZE 100000

void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}

//for parent
int maxheap_parent(int index){
  return (index - 1)/2;
}


//for left child
int maxheap_leftchild(int index){
  return (2*index)+1;
}

//for right child
int maxheap_rightchild(int index){
  return (2*index)+2;
}


//Heap shift down
void maxheap_shiftdown(int N, int arr[], int index){
  int left_index = maxheap_leftchild(index);
  int right_index = maxheap_rightchild(index);
  //lets say our current index contains maximum value
  int maxindex = index;
  //now we will compare it with left child
  //at first left child should exist
  if(left_index < N && arr[left_index] > arr[maxindex]){
    maxindex = left_index;
  }
  if(right_index < N && arr[right_index] > arr[maxindex]){
    maxindex = right_index;
  }

  if(maxindex == index){
    return;
  }
  swap(&arr[maxindex], &arr[index]);
  maxheap_shiftdown(N, arr, maxindex);
}

//Remove max
void maxheap_pop(int *N, int arr[]){
  //condition weather we can apply pop here or not
  if(*N > 0){
    //swap root element with last element
    swap(&arr[0], &arr[*N-1]);
    
    //decrement the size by 1
    (*N)--;
    //shift down to set our tree
    maxheap_shiftdown(*N,arr,0);
  }
  else{
    printf("ERROR: YOUR HEAP IS EMPTY\n");
  }
}

void print(int value){
  printf("%d\n",value);
}



void build_heap(int n, int arr[]){
  //we are starting from last element
  //Time complexity - NlogN
  for(int i = n-1; i >= 0; --i){
    maxheap_shiftdown(n, arr, i);
  }
}

void heap_sort(int n, int arr[]){
  //build heap - convert arr into heap
  build_heap(n, arr);
  while(n>0){
    maxheap_pop(&n, arr);
  }
    
    
}
int main(){
  int arr[] = {100, 20, 50, 1, 15, 69};

  heap_sort(6, arr);
  for(int i = 0; i < 6; ++i){
     print(arr[i]);
  }
  return 0;
}



// gcc heap_sort.c -o temp && ./temp && rm temp
