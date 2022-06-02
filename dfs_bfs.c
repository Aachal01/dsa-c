#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Linkedlist_node{
  int data;
  struct Linkedlist_node* next;
};

struct Linkedlist{
  struct Linkedlist_node* head;  
  struct Linkedlist_node* tail;
  int size;
};

struct Linkedlist* new_linkedlist() {
  struct Linkedlist* my_linkedlist = (struct Linkedlist*) malloc(sizeof(struct Linkedlist));
  my_linkedlist->head = NULL; 
  my_linkedlist->tail = NULL;
  my_linkedlist->size = 0;
};

struct Linkedlist_node* new_linkedlist_node(int data1) {
  struct Linkedlist_node* my_linkedlist_node =  (struct Linkedlist_node*) malloc(sizeof(struct Linkedlist_node));
  my_linkedlist_node->data = data1;
  my_linkedlist_node->next = NULL;
  
}

void linkedlist_pop_front(struct Linkedlist* my_linkedlist){
  if(my_linkedlist->size == 0) return;
  struct Linkedlist_node* node = my_linkedlist->head;
  if(my_linkedlist->size == 1){
    my_linkedlist->head = NULL;
    my_linkedlist->tail = NULL;
  }
  else{
    my_linkedlist->head = my_linkedlist->head->next;
  }
  my_linkedlist->size--;
  free(node);
}

void linkedlist_push_front(struct Linkedlist* my_linkedlist, int data) {

  struct Linkedlist_node* node = new_linkedlist_node(data);

  if(my_linkedlist->size == 0){
    my_linkedlist->head = node;
    my_linkedlist->tail = node;
  }

  else{
    node->next = my_linkedlist->head;
    my_linkedlist->head = node;
  }
  my_linkedlist->size++;
}

void linkedlist_push_back(struct Linkedlist* my_linkedlist, int data) {

  struct Linkedlist_node* node = new_linkedlist_node(data);

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


/*****************************************************************************

                        STACK USING LINKED LIST

****************************************************************************/

struct Stack{
  struct Linkedlist* list;
  int size;
};

struct Stack* new_stack(){
  struct Stack* my_stack = (struct Stack*) malloc(sizeof(struct Stack));
  my_stack->list = new_linkedlist();
  my_stack->size = 0;

  return my_stack;
};


void stack_push(struct Stack* my_stack,int data){

  linkedlist_push_front(my_stack->list, data);

  my_stack->size++;
}

void stack_pop(struct Stack* my_stack){

  if( my_stack->size > 0){
    linkedlist_pop_front(my_stack->list);
    my_stack->size--;
  }
  else{
    printf("Error: Your stack is empty");
  }
}

int stack_top(struct Stack* my_stack){
  if( my_stack->size > 0){
    return my_stack->list->head->data;
  }
  else{
    printf("Error: Your stack is empty");
    return 0;
  }
}

/*****************************************************************************

                        QUEUE USING LINKED LIST

****************************************************************************/
struct Queue{
  struct Linkedlist* list;
  int size;
};

struct Queue* new_queue(){
  struct Queue* my_queue = (struct Queue*) malloc(sizeof(struct Queue));
  my_queue->list = new_linkedlist();
  my_queue->size = 0;

  return my_queue;
};

void queue_push(struct Queue* my_queue,int data){

  linkedlist_push_back(my_queue->list, data);
  my_queue->size++;
}

void queue_pop(struct Queue* my_queue){
  //pop from front
  if( my_queue->size > 0){
    linkedlist_pop_front(my_queue->list);
    my_queue->size--;
  }
  else{
    printf("Error: Your queue is empty");
  }
}

int queue_top(struct Queue* my_queue){
  if( my_queue->size > 0){
    return my_queue->list->head->data;
  }
  else{
    printf("Error: Your queue is empty");
    return 0;
  }
}

void print(int value){
  printf("%d\n",value);
}

/*****************************************************************************

                        DFS USING STACK

****************************************************************************/

//what are the things i want - start node, visited nodes, number of nodes,
void dfs(int start, int N, int visited[N], int adj_matrix[N][N]){
  //make a new stack 
  struct Stack* stack = new_stack();
  //push start in the stack initally 
  stack_push(stack, start);
  //mark start as a visited
  visited[start] = 1;

  //now lets check weather the stack is empty or not 
  while(stack->size > 0){
    //we will check what is on the top of stack to travel further into it
    int node = stack_top(stack);
    printf("visited: %d\n",node);
    //pop the elememt 
    stack_pop(stack);
    //if there is edge between the popped element and other elements and that other element is not visited we will visit that element first
    //for loop to see vo kisse connected hai
    for(int i = 0; i < N; ++i){
      if(adj_matrix[node][i] == 1 && visited[i] == 0){
        //push that other element into stack
        stack_push(stack, i);
        //now mark it as visited
        visited[i] = 1;
      }
    }
    
  }
  
}


/*****************************************************************************

                          BFS USING QUEUE

****************************************************************************/

void bfs(int start, int N, int visited[N], int adj_matrix[N][N]){
  struct Queue* queue = new_queue();

  queue_push(queue, start);

  visited[start] = 1;

  while(queue->size > 0){
    int node = queue_top(queue);
    printf("visited: %d\n",node); 
    queue_pop(queue);
    for(int i = 0; i < N; ++i){
      if(adj_matrix[node][i] == 1 && visited[i] == 0){
        queue_push(queue, i);
        visited[i] = 1;
      }
    }
    
  }
  
}


int main(){
  int N; // no of nodes
  //take a user input 
  printf("Enter the number of nodes: ");
  scanf("%d", &N);

  int start; //from where u r starting
  //take a user input
  printf("Enter start: ");
  scanf("%d", &start);

  //initally mark a NxN matrix of 0
  int G[N][N];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      G[i][j] = 0;
    }
  }

  //mark initally visited as 0
  //one for bfs one for dfs
  int visited1[N];
  int visited2[N];

  for(int i = 0; i < 0; ++i){
    visited1[i] = 0;
    visited2[i] = 0;
  }
  
  //first ask for no of pairs 
  //pairs are nothing but edges
  int edges;
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  //now take a input of pairs who are connected to each other
  for(int i = 0; i < edges; ++i){
    int a , b;
    scanf("%d%d", &a,&b);
    G[a][b] = 1;
    G[b][a] = 1; //since we have undirected graph
  }

  dfs(start, N, visited1, G); 
  bfs(start, N, visited2, G); 


  return 0;
}
