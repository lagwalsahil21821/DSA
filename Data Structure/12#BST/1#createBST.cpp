#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* lchild,*rchild;
}*root = NULL;

void insert(int key){
    struct node *t = root;
    struct node *r,*p;

    if(root == NULL){
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t!=NULL){
        r = t;
        if(key < t->data) t = t->lchild;
        else if(key > t->data) t= t->rchild;
        else return;
    }

    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) r->lchild = p;
    else r->rchild = p;

}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<' ';
        inorder(p->rchild);
    }
}

struct node* BS(int key){
    struct node *p = root;
    while(p!=NULL){
        if(key == p->data) return p;
        else if(key < p->data) p = p->lchild;
        else p = p->rchild;
    }
    return NULL;
}


int main(){
    struct node *temp;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inorder(root);  //gives sorted order of elements
    cout<<"\n";

    temp = BS(20);
    if(temp!=NULL) cout<<"Element "<<temp->data<<" is found\n";
    else cout<<"Element not found\n";
    return 0;
}