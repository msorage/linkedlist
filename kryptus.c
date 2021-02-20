//OBS: Só foi me dado 1h para fazer esse programa, enquanto que no enunciado constava que haveria 1h30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct t_node {
  struct t_node* next;
  int data;
} node;

node * first(node * head){
  return head;

}

node * last(node * head){
  node * tmp = head;
  
  if(tmp == NULL) {
    return NULL;
  }
  
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  
  return tmp;
}

void list(node * head){
  node * tmp = head;
  while(tmp != NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
}

void clear(node* head) {
  // Tem memory leak, falta desalocar memória. Talvez usando recursão?
  head = NULL; 
}

void put(node* head, int data) {
  node new_node;
  new_node.data = data;
  new_node.next = NULL;

  node* l = last(head);
  
  if(l == NULL) {
    head = &new_node;
  }
  
  l->next = &new_node;
}

//void remove(node * head, int position){
//	int count = 0;
//  node * tmp = head;
//  
//  while(count != position){
//  	count++;
//  }  
//}

int main(int argc, char *argv[]) {
  char input[201];
  
  node n1;
  n1.data = 5;
  n1.next = NULL;
  
  node n2;
  n2.data = 8;
  n2.next = &n1;
  
  node n3;
  n3.data = 10;
  n3.next = &n2;
  
  node* head = &n3;
  

  while(1) {
	
    printf("prompt> ");
    if (fgets(input, 200, stdin) == NULL) {
      printf("An error ocurred.\n");
      break;
    }
    
    if (strncmp(input, "list\n", 5) == 0) {
      list(head);
    }
    
    if (strncmp(input, "first\n", 6) == 0) {
      node* f = first(head);
      printf("%d\n", f->data);
    }

    if (strncmp(input, "put", 3) == 0){
      printf("é isso\n");
    }
    
    if (strncmp(input, "last\n", 5) == 0) {
      node* l = last(head);
      printf("%d\n", l->data);
    }
    
//    if(starts_with(input, "put")) {
//      	char* data_str = input.split(" ")[1];
//      	int data = parse_int(data_str);
      
//      	put(head, data);
//      	list(head);
//    }
    
     if (strncmp(input, "exit\n", 5) == 0) {
       printf("Leaving. Good bye.\n");
       break;
     }
  }

  return EXIT_SUCCESS;
}


