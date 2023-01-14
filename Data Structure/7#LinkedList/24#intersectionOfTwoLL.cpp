#include<bits/stdc++.h>
using namespace std;
class node{
public: 
    int data;
    node* next;
};
node *first = NULL,*second = NULL;
void create1(int A[],int n){
    node *last,*t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}
void create2(int A[],int n,node *p){
    node *last,*t;
    second = new node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = p;
}

void display(node *p){
    while(p){
        cout<<p->data<<' ';
        p = p->next;
    }
}

void intersection(node *p,node *q){
    stack<node*>stk1;
    // store address of each node of linked list 1 in stack1
    while(p){
        stk1.push(p);
        p = p->next;
    }
    //store address of each node of linked list 2 in stack 2
    stack<node*>stk2;
    while(q){
        stk2.push(q);
        q = q->next;
    }

    node *r;
    while(stk1.top() == stk2.top()){
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout<<"INtersecting NOde: "<<r->data<<"\n";
}

int main(){
    int X[] = {1,2,3,4,5,6,7,8};
    int Y[] = {10,11,12,14};
    create1(X,8);
    //create second linked list
    node *temp = first;
    int i = 4;
    while(i>0){
        temp = temp->next;
        i--;
    }
    create2(Y,4,temp);
    intersection(first,second);
    display(first);
    cout<<"\n";
    display(second);
    
}