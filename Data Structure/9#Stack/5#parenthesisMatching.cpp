#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node* next;
}*top = NULL;

void push(char x){
    struct node *t;
    t = new node;
    if(t == NULL) cout<<"Stack is full\n";
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    char x  = -1;
    if(top == NULL) cout<<"Stack have no element to delete\n";
    else{
        struct node* t;
        t = top;
        top = top->next;
        x = t->data;
        delete t;

    }
    return x;
}

void display(){
    struct node *p;
    p = top;
    while(p){
        cout<<p->data<<' ';
        p = p->next;
    }
    cout<<"\n";
}

int isBalanced(string exp){
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(') push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL) return 0;
            pop();
        }
    }
    if(top == NULL) return 1;
    else return 0;
    
}
int main(){
    
}