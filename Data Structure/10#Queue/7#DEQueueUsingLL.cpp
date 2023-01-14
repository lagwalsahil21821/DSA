#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
};

class Deque{
private:
    node* front;
    node* rear;
public:
    Deque();
    ~Deque();
    void pushfront(int x);
    void pushback(int x);
    int popfront();
    int popback();
    void display();
};

Deque::Deque(){
    front = nullptr;
    rear = nullptr;
}
Deque::~Deque(){
    node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
void Deque::pushback(int x){
    node* t = new node;
    if(t == NULL) cout<<"Overflow\n";
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

void Deque::pushfront(int x){
    node *t = new node;
    if(t == NULL) cout<<"overflow\n";
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear =t;
        }
        else{
            t->next = front;
            front = t;
        }
    }
}

int Deque::popfront(){
    int x = -1;
    if(front == NULL) cout<<"Underflow\n";
    else{
        node* t;
        t = front;
        front = front->next;
        x = t->data;
        delete t;
    }
    return x;
}

int Deque::popback(){
    int x= -1;
    if(front == NULL) cout<<"Underflow\n";
    else{
        node* t = front;
        while(t->next->next != NULL){       //traverse to 2nd last node
            t = t->next;
        }
        x = rear->data;
        t->next = NULL;
        delete rear;
        rear = t;
    }
    return x;
}

void Deque::display(){
    node *t = front;
    while(t){
        cout<<t->data<<' ';
        t = t->next;
    }
    cout<<"\n";
}

int main(){
    Deque d;
    d.pushback(10);
    d.pushback(20);
    d.pushfront(30);
    d.pushfront(40);
    d.display();
    d.popfront();
    d.pushfront(60);
    d.popback();
    d.display();
}
