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
int countNode(struct node *p){
    int count = 0;
    while(p!= NULL){
        count++;
        p = p->next;
    }
    return count;
}

void sortedInsert(struct node* p,int x){
    struct node *t ,*q = NULL;
    t = new node;
    t->data = x;
    t->next = NULL;
    if(first == NULL) first = t;
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p == first){ //only one node then q points to NULL
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
int main(){
    //int arr[5] = {10,20,30,40,50};
   // create(arr,5);
    sortedInsert(first,25);
    sortedInsert(first,45);
    sortedInsert(first,5);
    display(first);

    return 0;
}