//OBS: Só foi me dado 1h para fazer esse programa, enquanto que no enunciado constava que haveria 1h30
//OBS2: Todas as contagens da lista começam em 0


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

int size(node * head){
  int count = 0;
  node * tmp = head;
  if(tmp == NULL) {
    printf("Lista vazia\n");
    return 0;
  }

  while(tmp != NULL){
    tmp = tmp->next;
    count++;
  }  
  return count; 

}

void list(node * head){
  node * tmp = head;
  while(tmp != NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void clear(node ** head) {
  
  node * tmp = *head;
  node * next;

  //percorrer a lista apagando os elementos
  while(tmp != NULL){
    next = tmp->next;
    free(tmp);
    tmp = next;
  } 

  //apontar head para null
  *head = NULL;
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

  //tratativa lista vazia
  if(tmp == NULL){
    printf("Empty List");
    return;
  }

  //primeiro elemento a ser removido
  if(position == 0){
    *head = tmp->next;
    free(tmp);
    return;
  }

  //encontrar elemento a ser removido
  while(tmp->next != NULL && count != position){
    tmp_ant = tmp;
    tmp = tmp->next;
  	count++;
  }

//remover elemento 
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

    if (strncmp(input, "clear\n", 6) == 0) {
      clear(&head);
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
      //tratativa de posições inválidas
      if(position >= size(head)){
        printf("Invalid Position\n");
      } else{
          printf("%d\n", get(head,position));
      }
      
      
    }

    if (strncmp(input, "remove", 6) == 0){
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


