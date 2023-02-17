
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value){

  Node *new_node = (NodePtr)malloc(sizeof(Node));
  if(new_node){
    new_node->data=value;
    new_node->nextPtr=s->top;
    s->top=new_node;
    s->size++;
  }
}

char pop(StackPtr s, int check){
  if(s->top){
  NodePtr t = s->top;
  char value;
  t=s->top; //(*top)->data
  value=t->data; //(*top)->nextPtr
  s->size--;
  s->top=t->nextPtr;
  free(t);
  return value;
    }
  if(check == 1) printf("Empty Stack\n");
  return 'e';
}
void pop_all(StackPtr s, int check){
  while(s->size>0) //s->top
    {
      if(check == 1) printf("All : %c\n",pop(s, check));
      else pop(s, 0);
    }
  if(check == 1) printf("pop_all complete with s->size = %d\n",s->size);
}
#endif
