#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

//Template
//what do we want to bind with node - data, left child, right child
struct Node{
char data;
struct Node* left_child;
struct Node* right_child;
};
  
//initialization
struct Node* new_node(char data1){
  //assigning memory 
  struct Node* my_node = (struct Node*) malloc(sizeof(struct Node));
  my_node->data = data1;
  my_node->left_child = NULL;
  my_node->right_child = NULL;
};

//expression tree
//parameter = postfix expression and usiki size
struct Node* expression_tree(int N, char expression[N]){
  struct Node* stack[MAX_STACK_SIZE];
  int stack_size = 0;

  //traverse the expression array
  for(int i = 0; i < N; ++i){
    //accepted the integer value
    if('0' <= expression[i] && expression[i] <= '9'){
      stack[stack_size++] = new_node(expression[i]);
    }
    else{
      //accept the symbol
      //1st popped value will be right 
      struct Node* parent = new_node(expression[i]);
      parent->right_child = stack[--stack_size];
      parent->left_child = stack[--stack_size];
      stack[stack_size++] = parent;
    }
  }

  //in the end only one element will be left and that is root node
  return stack[0];
  };

void print(struct Node* my_node){
  printf("%c",my_node->data);
}

//recursive preorder
//root left right
void preorder(struct Node* parent){
  //base condition
  if(parent == NULL) return;
  print(parent);
  preorder(parent->left_child);
  preorder(parent->right_child);  
}


//recursive preorder
void inorder(struct Node* parent){
  if(parent == NULL) return;
  inorder(parent->left_child);
  print(parent);
  inorder(parent->right_child);
}


//recursive postorder
void postorder(struct Node* parent){
  if(parent == NULL) return;
  postorder(parent->left_child);
  postorder(parent->right_child);
  print(parent);
}

int main(){

  //ask for a length
  int length_of_expression;
  printf("Enter the length of expression tree: ");
  scanf("%d", &length_of_expression);

  //ask for postfix expression 
  char expression[length_of_expression];
  printf("Enter the postfix expression: ");
  scanf("%s", expression);

  //make a expression tree by calling expression tree function
  struct Node* root = expression_tree(length_of_expression, expression);

  //preorder traversal
  printf("Preorder traversal: ");
  preorder(root);

  //postorder traversal
  printf("\npostorder traversal: ");
  postorder(root);

  //inorder traversal
  printf("\ninorder traversal: ");
  inorder(root);

  printf("\n");
}