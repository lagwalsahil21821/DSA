#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*first = NULL;

void create(int value){
    struct node *last,*t;
    if(first == NULL){
        first = new node;
        first->data = value;
        first->next = NULL;
        last->next = first;
        last = first;
    }
    else{
        t = new node;
        t->data = value;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(struct node *p){
    while(p!= NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}

int main(){
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    display(first);
}