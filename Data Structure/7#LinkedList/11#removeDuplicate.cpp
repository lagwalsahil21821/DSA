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

void removeDuplicate(struct node *p){
    struct node*q = p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,4,5,5,6};
    create(arr,8);
    removeDuplicate(first);
    display(first);

}