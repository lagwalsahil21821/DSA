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
    while(p!= NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
}
struct node* linearSearch(struct node* p , int key){
    while(p!= NULL){
        if(key == p->data) return p;
        else{
            p= p->next;
        }
    }
    return NULL;
}
struct node* ImprovelinearSearch(struct node* p , int key){
    struct node *q = NULL;
    while(p!= NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        } 
        q = p;
        p = p->next;
    }
    return NULL;
}
struct node * RSearch(struct node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}


int main(){
    int arr[] = {1,92,13,44,95,6};
    create(arr,6);
    display(first);
    cout<<"\nnode found at: ";
    cout<<ImprovelinearSearch(first,44);
    cout<<"\nLinked list after linear search: ";
    display(first);
    

}