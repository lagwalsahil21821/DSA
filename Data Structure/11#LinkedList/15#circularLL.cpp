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
void display(struct node *p){
    do{
        cout<<p->data<<' ';
        p = p->next;
    }while(p != head);
}

int main(){
    int A[] = {1,2,3,4,5,6};
    create(A,6);
    display(head);
}