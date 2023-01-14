#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*front = NULL,*rear = NULL;

void enqueue(struct node *q,int x){
    q = new node;
    if(q == NULL) cout<<"Queue is full\n";
    else{
        q->data = x;
        q->next = NULL;
        if(front == NULL) front = rear = q; // inserting first node
        else{
            rear->next = q;
            rear = q;
        }
    }
}

int dequeue(){
    int x = -1;
    if(front == NULL) cout<<"Queue is Empty\n";
    else{
        struct node *p;
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display(){
    struct node *q = front;
    while(q!=NULL){
        cout<<q->data<<' ';
        q = q->next;
    }
}

int main(){
    enqueue(rear,10);
    enqueue(rear,20);
    enqueue(rear,30);
    enqueue(rear,40);
    dequeue();

    display();
}