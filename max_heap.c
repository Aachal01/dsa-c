#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_HEAP_SIZE 100000

void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}


struct MaxHeap{
int arr[MAX_HEAP_SIZE];
int size; 
};


struct MaxHeap* new_maxheap(){
  
  struct MaxHeap* my_maxheap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
  my_maxheap->size = 0;
  return my_maxheap;
};


//how do we know who is parent who is left child who is right child
//it doesnot depend on actual heap


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


//Heap shift up
void maxheap_shiftup(struct MaxHeap *my_maxheap, int ch_index){
  //using recursive 
  //ch_index = 0 means it is root node
  if(ch_index == 0){
    return; //only return coz our return type is void
  }

  //just putting a check mark
  assert(ch_index > 0);
  int parent = maxheap_parent(ch_index);
  if(my_maxheap->arr[ch_index] > my_maxheap->arr[parent]){
    swap(&my_maxheap->arr[parent] , &my_maxheap->arr[ch_index]);
    maxheap_shiftup(my_maxheap,parent);
  }
   
  // //using while loop
  // //>0 coz we are using zero based index
  // int parent = maxheap_parent(ch_index)
  // assert(ch_index > 0);
  // //why index > 0 and >= 0
  // while(ch_index > 0 && my_maxheap->arr[parent] < my_maxheap->arr[ch_index]){
  //   swap(&my_maxheap->arr[parent] , &my_maxheap->arr[ch_index]);
  //   ch_index = parent;
  // }
}

//Heap shift down
void maxheap_shiftdown(struct MaxHeap *my_maxheap, int index){
  int N = my_maxheap->size;
  int left_index = maxheap_leftchild(index);
  int right_index = maxheap_rightchild(index);
  //lets say our current index contains maximum value
  int maxindex = index;
  //now we will compare it with left child
  //at first left child should exist
  if(left_index < N && my_maxheap->arr[left_index] > my_maxheap->arr[maxindex]){
    maxindex = left_index;
  }
  if(right_index < N && my_maxheap->arr[right_index] > my_maxheap->arr[maxindex]){
    maxindex = right_index;
  }

  if(maxindex == index){
    return;
  }
  swap(&my_maxheap->arr[maxindex], &my_maxheap->arr[index]);
  maxheap_shiftdown(my_maxheap, maxindex);
}

//Insert new element
void maxheap_push(struct MaxHeap *my_maxheap, int value){
  if(my_maxheap->size < MAX_HEAP_SIZE){
    my_maxheap->arr[my_maxheap->size] = value;
    //we will check weather it is max heap or not
    maxheap_shiftup(my_maxheap, my_maxheap->size);
    my_maxheap->size++;
  }
  else{
    printf("ERROR: YOUR HEAP IS FULL\n");
  }
}


//Remove max
void maxheap_pop(struct MaxHeap *my_maxheap){
  //condition weather we can apply pop here or not
  if(my_maxheap->size > 0){
    //swap root element with last element
    swap(&my_maxheap->arr[0], &my_maxheap->arr[my_maxheap->size-1]);
    
    //decrement the size by 1
    my_maxheap->size--;
    //shift down to set our tree
    maxheap_shiftdown(my_maxheap,0);
  }
  else{
    printf("ERROR: YOUR HEAP IS EMPTY\n");
  }
}


//returns maximum element
int maxheap_top(struct MaxHeap *my_maxheap){
  if(my_maxheap->size > 0){
    return my_maxheap->arr[0];
  }
  return 0;
}

void print(int value){
  printf("%d\n",value);
}

int main(){
  struct MaxHeap* maxheap1 = new_maxheap();
  maxheap_push(maxheap1, 120);
  maxheap_push(maxheap1, 500);
  maxheap_push(maxheap1, 100);
  maxheap_push(maxheap1, 0);
  
  //to see what elements are in the array
 

  maxheap_pop(maxheap1);
  // print(maxheap_top(maxheap1));
  maxheap_pop(maxheap1);
  // print(maxheap_top(maxheap1));
  maxheap_pop(maxheap1);
  // print(maxheap_top(maxheap1));
  maxheap_pop(maxheap1);
  // print(maxheap_top(maxheap1));
  for(int i = 0; i < 4; i++){
    print(maxheap1->arr[i]);
  }
  // print(maxheap_top(maxheap1));


  return 0;
}



// gcc max_heap.c -o temp && ./temp && rm temp
