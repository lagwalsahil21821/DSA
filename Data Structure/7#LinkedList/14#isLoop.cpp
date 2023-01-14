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

int isLoop(struct node *p){
    struct node *q = p;
    do{
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    }while(p && q && p!=q);
    
    // if(p == q) return 1;
    // else return 0;
    return p == q ? 1 : 0;

}




int main(){
    struct node *t1,*t2;
    int arr[] = {1,2,3,4,5,6};
    create(arr,6);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout<<isLoop(first);
    

}