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

void insert(struct node *p,int x,int index){    //also we can make insert() at last so no need to give index
    struct node *t;
    if(index < 0 || index > countNode(p)){
        return;
    }
    t = new node;
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;

    }
}

int main(){
    insert(first,10,0);
    insert(first,20,1);
    insert(first,30,2);
    insert(first,40,3);
    insert(first,50,4);
    display(first);
    insert(first,40,0);
    cout<<"\n";
    display(first);
    insert(first,80,3);
    cout<<"\n";
    display(first);
    return 0;
}