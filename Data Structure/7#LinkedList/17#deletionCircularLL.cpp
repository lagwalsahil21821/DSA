#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*head;
void create(int A[],int n){
    struct node *t,*last;
    head = new node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    
}

int length(struct node *p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p!=head);
    return len;
}

void display(struct node *p){
    do{
        cout<<p->data<<' ';
        p = p->next;
    }while(p != head);
}

int deletion(struct node *p,int index){
    if(index <= 0 || index > length(p)) return -1;
    struct node *q; int x = -1;
    if(index == 1){
        if(p->next == head) {       //if LL have only 1 element
            x = p->data;
            delete head;
            head = NULL;
        }
        else{
            while(p->next != head) p= p->next;
            p->next = head->next;
            x = head->data;
            delete head;
            head = p->next;
        }
        return x;
    }
    else{
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int main(){
    int A[] = {1,2,3,4,5,6};
    create(A,6);
    deletion(head,3);
    
    display(head);
}