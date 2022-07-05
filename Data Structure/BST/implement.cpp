#include<bits/stdc++.h>
using namespace std;
class node{
public: 
    int data;
    node* lchild, *rchild;

}*root = NULL;

void insert(int key){
    node *t = root;
    node *r,*p;
    if(root == NULL){
        p = (node*)malloc(sizeof(node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t!= NULL){
        r = t;
        if(key< t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else 
            return;
    }
    p = (node *) malloc(sizeof(node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) r->lchild = p;
    else r->rchild = p;
}

void inorder(node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<' ';
        inorder(p->rchild);
    }
}

node* search(int key){
    node* t = root;
    while(t!= NULL){
        if(key == t->data) return t;
        else if(key < t->data) t= t->lchild;
        else t = t->rchild;

    }
    return NULL;
}
int main(){
    node* temp;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inorder(root);
    cout<<" \n";
    temp = search(2);
    if(temp != NULL)cout<<"Element is found "<<temp->data<<"\n";
    else cout<<"Element not found\n";

    return 0;
   
}