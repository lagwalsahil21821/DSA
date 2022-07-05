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
void countAdd(struct node *p){
    int count = 0,sum = 0;
    while(p!= NULL){
        count++;
        sum += p->data;
        p = p->next;
    }
    cout<<"no. of nodes: "<<count<<"\n";
    cout<<"sum of elements: "<<sum<<"\n";
}


int main(){
    int arr[] = {1,2,3,4,5,6};
    create(arr,6);
    countAdd(first);
    display(first);

}