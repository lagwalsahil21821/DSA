#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
}*first = NULL;

void create(int arr[],int n){
    struct node* last,*t;
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
//concept of auxilary array
void reverse(struct node* p, int a[]){
    int i = 0;
    while(p!= NULL){
        a[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while(p!= NULL){
        p->data = a[i--];
        p = p->next;
    }
}

void display(struct node* p){
    while(p!= NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}

int main(){
    int a[] = {1,2,3,4,5,6};
    int b[6];
    create(a,6);
    reverse(first,b);
    cout<<"Reversing of LL: \n";
    display(first);
}