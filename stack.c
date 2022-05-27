#include<stdio.h>
#include<stdlib.h>

//macros 

//drawback of using array is it will occupy tooo memory 
#define MAX_STACK_SIZE 100000

struct Stack{
//array to store the value of stack 
//in c we don't have dynamic array and we don't know how big our stack is so we will assign maximum possible value to our array
int arr[MAX_STACK_SIZE]; //we know that array has infinite size

//store the size of stack 
int size; //for users 
};




//struct Stack - data type 
//stack - variable name

//for new stack
struct Stack* new_stack(){

  //malloc syntax - (cast-type*) malloc(byte-size)
  //malloc provides the memory to new_stack
  //it returns null pointer so we will type cast it into stuct 
  struct Stack* my_stack = (struct Stack*)malloc(sizeof(struct Stack));
  //we will intialize size of stack as 0 so that no garbage value is assigned to it 

  //we are passing data as ref so we don't know the exact location of our data thats why we will use ->, as we are using pointer
  //if it wasnt pointer data type we would have used .
  my_stack->size = 0;
  return my_stack;
};
//Push operation 
void stack_push(struct Stack *my_stack, int value){
  if(my_stack->size < MAX_STACK_SIZE){

    //we will insert the element after the top element 
    my_stack->arr[my_stack->size] = value;
    //we will also need to update the size of stack
    my_stack->size++;  
  }
  else{
    printf("ERROR: YOUR STACK IS FULL\n");
  }
}

//Pop operation 
//pop is global function so we will direct use it like pop()
//not binded with any data like in oop
void stack_pop(struct Stack *my_stack){
  if(my_stack->size > 0){
    //ignore the last element in stack 
    //last element got converted in garbage element 
    my_stack->size--;
  }
  else{
    printf("ERROR: YOUR STACK IS EMPTY\n");

  }
}

//if we want to know what is on the top of stack we will use top
int stack_top(struct Stack *my_stack){
  
  if(my_stack->size > 0){
    //we are returning what element is on the top of stack
    return my_stack->arr[my_stack->size-1];
  }
  else{
    //when stack is empty
    printf("ERROR: YOUR STACK IS EMPTY\n");
    return 0;
  }
}

void print(int value){
  printf("%d\n",value);
}

int main(){

  //struct Stack* is datatype
  //stack1 is variable 
  //new_stack is function
  struct Stack* stack1 = new_stack();
  
  stack_push(stack1, 12);
  stack_push(stack1, 13);
  stack_push(stack1, 15);
  int top_value = stack_top(stack1);
  print(top_value);
  stack_pop(stack1);
  print(stack_top(stack1));

  return 0;
}