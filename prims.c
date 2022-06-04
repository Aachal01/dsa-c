#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//returns index of minimum non negative valuse otherwise -1
//array[N] --> we will store its updated values
//replacement for priorty queue
int min_priority(int N, int array[N]){
  int index = 0;

  //to traverse the array
  for(int i = 0; i < N; ++i){
    //if(cost in array is >=0 and that cost is less than previous cost) ----> update the index
    if(array[i] >= 0 && array[i]<array[index]){
      index = i;
    }
  }

  //this means that all cost is now -1
  if(array[index] < 0){
      return -1;
    }
  return index;
}

void prims(int start_index, int no_of_nodes, int parent[no_of_nodes], int graph[no_of_nodes][no_of_nodes]){

  int priority[no_of_nodes]; //an empty array with garbage values
  
  for(int i = 0; i < no_of_nodes; ++i){
    //now we will assign everyone initially as infinity
    priority[i] = INT_MAX;
  }

  //we will set start index as 0 coz we are starting from there
  priority[start_index] = 0;
  
  //as said initially parent array has garbage value 
  //parent of start node is start node itself indicating that it has no parent
  parent[start_index] = start_index;

  //now we will start from here
  int node = start_index;

  while(node>=0){
    //we will first fix one node and then see where we can go from that node with minimum cost
    priority[node] = -1;

    //this for loop to traverse the graph/all nodes
    for(int i = 0; i < no_of_nodes; ++i){
      //if(cost is not zero and its cost is less than infinty) ---> we will rewrite infinity with it original cost(initially)....and later to choose minimum cost
      if(graph[node][i] > 0 && graph[node][i] < priority[i]){
        priority[i] = graph[node][i];
        //set the parent of current node to `node`
        parent[i] = node;
      }

      /*

        (1)   {∞, ∞, ∞, ∞, ∞, ∞}
        (2)   {∞, 0, ∞, ∞, ∞, ∞}
        (3)   {∞, 0, 10, 4, ∞, ∞}
        (4)   {∞, -1, ∞, ∞, ∞, ∞}

       -1 so that we will not go on the same node and choose next min priority node
      */
      node = min_priority(no_of_nodes, priority);
      
      }
  }
  
}


int main(){

  //Enter no of nodes
  int no_of_nodes;
  // printf("Enter the no of nodes: ");
  scanf("%d", &no_of_nodes);
  
  //Enter the start point
  int start_index;
  // printf("Enter the start: ");
  scanf("%d", &start_index);

  //lets make one adjacency matrix and initalize all the values with 0 
  int graph[no_of_nodes][no_of_nodes];
  for(int i = 0; i < no_of_nodes; ++i){
    for(int j = 0; j < no_of_nodes; ++j){
      graph[i][j] = 0;
    }
  }

  //Enter the no of edges
  int edges;
  // printf("Enter no of edges: ");
  scanf("%d", &edges);

  //we want connection between two nodes and their cost which we take input from user
  for(int i = 0; i < edges; ++i){
    int node1, node2, cost;
    // printf("Enter node1, node2, cost: ");
    scanf("%d %d %d", &node1, &node2, &cost);
    //now here we will replace 0 for that pair in adjacency list with the cost
    graph[node1][node2] = cost;
    //since we have undirected graph
    graph[node2][node1] = cost;
  }

  for(int i = 0; i < no_of_nodes; ++i){
    for(int j = 0; j < no_of_nodes; ++j){
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  

  //we will say that every node have parents for example 1 has parent 1 itself
  //currently this array is empty or filled with garbage values 
  //this will represent our entire tree 
  int parent[no_of_nodes];

  //this will make a tree 
  prims(start_index, no_of_nodes, parent, graph);

  //we need to return total cost and 
  //we will go to thier parent and from there we will travel and calculate total cost
  int total_cost = 0;
  for (int i = 0; i < no_of_nodes; ++i)
    {
      int p = parent[i];
      if(i != p) {
        total_cost += graph[i][p];
        printf("%d <--> %d, Cost: %d\n", i, p, graph[i][p]);
        }
    }

    printf("\nTotal Cost of Spanning Tree: %d\n\n", total_cost);
  
  return 0;
}