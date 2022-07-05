#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[],int n){
    first = new node;
    struct node *t, *last;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        struct node* t;
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p){
    while(p != NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}

int main(){
    int arr[5] = {3,4,5,6,7};
    create(arr,5);
    display(first);
    return 0;
}