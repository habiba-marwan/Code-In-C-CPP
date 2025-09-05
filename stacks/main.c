//
//  main.c
//  stacks
//
//  Created by Habiba Elkamary on 29/02/2024.
//

#include <stdio.h>
#include <stdlib.h>
#define size 100
typedef struct {
    int items[size];
    int top;
} stack;


stack* intialize(void){
    stack*s=malloc(sizeof(stack));
    s->top=0;
    return s;
}


void push(stack*s,int value)
{
    s->items[s->top]=value;
    s->top++;
}

int pop(stack*s){
    int value=s->items[(s->top)-1];
    s->top--;
    return value;
}

int peek(stack*s){
    int  value =s->items[s->top-1];
    return value;
}

int isfull(stack*s)
{ if((s->top)==size) return 1;
else return 0;
}
int isEmpty(stack*s){
    if ((s->top)==0) {
        return 1;
    }
        else  return 0;
    
}

void display(stack*s){
    stack *temp=malloc(sizeof(stack));
    while (!isEmpty(s)) {
        int x=pop(s);
        printf("%d\n",x);
        push(temp,x);
    }
    while (!isEmpty(temp)) {
        push(s, pop(temp));
    }
}

void displaystring(stack*s){
    stack *temp=malloc(sizeof(stack));
    while (!isEmpty(s)) {
        int x=pop(s);
        printf("%c\n",x);
        push(temp,x);
    }
    while (!isEmpty(temp)) {
        push(s, pop(temp));
    }
}

int count(stack*s){
    return s->top;
}


void deleteNonprime(stack*s){
    stack*temp=malloc(sizeof(stack));
        while (!isEmpty(s)) {
            int flag=0;

      int x=pop(s);
        for (int i=2; i<x; i++) {
            if (x%i==0)
                flag=1;
        }
        if (flag);
            else push(temp, x);
         
           
    }
    while (!isEmpty(temp)) {
        push(s, pop(temp));
    }
}
stack*reverse(stack*s){
    stack*reversed=malloc(sizeof(stack));
    stack*temp=malloc(sizeof(stack));
    while (!isEmpty(s)) {
     int   x=pop(s);
        push(reversed, x);
        push(temp, x);
    }
    while (!isEmpty(temp)) {
        push(s, pop(temp));
    }
    return reversed;
}
int sorted(stack*s){
    stack*temp=malloc(sizeof(stack));
    int x=pop(s);
    int flag=1;
    while (!isEmpty(s)) {
        int y=pop(s);
        if (y<x) {
            flag=0;
            push(temp, x);
            push(temp, y);
            break;
        }
        else {
            push(temp, x);
            x=y;
        }
    }
    if (flag) {
        push(temp, x);
    }
    while (!isEmpty(temp)) {
       push(s, pop(temp));
    }
  
    if (flag)
        return 1;
        else return 0;
}
stack* sort(stack*s)
{
    stack*temp=malloc(sizeof(stack));
    int flag=1;
    while (flag) {
        int x=pop(s);
        while (!isEmpty(s)) {
           int y=pop(s);
            if (y<x) {
                push(temp,y);
            }
            else {
                push(temp,x);
               x=y;
            }
        }
        push(temp, x);
     
        while (!isEmpty(temp)) {
           push(s, pop(temp));
        }
        
        if (sorted(s)) {
            flag=0;
        }
    }
    return temp;
}
stack* merge(stack*s,stack*s1){
    stack*p=malloc(sizeof(stack));
    stack*temp=malloc(sizeof(stack));
    while (!isEmpty(s)) {
        int x=pop(s);
        push(p, x);
        push(temp, x);
    }
    while (!isEmpty(temp)) {
        push(s, pop(temp));
    }
    
    while (!isEmpty(s1)) {
        int y=pop(s1);
        push(p, y);
        push(temp, y);
    }
    while (!isEmpty(temp)) {
        push(s1, pop(temp));
    }
    
    sort(p);
    return p;
}
    
    int main(int argc, const char * argv[]) {
        stack *s=intialize();
        push(s, 'h');
        push(s,'a');
        push(s, 'b');
        push(s, 'i');
        push(s, 'b');
        push(s, 'a');
        stack *s1=intialize();
        push(s1,7);
        push(s1,80);
       push(s1,17);
        deleteNonprime(s1);
        display(merge(s, s1));
        printf("\n");
       displaystring(reverse(s));
     printf("\n%d\n",sorted(s));
        free(s);
        free(s1);
        
    return 0;
}
