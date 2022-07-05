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

int isSorted(struct node *p){
    int x = INT_MIN;
    while(p!=NULL){
        if(p->data < x) return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}


int main(){
    int arr[] = {1,2,3,4,5,6};
    create(arr,6);
    if(isSorted(first)){
        cout<<"Sorted\n";
    }
    else cout<<"NOt Sorted\n";
    display(first);

}