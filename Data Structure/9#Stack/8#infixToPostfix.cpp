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

int pre(char x){
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    return 0;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}

char* InToPost(char *infix){
    int i = 0,j = 0;
    char* postfix;
    int len = strlen(infix);
    postfix = new char[len+2];
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top != NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = InToPost(infix);
    cout<<postfix<<"\n";
}