#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//******** CREATED A TEMPLATE ********//
//its like a interface
struct Linkedlist_node{
  //in node we want data and address of next(pointer)
  int data;
  struct Linkedlist_node* next;
};

struct Linkedlist{
  //its complete linked list so here we want head, tail, its complete size of linked list(its for stack and queue)
  //HEAD = is pointing towards head of linked list so its datatype should be struct pointer
  struct Linkedlist_node* head; //example - train 
  struct Linkedlist_node* tail;
  int size;
};


//****** NOW WE WILL INITIALIZE THE THIHGS AND ALLOCATE MEMORY *******//
struct Linkedlist* new_linkedlist() {
  //here we will allocate size
  struct Linkedlist* my_linkedlist = (struct Linkedlist*) malloc(sizeof(struct Linkedlist));
  //initialize empty linked list 
  // we have allocated a memory to my_linkedlist 
  //since we donot have oop in c we will be writing it ->
  my_linkedlist->head = NULL; //Null ka data type hi alag hai but sirf pointer ko allowed hai null see initialize karna
  my_linkedlist->tail = NULL;
  my_linkedlist->size = 0;
};

struct Linkedlist_node* new_linkedlist_node(int data1) {
  //basically Linkedlist_node is an class and my_linkedlist_node is an object
  struct Linkedlist_node* my_linkedlist_node =  (struct Linkedlist_node*) malloc(sizeof(struct Linkedlist_node));
  //if it was oop then we would have written it as my_linkedlist_node.size()
  my_linkedlist_node->data = data1;
  my_linkedlist_node->next = NULL;
  
}

//pop kahasee karna hai - head see - head linkedlist see milega - so we want linked list
//pop kya karna hai - existing data
void linkedlist_pop_front(struct Linkedlist* my_linkedlist){
  if(my_linkedlist->size == 0) return;
  //we will first create a one timepass node pointerand  will point timepass node towards head that we are going to del
  struct Linkedlist_node* node = my_linkedlist->head;
  //here head, tail and node all three are pointing towards same node
  if(my_linkedlist->size == 1){
    my_linkedlist->head = NULL;
    my_linkedlist->tail = NULL;
    //after this head and tail is null and node is pointing towards previous head
  }
  else{
    //then we will update new head as a next node of previous head
    my_linkedlist->head = my_linkedlist->head->next;
  }
  //update the size
  my_linkedlist->size--;
  //free the timepass node
  free(node);
}

void linklist_pop_back() {
  //..
}

//push kaha karna hai - head ke pahile - head linkedlist see milega - so we want linked list
//push kya karna hai - data
void linkedlist_push_front(struct Linkedlist* my_linkedlist, int data) {
  //push front means we will insert our new node before current head and newly added node will become our new head
  //allocate the node 
  
  // we will first need to create a new node.
  struct Linkedlist_node* node = new_linkedlist_node(data);

  //if linkedlist is empty then head and tail will point towards same thing
  if(my_linkedlist->size == 0){
    my_linkedlist->head = node;
    my_linkedlist->tail = node;
  }

  else{
    node->next = my_linkedlist->head;
    my_linkedlist->head = node;
  }
  //update size
  my_linkedlist->size++;
}


//push kaha karna hai - tail ke baad - tail linkedlist see milega - so we want linked list
//push kya karna hai - data
void linkedlist_push_back(struct Linkedlist* my_linkedlist, int data) {
  //push back means append node after tail and make newly added node as tail
  //allocate the node 
  struct Linkedlist_node* node = new_linkedlist_node(data);

  //if linkedlist is empty then head and tail will point towards same thing
  if(my_linkedlist->size == 0){
    my_linkedlist->head = node;
    my_linkedlist->tail = node;
  }

  else{
    my_linkedlist->tail->next = node;
    my_linkedlist->tail = node;
  }
  my_linkedlist->size++;
}


void print_linkedlist(struct Linkedlist* Linkedlist){
  struct Linkedlist_node* node = Linkedlist->head;
  while(node){
    printf("%d->",node->data);
    node = node->next;
  }
  printf("\n");
}
int main(){
  struct Linkedlist* linkedlist = new_linkedlist();
  linkedlist_push_back(linkedlist, 2);
  linkedlist_push_back(linkedlist, 89);
  linkedlist_push_back(linkedlist, 90);
  linkedlist_push_back(linkedlist, 20);
  linkedlist_push_front(linkedlist, 22);
  linkedlist_pop_front(linkedlist);
  print_linkedlist(linkedlist);
  
  
  return 0;
}