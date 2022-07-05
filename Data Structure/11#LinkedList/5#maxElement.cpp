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
int maxElement(struct node* p){
    int maxi = INT_MIN;
    while(p!= 0){
        if(p->data > maxi)maxi = p->data;
        p = p->next;
    }
    return maxi;
}

int Rmax(struct node *p){
    int x = 0;
    if(p == 0) return INT_MIN;
    x = Rmax(p->next);
    if(x > p->data) return x;
    else return p->data;

}




int main(){
    int arr[] = {1,92,13,44,95,6};
    create(arr,6);
    display(first);
    cout<<"\nMax. Element: "<<maxElement(first);
    cout<<"\nMax. Element through recursive approach: "<<Rmax(first);

}