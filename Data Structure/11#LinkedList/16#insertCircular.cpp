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
void insert(struct node *p ,int index,int x){
    struct node *t;
    if(index < 0 || index > length(p)) return;
    t = new node;
    t->data = x;
    if(index == 0){
       
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while(p->next != head) p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next= p->next;
        p->next = t;
        
    }
}
void display(struct node *p){
    do{
        cout<<p->data<<' ';
        p = p->next;
    }while(p != head);
}

int main(){
    int A[] = {1,2,3,4,5,6};
    create(A,6);
    insert(head,0,10);
    display(head);
}