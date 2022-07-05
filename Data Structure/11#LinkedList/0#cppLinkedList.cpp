#include<bits/stdc++.h>
using namespace std;
class node{
public: 
    int data;
    node* next;
};
class LinkedList{
private:
    node * first;
public:
    LinkedList(){first = NULL;}
    LinkedList(int A[],int n);
    ~LinkedList();
    void display();
    void insert(int index,int x);
    int deletion(int index);
    int length();
};
LinkedList::LinkedList(int A[],int n){
    first = new node;
    struct node *last,*t;
    first->data = A[0];
    first->next = NULL;
    last =first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}
LinkedList::~LinkedList(){
    node *p = first;
    while(first){
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList:: display(){
    struct node*p = first;
    while(p){
        cout<<p->data<<' ';
        p = p->next;
    }
}
int LinkedList::length(){
    node* p = first;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}
void LinkedList:: insert(int index,int x){
    node *p = first,*t;
    if(index <0 || index > length()) return;

    t = new node;
    t->data = x;
    t->next = NULL;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{

        for (int i = 0; i < index; i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}
int LinkedList:: deletion(int index){
    node *p = first,*q = NULL;
    int x = -1;
    if(index < 1 || index > length()) return -1;
    if(index == 1) {
        first = p->next;
        x = p->data;
        delete p;
    }else{
        for (int i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        
    }
    return x;
}

int main(){
    int A[] = {1,2,3,4,5,6};
    LinkedList l(A,6);
    cout<<l.deletion(3)<<endl;
    l.display();

}