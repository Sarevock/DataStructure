#include<stdio.h>

//Lab 3 Stacks API LIFO

#define MAX 10

struct stack{
    int array[MAX];
    int top;
};

void init_stack(struct stack *s){
    s->top = -1;
}

void push(struct stack *s, int item){
    if(s->top == MAX -1){
        printf("Stack is full .Couldn't push '%d' onto stack\n", item);
        return;    
    }
    s->top++;
    s->array[s->top] = item;
}

int *pop(struct stack *s){
    int *data;
    if(s->top == -1){
        printf("Stack is Empty\n");
        return NULL;
    }

    data = &s->array[s->top];
    s->top--;
    return data;
}

int main(void){

    struct stack s;

    init_stack(&s);

    //fill the stack
    push(&s, 11);
    push(&s, 24);
    push(&s, 56);
    push(&s, 177);
    push(&s, 199);
    push(&s, 234);
    push(&s, 1);
    push(&s, 98);
    push(&s, 16);
    push(&s, 17);
    //full entry
    push(&s, 189);

    int *i = NULL ;

    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }
    
    //Empty
    i = pop (&s);
    if(i) { printf (" Item popped : %d\n", *i); }

    return 0;

}