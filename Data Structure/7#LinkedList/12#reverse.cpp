#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*first = NULL;

void create(int arr[],int n){
    struct node *t,*last;
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
void display(struct node* p){
    while(p != NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}
int countNode(struct node *p){
    int count = 0,sum = 0;
    while(p!= NULL){
        count++;
        p = p->next;
    }
    return count;
}

void reverse1(struct node *p){
    int *A,i = 0;
    struct node* q = p;
    A = new int[countNode(p)];
    while(q!=NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q!=NULL){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct node* p){
    struct node *q = NULL,*r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    create(arr,6);
    //reverse1(first);
    reverse2(first);
    display(first);

}