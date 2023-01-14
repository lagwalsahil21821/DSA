#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*first = NULL,*second = NULL,*third = NULL;
void create(int arr[],int n){
    struct node* last,*t;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data=arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}
void create2(int arr[],int n){
    struct node* last,*t;
    second = new node;
    second->data = arr[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data=arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(struct node*p){
    while(p != NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}
void concat(struct node* p ,struct node* q){
    third = p;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
}

void merge(struct node *p,struct node *q){
    struct node *last;
    if(p->data <= q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p != NULL && q != NULL){
        if(p->data <= q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;

            
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p!= NULL){
        last->next = p;
    }
    else{
        last->next = q;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int v[] = {2,4,5,6,7,9};
    create(arr,5);
    create2(v,6);
    cout<<"1st LL: ";
    display(first);
    cout<<"\n";
    cout<<"Second LL: ";
    display(second);
    cout<<"\nmerged LL: ";
    merge(first,second);
    display(third);
    // cout<<"\nConcatinated LL: ";
    // concat(first,second);
    // display(third);
}
