#include<stdio.h>
#define MAX_SIZE 100
#define KEY 7

typedef struct{
  char name[10];
  long long phone;  
}Contact;


int ask_choice(){
  int choice;
  printf("Select operations\n");
  printf(" 1. Add contact\n");
  printf(" 2. Delete contact\n");
  printf(" 3. Display phonebook\n");
  printf(" 4. Exit\n");
  printf("Enter choice: \n");
  scanf("%d",&choice);
  return choice;
}

Contact input_contact(){
  Contact new_contact;
  printf("Enter Name: ");
  scanf("%s",new_contact.name);
  printf("Enter contact number: ");
  scanf("%lld",&new_contact.phone);
  return new_contact;
}

void print_contact(Contact display){
  printf("%s\t%lld\n", display.name, display.phone);
}

int hash(long long phone_number){
  return phone_number%KEY;
}

void addContact(Contact HASHTABLE[KEY][MAX_SIZE], int size[KEY]){
  Contact new_contact = input_contact();
  int key = hash(new_contact.phone);
  HASHTABLE[key][size[key]++] = new_contact;  
}

void delContact(Contact HASHTABLE[KEY][MAX_SIZE], int size[KEY]){
  printf("Enter the phone number u want to delete: ");
  long long entered_phone;
  scanf("%lld", &entered_phone);

  int key = hash(entered_phone);
  int target_index = -1;
  for(int i = 0; i < size[key]; ++i){
    if(HASHTABLE[key][i].phone  == entered_phone){
      target_index = i;
      break;
    }
  }
  //deletion 
  if(target_index == -1) return;

  //deletion process
  size[key]--;
  HASHTABLE[key][target_index] = HASHTABLE[key][size[KEY]]; 
}

void displayContact(Contact HASHTABLE[KEY][MAX_SIZE], int size[KEY]){
  for(int key = 0; key < KEY; ++key){
    for(int i = 0; i < size[key]; ++i){
      print_contact(HASHTABLE[key][i]);
    }
  }
}

int main(){
  Contact HASHTABLE[KEY][MAX_SIZE];
  int size[KEY] = {0}; 

  int choice;
  while(choice != 4){
    choice = ask_choice();
    switch(choice){
      case 1:
        addContact(HASHTABLE, size);
        break;
      case 2:
        delContact(HASHTABLE, size);
        break;
      case 3:
        displayContact(HASHTABLE, size);
        break;
      case 4:
        break;    
    }
  }
  return 0;
}