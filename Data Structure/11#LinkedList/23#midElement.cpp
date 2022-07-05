#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct node *t, *last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
}
void midElement1(struct node *p){
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    p = first;
    for (int i = 1; i < ceil((count+1)/2.0); i++)
    {
        p = p->next;
    }
    cout<<"midElement1: "<<p->data<<"\n";
    
    
}

void midElement2(struct node *p)
{
    struct node *q;
    q = first;
    while (q  && q->next)
    {
        q = q->next->next;
        p = p->next;
    }
    cout <<"midElement2: "<< p->data<<"\n";
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 9);
    midElement1(first);
    midElement2(first);
    display(first);
}