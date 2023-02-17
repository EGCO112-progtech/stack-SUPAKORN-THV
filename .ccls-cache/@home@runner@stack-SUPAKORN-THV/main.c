#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

int main(int argc, char **argv){
  
  int i,flag,j,check=0;
  char temp;
  //NodePtr top=NULL;
  Stack s;
  s.top=NULL;
  s.size=0;
//Check d//
if(strcmp(argv[1],"d")==0){
check=1;
printf("Entering debug mode...\n");
  }
if(check==0){         
for(i=1; i<argc; i++)
    { flag=0;
      for(j=0; j<strlen(argv[i]); j++)
        {
          switch(argv[i][j]){
            case '{' :
            case '[' : push(&s,argv[i][j]); break;
            case '}': 
              temp=pop(&s, check);
              if(temp!='{')flag=1; break;
            case ']' : 
              temp=pop(&s, check);
              if(temp!='[')flag=1; break;
        }
          }
      if(s.size==0 && flag==0) {
        printf("argv %d: Correct\n",i);
      }
      else if(s.size>0 && flag==0) {
        printf("argv %d: Incorrect: too many open parenthesis\n",i);
        pop_all(&s, check);
      } else if(s.size==0 && temp=='e'){
        printf("argv %d: Incorrect: too many closed parenthesis\n",i);
      } else
        printf("argv %d: Incorrect: mismatch\n",i);
    }
  }
  
else{//Check found Debug-Mode
  printf("====== DEBUG MODE [%d] ======\n\n",check);
  for(i=2; i<argc; i++)
    { flag=0;
      for(j=0; j<strlen(argv[i]); j++)
        {
          switch(argv[i][j]){
            case '{' :
            case '[' : push(&s,argv[i][j]); printf("saved %c at i:%d j:%d\n",argv[i][j],i,j); break;
            case '}': 
              temp=pop(&s, check);
              if(temp!='{'){flag=1; printf("Error at } i:%d j:%d\n",i,j); }
            else{
              printf("Correct at }\n");
            } break;
            case ']' : 
              temp=pop(&s, check);
              if(temp!='['){flag=1; printf("Error at ] i:%d j:%d\n",i,j); }
            else{
              printf("Correct at ]\n");
            } break;
        }
          }
      if(s.size==0 && flag==0) {
        printf("argv %d: Correct with s.size = %d, flag = %d\n\n",i,s.size,flag);
      }
      else if(s.size>0 && flag==0) {
        printf("argv %d: Incorrect: too many open parenthesis with s.size = %d, flag = %d, temp = %c\n\n",i,s.size,flag,temp);
        pop_all(&s, check);
      } else if(s.size==0 && temp=='e'){
        printf("argv %d: Incorrect: too many closed parenthesis with s.size = %d, flag = %d, temp = %c\n\n",i,s.size,flag,temp);
      } else
        printf("argv %d: Incorrect: mismatch with s.size = %d, flag = %d, temp = %c\n\n",i,s.size,flag,temp);
    }
  }
  /*push(&top,5);
  printf("%d\n",pop(&top));
  push(&top,7);
  push(&top,8);
  printf("%d\n", pop(&top));
  printf("%d\n", pop(&top));*/
  /*for(i=1; i<argc-1; i++)
    {
       push(s,argv[i]);
    }
  if (strcmp(argv[i],"all")==0)
  {
    pop_all(s);
  }*/
  /*for(i=1; i<argc; i++)
    {
  printf("argv : %d\n", pop(&top)); 
    }*/
/*
  while(s->top)
    {
  //printf("argv : %d\n", pop(&top)); 
      printf("argv : %d\n", pop(s)); 
    }
  //printf("%d\n", pop(&top)); 
      printf("%d\n", pop(s));
*/
  /*pop(&top);
  push(&top,7);
  push(&top,8);
  pop(&top);*/
 
  

 /*
 Stack s;
 printf("Checking the parentheses in argv arguments\n");
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
        Use stack to help with the parentheses


     }


  }
*/


   return 0;
}
