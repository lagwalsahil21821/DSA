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
int length(struct node *p){
    int len = 0;
    while(p){
        len++;
        p= p->next;
    }
    return len;
}

void insert(struct node *p,int index,int x){
    if(index<0 || index > length(p)) return;
    struct node *t;
    t = new node;
    t->data = x;
    if(index == 0){
        if(p == NULL){
            t->prev = t->next = NULL;
            p = t;
        }
        else{
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else{
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->prev = p; 
        t->next = p->next;
        if(p->next)t->next->prev = t;  //next node's prevoius address set to t
                                        // also if condition not apply then insertion not valid on last index
        p->next = t;
    }
}

int deletion(struct node *p,int index){
    if(index <= 0 || index > length(p)) return -1;
    struct node *q; int x = -1;
    if(index == 1){
        x = first->data;
        first = first->next;
        if(first)first->prev = NULL;    //if only 1 element present then this condition not executed
        delete p;
        return x;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        if(p->next)p->next->prev = q;
        delete p;

        return x;
    }
}

int main(){
    int A[] = {2};
    create(A,1);
    cout<<deletion(first,1)<<"\n";
    display(first);
}