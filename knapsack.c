#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Make a templete 

/*
what are the thing i want to link with the data
- profit
- weight
- id
- profit per weight
*/

struct Object{
  int id;
  int weight;
  int profit;
  float profit_per_weight;
};


int main(){
  //I will make an array coz there are multiple objects and we need to assign the data to each
  
  int capacity;
  printf("Enter the capacity: ");
  scanf("%d",&capacity);

  int no_of_items;
  printf("Enter the number of items that are available: ");
  scanf("%d", &no_of_items);

  struct Object item[no_of_items];


  //this for loop to ask the details of each item to user
  for(int i = 0; i < no_of_items; ++i){
    //id will be automatically assigned but it will start from 0
    item[i].id = i+1;
    
    //we will ask user for its weight and profit
    int w;
    printf("Enter the weight: ");
    scanf("%d",&w);
    item[i].weight = w;
    
    int p;
    printf("Enter profit: ");
    scanf("%d", &p);
    item[i].profit = p;

    //we can calculate with profit per weight
    item[i].profit_per_weight = (float)p/w;
  }

  //this for loop to sort the items acc profit per weight
  //we will sort in descending order
  //here we will use bubble sort
  for(int i = 0; i < no_of_items; ++i){
    for(int j = 1; j < no_of_items-i; ++j){
      if(item[j-1].profit_per_weight < item[j].profit_per_weight){
        //swap
        struct Object dummy = item[j];
        item[j] = item[j-1];
        item[j-1] = dummy;
      }
    }
  }

  float total_profit = 0;
  //this for loop for calclating total profit
  printf("\nselected items:\n");
  for(int i = 0; capacity > 0 && i < no_of_items; ++i){
    //lets take one container of weight 
    //another container of profit

    int current_weight = 0;
    float current_profit = 0;
    if(capacity > item[i].weight){
      //weight ke container me vo weight daal do
      current_weight = item[i].weight;
      //profit ke container me profit daal do
      current_profit = item[i].profit;
      //now update capacity
      capacity -= item[i].weight; 
    }
    else{
      current_weight = capacity;
      current_profit = item[i].profit_per_weight*current_weight;
      capacity = 0;
    }

    total_profit += current_profit;
    printf("Item id: %d, ", item[i].id);
    printf("Item weight: %d/%d, ", current_weight, item[i].weight);
    printf("Item profit: %.2f\n", current_profit);
  }

  printf("Total Profit: %.2f\n", total_profit);

  
  return 0;
}