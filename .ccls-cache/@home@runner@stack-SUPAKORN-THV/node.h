//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa
//

#ifndef linkedlist_h //ถ้า linklist นี้ยังไม่ define ให้ define ใหม่
#define linkedlist_h
struct node
{
    char data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node* NodePtr;

/*void push(NodePtr* top, int x);
int pop(NodePtr* top);

  void push(NodePtr* top, int x){
  Node *new_node = (NodePtr)malloc(sizeof(Node));
  if(new_node){
    new_node->data=x;
    new_node->nextPtr=*top;
    *top=new_node;
  }
}
int pop(NodePtr* top){
  if(*top){
  NodePtr t = *top;
  int value;
  t=*top; //(*top)->data
  value=t->data; //(*top)->nextPtr
  *top=t->nextPtr;
  free(t);
  return value;
    } else return 0;
}*/

#endif
