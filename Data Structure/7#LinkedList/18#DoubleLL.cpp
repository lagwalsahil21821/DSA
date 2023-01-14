#include<bits/stdc++.h>
using namespace std;
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;

void create(int A[],int n){
    struct node *t, *last;
    first = new node;
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}
void display(struct node* p){
    struct node *q;
    while(p!=NULL){
        cout<<p->data<<' ';
        q = p;
        p = p->next;
    }
    cout<<"\nReverse Access: ";
    while(q!= NULL){
        cout<<q->data<<' ';
        q = q->prev;
    }

}
int main(){
    int A[] = {2,3,4,5,6,7};
    create(A,6);
    display(first);
}