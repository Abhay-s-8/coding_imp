#include <stdio.h>
#include <stdlib.h>


struct stack {
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack  * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{return 0;}
}

int isFull(struct stack  * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{return 0;}
}

void push(struct stack  * ptr,int value){
    if(isFull(ptr)){
       printf("Stack Overflow! Cannot push \n");
       
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int display(struct stack * ptr){
    int i =0 ;
    while(i<=ptr->top){
        int value = ptr->arr[i];
        printf("%d -> ",value);
        i++;
    }
    printf("NULL\n");
}

int peek(struct stack * ptr){
    int value = ptr->arr[ptr->top];
    printf("%d is the top most element \n",value);
}

int pop(struct stack* ptr){
if(isEmpty(ptr)){
    printf("Stack underflow! Cannot pop \n");
    
}
else{
    int value = ptr->arr[ptr->top];
    ptr->top--;
    printf("%d \n",value);
}
}

int main(){
int n;
    struct stack * s = (struct stack *)malloc(sizeof(struct stack ));
s -> size = 7;
s -> top = -1;
s->arr = (int *)malloc(s->size*sizeof(int));




push(s,37455);
push(s,4);
push(s,304);
push(s,346);

display(s);

peek(s);

pop(s);


display(s);

peek(s);

return 0;
}