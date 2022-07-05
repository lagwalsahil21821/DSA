// linked list already list
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
}*first = NULL;

void create(int arr[],int n){
    struct node* last,*t;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void slidingReverse(struct node* p){
    struct node* q= NULL,*r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void display(struct node* p){
    while(p!= NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}

int main(){
    int a[] = {1,2,2,5,5,5};
    create(a,6);
    cout<<"reversing of LL: \n";
    slidingReverse(first);
    display(first);
}