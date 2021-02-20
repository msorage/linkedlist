//OBS: Só foi me dado 1h para fazer esse programa, enquanto que no enunciado constava que haveria 1h30
//OBS2: Todas as contagens da lista começam em 0

//faltando: clear

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
  printf("\n");
}

void clear(node* head) {
  // Tem memory leak, falta desalocar memória. Talvez usando recursão?
  head = NULL; 
}

void put(node** head, int data) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  
  node* l = last(*head);
  
  if(l == NULL) {
    *head = new_node;
    return;
  }
  l->next = new_node;
}

int get(node * head, int position){
  int count = 0;
  node * tmp = head;
  // tratativas de tamanho da fila e posição além do limite dela poderiam ser feitas
  
  while(tmp != NULL && count != position){
    tmp = tmp->next;
    count++;
  }    
  return tmp->data;
  

}

void delete(node ** head, int position){
  int count = 0;
  node * tmp = *head;
  node * tmp_ant;

  //tratativa para lista vazia e lista com um elemento a serem implementadas
  if(tmp == NULL){
    printf("Empty List");
    return;
  }

  while(tmp->next != NULL && count != position){
    tmp_ant = tmp;
    tmp = tmp->next;
  	count++;
  }

tmp_ant->next = tmp->next;
free(tmp);

}

int main(int argc, char *argv[]) {
  char input[201];
  
  node* head = NULL;
  

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

      if(f != NULL){
        printf("%d", f->data);
      } 
      printf("\n");
      
    }

    if (strncmp(input, "put", 3) == 0){
      const char* delim = " ";
      char* token = strtok(input,delim);
      token = strtok(NULL, delim);
      int data; 
      data = atoi(token);
      put(&head,data);
      list(head);
      
    }

    if (strncmp(input, "get", 3) == 0){
      const char* delim = " ";
      char* token = strtok(input,delim);
      token = strtok(NULL, delim);
      int position; 
      position = atoi(token);
      
      printf("%d\n", get(head,position));
    }

    if (strncmp(input, "delete", 6) == 0){
      const char* delim = " ";
      char* token = strtok(input,delim);
      token = strtok(NULL, delim);
      int position; 
      position = atoi(token);
      
      delete(&head,position);
      list(head);
    }
    
    if (strncmp(input, "last\n", 5) == 0) {
      node* l = last(head);
      if(l != NULL){
        printf("%d", l->data);
      } 
      printf("\n");
    }
    
     if (strncmp(input, "exit\n", 5) == 0) {
       printf("Leaving. Good bye.\n");
       break;
     }
  }

  return EXIT_SUCCESS;
}


