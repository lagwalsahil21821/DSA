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

void deletion(struct node* p ,int index){
    struct node *q = NULL;
    int x = -1;
    if(index < 1 || index >countNode(p)){
        return;
    }
    if(index == 1){
        x = p->data;
        first = p->next;
        delete p;
    }
    else{
        for (int i = 0; i < index-1 && (p); i++)
        {
            q = p;
            p = p->next;
        }
        if(p){
            x = p->data;
            q->next = p->next;
            delete p;
        }
    }
    
}

int main(){
    int arr[5] = {3,4,5,6,7};
    create(arr,5);
    deletion(first,1);  //3 should be deleted so new ll: 4,5,6,7
    deletion(first,3);  // now 6 gonna be deleted
    display(first);
    return 0;
}