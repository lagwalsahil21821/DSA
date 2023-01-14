#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
};

class stk{
private:
    node* top;
public:
    stk(){top = NULL;}
    void push(int x);
    int pop();
    void display();
};
void stk::push(int x){
    node *t = new node;
    if(t== NULL) cout<<"Stack is full\n";
    else{
        t->data = x;
        t->next = top;
        top= t;
    }

}

int stk::pop(){
    int x = -1;
    if(top == NULL) cout<<"Stack is empty\n";
    else{
        x = top->data;
        node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void stk:: display(){
    struct node* t;
    t = top;
    while(t){
        cout<<t->data<<' ';
        t = t->next;
    }
    cout<<"\n";
}

int main(){
    stk s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.pop();
    s.display();
}